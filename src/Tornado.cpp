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
    m_particleSystemTreshold=5;
    m_maxProductionRate=3;
    m_particleSystemCount=0;
    m_radiusRange[0]=1.0;
    m_radiusRange[1]=10.0;
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
            std::uniform_real_distribution<float> distribution1(0.0,5.0);
            float offset = distribution1(gen);
            //std::cout<<"offset:"<<offset<<"\n";


            ParticleSystem* PartSys=new ParticleSystem(radius,offset);
            m_particleSystemList.push_back (PartSys);

            std::vector<ngl::Vec3> particlePoint;

            m_storeList.push_back(particlePoint);

            m_particleSystemCount++;

            if (m_particleSystemCount >= m_particleSystemTreshold){ return;}
            if (i >= m_maxProductionRate){return;}

        }
    }


}

void Tornado::update()
{
    //std::cout<<"running Tornado update\n";
    m_curve.frameChange(m_frame);
    createParticleSystem();
    for (int i=0;i<m_particleSystemCount;i++)
    {

        int particleAge = m_particleSystemList[i]->getAge();

        m_curve.spiral(m_particleSystemList[i]->m_radius,particleAge, m_particleSystemList[i]->m_offset);
        ngl::Vec3 point = m_curve.getPoint();

        //std::cout<<point[0]<<","<<point[1]<<","<<point[2]<<"\n";
        m_storeList[i].push_back(point);

        m_particleSystemList[i]->move(point);
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
    for(int i =0;i<(int)m_storeList.size();++i)
    {
        std::cout<<"\n \n \n\"ParticleSystem"<<i<<"\":[\n";
        for(int j=0;j<(int)m_storeList[i].size();++j)
        {

            std::cout<<m_storeList[i][j].m_x<< "," <<m_storeList[i][j].m_y<<","  <<m_storeList[i][j].m_z<<";\n";
        }
    }
}

void Tornado::save()
{

}
