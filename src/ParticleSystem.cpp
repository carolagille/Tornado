#include "ParticleSystem.h"
#include "Particle.h"
#include "TornadoCurve.h"
#include "Tornado.h"
#include <vector>
#include<random>
#include<iostream>

ParticleSystem::ParticleSystem()
{
    std::cout<<"ParticleSystem created\n";
    m_offset=0;
    m_boundingBox = 0.5; //radius of a sphere soroundig the particle
    m_position[0] = 0;
    m_position[1] = 0;
    m_position[2] = 0;

    m_age = 0;
    m_rgbaRange[0][0]=0.545;
    m_rgbaRange[0][1]=0.513;
    m_rgbaRange[0][2]=0.470;
    m_rgbaRange[0][3]=1.0;

    m_rgbaRange[1][0]=0.8;
    m_rgbaRange[1][1]=0.78;
    m_rgbaRange[1][2]=0.69;
    m_rgbaRange[1][3]=0.8;
    m_particleTreshold=10;
    m_radius=5;
    m_maxProductionRate=1;
    m_particleCount=0;
    m_particleList=std::vector<Particle*> ();
    createParticles();

}

ParticleSystem::ParticleSystem(float _radius, float _offset)
{
    std::cout<<"ParticleSystem created\n";
    m_offset=_offset;
    m_boundingBox = 0.5; //radius of a sphere soroundig the particle
    m_position[0] = 0;
    m_position[1] = 0;
    m_position[2] = 0;

    m_age = 0;
    m_rgbaRange[0][0]=0.545;
    m_rgbaRange[0][1]=0.513;
    m_rgbaRange[0][2]=0.470;
    m_rgbaRange[0][3]=1.0;

    m_rgbaRange[1][0]=0.8;
    m_rgbaRange[1][1]=0.78;
    m_rgbaRange[1][2]=0.69;
    m_rgbaRange[1][3]=0.8;
    m_particleTreshold=10;
    m_radius=_radius;
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

void ParticleSystem::move()
{

    //Tornado.m_curve.spiral(m_radius,m_age,m_offset);
    //float new_pos[3];
    //Tornado::m_curve.getPoint(&new_pos);



    createParticles();
    for (int i=0;i<=m_particleCount;i++)
    {
        m_particleList[i]->move(m_position,m_boundingBox);
        int out=m_particleList[i]->checkLife();
        if (out==1)
        {
           delete m_particleList[i];
           m_particleList.erase(m_particleList.begin()+i);
        }
    }

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
