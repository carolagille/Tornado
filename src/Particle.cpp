#include "Particle.h"
#include <iostream>
#include <random>
Particle::Particle(ngl::Vec4 _rgba, ngl::Vec3 _center, float _radius)
{
    std::cout<<"Particle created\n";
    m_position=ngl::Vec3(0.0f,0.0f,0.0f);

    m_rgba=(_rgba);

    m_lifetime=30;
    m_age=0;


    place(_center,_radius);

}

Particle::~Particle()
{
    std::cout<<"Destructor Particle called"<<std::endl;
}

void Particle::move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox)
{
    std::cout<<"movingParticle"<<std::endl;
    ngl::Vec3 velocity = (_newCenter) - (_center);
    ngl::Vec3 midResult = (m_position) + (velocity);
    ngl::Vec3 distance = (midResult) - (_newCenter);

    ngl::Vec3 newPos;

    if(distance.length()<=(0.5* _boundingBox))
    {
        newPos = (midResult) + (0.3 * distance);
    }
    else if(distance.length() > (0.5* _boundingBox))
    {
        newPos = (midResult) - (0.3 * distance);
    }

    m_position= newPos;
}

int Particle::checkLife()
{
    if(m_age >= m_lifetime)
    {
        return 1;
    }
    else {return 0;}
}

void Particle::place(ngl::Vec3 _center, float _boundingBox)
{
    for(int i=0; i<=2;i++)
    {
        std::default_random_engine generator;
        std::uniform_real_distribution<float> distribution(_center[i],_boundingBox);
        m_position[i]=distribution(generator);
    }
}

ngl::Vec3 Particle::getPoints()
{
    return m_position;
}
