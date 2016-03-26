#include "Particle.h"
#include <iostream>
#include <random>
Particle::Particle(ngl::Vec4 _rgba, ngl::Vec3 _center, float _radius)
{   //Constructor

    //std::cout<<"Particle created\n";
    m_position=ngl::Vec3(0.0f,0.0f,0.0f);

    m_rgba=(_rgba);

    m_lifetime=100;
    m_age=0;
    m_velocity=ngl::Vec3(0.0f,0.0f,0.0f);

    place(_center,_radius);

}

Particle::~Particle()
{
    //std::cout<<"Destructor Particle called"<<std::endl;
}

void Particle::move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox,ngl::Vec3 _tornadoCenter)
{
    //This function calculates the movement of one particle by testing its position relative to the particle System center and
    //the tornado center and calculates the according movment
    /*In case the particle is out side of the bounding box it is attracted to the center of the Particle system
     *
     * If its inside of it it can be on the side of the tornado center or on the opposite
     * it is than pushed away from the center
     *
     * To get a more fluid trasision the previous velocity is taken in consideration
     *
     * and also a softening area between the two extremes is created
    */



    ngl::Vec3 particleSysTornadoCenter(_tornadoCenter - _center);
    ngl::Vec3 particleTornadoCenter(_tornadoCenter - m_position);
    ngl::Vec3 particleParticleSys(_center-m_position);
    ngl::Vec3 particleSysVelocity(_newCenter-_center);


    if(particleParticleSys.length()>_boundingBox)
    {
        m_velocity=(0.5*m_velocity)+(0.3*particleSysVelocity)+(0.2*particleParticleSys);
    }


    else if(0.6*_boundingBox<particleParticleSys.length()<0.4*_boundingBox)
    {
        m_velocity=(0.5*m_velocity)+(0.5*particleSysVelocity);
    }


    else if(particleParticleSys.length()<=0.4*_boundingBox)
    {
        particleSysTornadoCenter.normalize();
        if(particleSysTornadoCenter.length() > particleTornadoCenter.length())
        {
            m_velocity=(0.5*m_velocity)+(0.3*particleSysVelocity)+(0.2*particleSysTornadoCenter);
        }
        else if(particleSysTornadoCenter.length() <= particleTornadoCenter.length())
        {
            m_velocity=(0.5*m_velocity)+(0.3*particleSysVelocity)-(0.2*particleSysTornadoCenter);
        }
    }
    m_position+=m_velocity;

    m_age++;
}

int Particle::checkLife()
{ //this function checkes the lifetime and returns 1 if this life is outrun
    if(m_age >= m_lifetime)
    {
        return 1;
    }
    else {return 0;}
}

void Particle::place(ngl::Vec3 _center, float _boundingBox)
{ //This function is called once when the particle is created to place it at a random position inside the particles systems bounding box
    for(int i=0; i<=2;i++)
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());

        std::uniform_real_distribution<float> distribution(-_boundingBox,_boundingBox);
        //std::uniform_int_distribution<int> distribution(0.0,100.0);
        m_position[i]=_center[i]+float(distribution(gen));
    }
    std::cout<<"paticle position"<<m_position[0]<<m_position[1]<<m_position[2]<<"\n";
}

ngl::Vec3 Particle::getPoints()
{
    return m_position;
}
