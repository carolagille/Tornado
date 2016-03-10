#include "ParticleSystem.h"
#include "Particle.h"
#include "TornadoCurve.h"
#include "Tornado.h"
#include <vector>
#include<random>
#include<iostream>

ParticleSystem::ParticleSystem():
m_offset(0),
m_radius(5)
{
    std::cout<<"ParticleSystem created\n";

    m_boundingBox = 0.5; //radius of a sphere soroundig the particle
    m_position = (0.0f,0.0f,0.0f);
    m_age = 0;

    m_rgbaRange[0]= (0.545f,0.513f,0.470f,1.0f);
    m_rgbaRange[1]= (0.8f,0.78f,0.69f,0.8);

    m_particleTreshold=1;

    m_maxProductionRate=1;
    m_particleCount=0;
    m_particleList=std::vector<Particle*> ();
    createParticles();

}

ParticleSystem::ParticleSystem(float _radius, float _offset):
m_offset(_offset),
m_radius(_radius)
{
    std::cout<<"ParticleSystem created\n";
    m_boundingBox = 0.5; //radius of a sphere soroundig the particle

    m_position = (0.0f,0.0f,0.0f);

    m_age = 0;

    m_rgbaRange[0]= (0.545f,0.513f,0.470f,1.0f);
    m_rgbaRange[1]= (0.8f,0.78f,0.69f,0.8);

    m_particleTreshold=10;
    m_maxProductionRate=1;
    m_particleCount=0;
    m_particleList=std::vector<Particle*> ();
    createParticles();
}

ParticleSystem::~ParticleSystem()
{
  std::cout<<"Destructor Particle System called"<<std::endl;
  for(int i=0;i<=(int)m_particleList.size();++i)
  {
      delete m_particleList[i];
  }

}

void ParticleSystem::createParticles()
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
            Particle *Part = new Particle(m_rgbaRange[color],m_position,m_boundingBox);
            m_particleList.push_back(Part);

            m_particleCount++;
            if (m_particleCount >= m_particleTreshold){return;}


        }
    }
}

void ParticleSystem::move(ngl::Vec3 _position)
{




    createParticles();
    for (int i=0;i<=m_particleCount;i++)
    {
        m_particleList[i]->move(_position,m_position,m_boundingBox);
        int out=m_particleList[i]->checkLife();
        if (out==1)
        {
           delete m_particleList[i];
           m_particleList.erase(m_particleList.begin()+i);
        }
    }

    m_position[0]= _position[0];
    m_position[1]= _position[1];
    m_position[2]= _position[2];

    //insert Curve function stuff here
}


int ParticleSystem::checkKill(float _maxHeight)
{
    if(m_position[2] >= _maxHeight)
    {
        return 1;
    }
    else {return 0;}
}

int ParticleSystem::getAge()
{
    return m_age;
}
