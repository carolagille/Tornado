#include "Particle.h"
#include <iostream>

Particle::Particle(float _rgba[4], float _position[])
{
    std::cout<<"Particle created\n";
    m_position[0]=_position[0];
    m_position[1]=_position[1];
    m_position[2]=_position[2];

    m_rgba[0]=_rgba[0];
    m_rgba[1]=_rgba[1];
    m_rgba[2]=_rgba[2];
    m_rgba[3]=_rgba[3];

    m_lifetime=30;
    m_age=0;
    m_velocity[0]=0;
    m_velocity[1]=0;
    m_velocity[2]=0;


}

Particle::~Particle()
{
    std::cout<<"Destructor Particle called"<<std::endl;
}

void Particle::move(float _center[], float _boundingBox)
{
    std::cout<<"movingParticle"<<std::endl;
    //find out how to move
}

int Particle::checkLife()
{
    if(m_age >= m_lifetime)
    {
        return 1;
    }
    else {return 0;}
}
