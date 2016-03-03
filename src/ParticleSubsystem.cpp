#include "ParticleSubsystem.h"
#include "Particle.h"
#include <vector>
#include<random>
#include<iostream>


ParticleSubsystem::ParticleSubsystem(float _radius, float _offset)
{
    m_offset=_offset;
    m_boundingBox = 0.5; //radius of a sphere soroundig the particle
    m_position[0] = 0;
    m_position[1] = 0;
    m_position[2] = 0;
    m_lifetime = 200; //make sure this is around the same as the time up
    m_age = 0;
    m_rgbaRange[0][0]=0.545;
    m_rgbaRange[0][1]=0.513;
    m_rgbaRange[0][2]=0.470;
    m_rgbaRange[0][3]=1.0;

    m_rgbaRange[1][0]=0.8;
    m_rgbaRange[1][1]=0.78;
    m_rgbaRange[1][2]=0.69;
    m_rgbaRange[1][3]=0.8;
    m_particleTreshold=100;
    m_radius=_radius;
    m_maxProductionRate=10;
    m_particleCount=0;
    createParticles();
}

ParticleSubsystem::~ParticleSubsystem()
{
  std::cout<<"Destructor Particle Subsystem called"<<std::endl;
}

void ParticleSubsystem::createParticles()
{
    if (m_particleCount < m_particleTreshold)
    {
        int diffrence=m_particleTreshold - m_particleCount;
        for (int i=0; i<diffrence;i++)
        {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(1,2);
            int color= distribution(generator);
            //for now particles created at the origin
            Particle Part(m_rgbaRange[color],m_position);
            m_particleList.push_back(Part);

            m_particleCount++;
            if (m_particleCount >= m_particleTreshold){return;}


        }
    }
}

void ParticleSubsystem::move()
{
    createParticles();
    for (int i=0;i<=m_particleCount;i++)
    {
        m_particleList[i].move(m_position,m_boundingBox);
        int out=m_particleList[i].checkLife();
        if (out==1)
        {
           m_particleList.erase(m_particleList.begin()+i);
        }
    }

    //insert Curve function stuff here
}


int ParticleSubsystem::checkLife()
{
    if(m_age >= m_lifetime)
    {
        return 1;
    }
    else {return 0;}
}
