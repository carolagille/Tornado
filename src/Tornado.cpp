#include "Tornado.h"
#include "ParticleSystem.h"
#include "TornadoCurve.h"
#include <random>
#include <vector>
#include<iostream>
Tornado::Tornado(int _changeRate, ngl::Vec3 _controlPoint[], float _maxHeight) :
    m_curve(_changeRate, _controlPoint,_maxHeight)
{
    m_frame=0;
    m_particleSystemTreshold=8000;
    m_maxProductionRate=1;
    m_particleSystemCount=0;
    m_radiusRange[0]=4.0;
    m_radiusRange[1]=8.0;
    m_maxHeight=_maxHeight;
    //m_particleSystemList = std::vector<ParticleSystem*> ();
    std::cout<< "Tornado created\n";
    createParticleSystem();

}

Tornado::~Tornado()
{
    std::cout<<"Destructor Tornado called"<<std::endl;
    for(int i=0;i<(int)m_particleSystemList.size();++i)
    {
        delete m_particleSystemList[i];
    }
}

void Tornado::createParticleSystem()
{//std::cout<<"running"<< std::endl;
    if (m_particleSystemCount < m_particleSystemTreshold)
    {
        int diffrence=m_particleSystemTreshold - m_particleSystemCount;
        for (int i=0; i<diffrence;i++)
        {
            std::random_device rd;
            std::mt19937_64 gen(rd());

            std::uniform_real_distribution<float> distribution(m_radiusRange[0],m_radiusRange[1]);
            float radius = distribution(gen);
            //std::cout<<"radius:"<<radius<<"\n";
            std::uniform_real_distribution<float> distribution1(0.0,10.0);
            float offset = distribution1(gen);
            //std::cout<<"offset:"<<offset<<"\n";


            ParticleSystem* PartSys=new ParticleSystem(radius,offset);
            m_particleSystemList.push_back (PartSys);

            std::vector<ngl::Vec3> particlePoint;



            m_particleSystemCount++;

            if (m_particleSystemCount >= m_particleSystemTreshold){ return;}
            if (i >= m_maxProductionRate){return;}

        }
    }


}

void Tornado::update()
{   //std::cout<<"\nlist lenght"<<m_storeList.size()<<"\n";
    m_storeParticleSysList.clear();
    m_storeParticlePos.clear();
    std::cout<<"running Tornado update\n";
    m_curve.frameChange(m_frame);
    createParticleSystem();
    for (int i=0;i<m_particleSystemCount;i++)
    {

        int particleAge = m_particleSystemList[i]->getAge();

        m_curve.spiral(m_particleSystemList[i]->m_radius,particleAge, m_particleSystemList[i]->m_offset);
        ngl::Vec3 point = m_curve.getPoint();

        //std::cout<<point[0]<<","<<point[1]<<","<<point[2]<<"\n";
        m_storeParticleSysList.push_back(point);

        m_storeParticlePos = m_particleSystemList[i]->move(point,m_storeParticlePos);
        int out=m_particleSystemList[i]->checkKill(m_maxHeight);
        if (out==1)
        {
           delete m_particleSystemList[i];
           m_particleSystemList.erase(m_particleSystemList.begin()+i);
           m_particleSystemCount--;
        }
    }
    m_frame++;
}

void Tornado::printList()
{
    for(int i =0;i<(int)m_storeParticleSysList.size();++i)
    {

            std::cout<<m_storeParticleSysList[i].m_x<< "," <<m_storeParticleSysList[i].m_y<<","  <<m_storeParticleSysList[i].m_z<<";\n";

    }
}
std::vector<ngl::Vec3> Tornado::getParticleSysList()
{
    return m_storeParticleSysList;
}

std::vector<ngl::Vec3> Tornado::getParticleList()
{
    return m_storeParticlePos;
}

int Tornado::getParticleSysCount()
{
    return m_particleSystemCount;
}

void Tornado::save()
{

}

void Tornado::changeMaxHeight(int _changeValue)
{
    m_maxHeight+=_changeValue;
}
int Tornado::getFullParticleCount()
{

    return m_storeParticlePos.size();
}
