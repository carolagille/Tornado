#include "Organizer.h"
#include "ParticleSubsystem.h"
#include <random>
#include <vector>
#include<iostream>
Organizer::Organizer()
{
    m_frame=0;
    m_partSubsysTreshold=1000; //equals to 10000 particles in total as every partciel subsys has 100 particles it self
    m_maxProductionRate=100;
    m_particleSubsysCount=0;
    m_radiusRange[0]=5.0;
    m_radiusRange[1]=7.0;
    m_partSubsysList = std::vector<ParticleSubsystem> ();
    createParticleSubsys();

}

Organizer::~Organizer()
{
    //maybe add something that deletes all the particleSubsystems
    //figure out how forward list work and destroy themselves
}

void Organizer::createParticleSubsys()
{
    if (m_particleSubsysCount < m_partSubsysTreshold)
    {
        int diffrence=m_partSubsysTreshold - m_particleSubsysCount;
        for (int i=0; i<diffrence;i++)
        {
            std::default_random_engine generator;
            std::uniform_real_distribution<float> distribution(m_radiusRange[0],m_radiusRange[1]);
            float radius = distribution(generator);


            std::default_random_engine generator1;
            std::uniform_real_distribution<float> distribution1(0.0,1.0);
            float offset = distribution1(generator1);

            ParticleSubsystem PartSub(radius,offset);
            m_partSubsysList.push_back (PartSub);

            m_particleSubsysCount++;
            if (m_particleSubsysCount >= m_partSubsysTreshold){return;}


        }
    }

}

void Organizer::timerEvent()
{
    createParticleSubsys();
    for (int i=0;i<=m_particleSubsysCount;i++)
    {
        m_partSubsysList[i].move();
        int out=m_partSubsysList[i].checkLife();
        if (out==1)
        {
           m_partSubsysList.erase(m_partSubsysList.begin()+i);
        }
    }
    m_frame++;
}

void save()
{

}
