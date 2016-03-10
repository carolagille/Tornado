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
    m_particleSystemTreshold=10; //equals to 10000 particles in total as every partciel subsys has 100 particles it self
    m_maxProductionRate=1;
    m_particleSystemCount=0;
    m_radiusRange[0]=5.0;
    m_radiusRange[1]=7.0;
    m_maxHeight=_maxHeight;
    m_particleSystemList = std::vector<ParticleSystem*> ();
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
{
    if (m_particleSystemCount < m_particleSystemTreshold)
    {
        int diffrence=m_particleSystemTreshold - m_particleSystemCount;
        for (int i=0; i<diffrence;i++)
        {
            std::default_random_engine generator;
            std::uniform_real_distribution<float> distribution(m_radiusRange[0],m_radiusRange[1]);
            float radius = distribution(generator);

            std::uniform_real_distribution<float> distribution1(0.0,1.0);
            float offset = distribution1(generator);

            ParticleSystem* PartSys=new ParticleSystem(radius,offset);
            m_particleSystemList.push_back (PartSys);

            m_particleSystemCount++;
            std::cout<<"running"<< std::endl;
            if (m_particleSystemCount >= m_particleSystemTreshold){ return;}
            if (i >= m_maxProductionRate){return;}

        }
    }


}

void Tornado::timerEvent()
{
    m_curve.frameChange(m_frame);
    createParticleSystem();
    for (int i=0;i<=m_particleSystemCount;i++)
    {
        int particleAge = m_particleSystemList[i]->getAge();
        m_curve.spiral(m_particleSystemList[i]->m_radius,particleAge, m_particleSystemList[i]->m_offset);
        ngl::Vec3 point = m_curve.getPoint();

        m_particleSystemList[i]->move(point);
        int out=m_particleSystemList[i]->checkKill(m_maxHeight);
        if (out==1)
        {
           delete m_particleSystemList[i];
           m_particleSystemList.erase(m_particleSystemList.begin()+i);
        }
    }
    m_frame++;
}

void save()
{

}
