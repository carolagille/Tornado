#include "Particle.h"

Particle::Particle( ngl::Vec3 _center, float _radius,ngl::Vec2 _lifeRange)
{   //Constructor


    m_position=ngl::Vec3(0.0f,0.0f,0.0f);
    //creates a random life time from the time range
    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<int> distribution(_lifeRange[0],_lifeRange[1]);

    m_lifetime= distribution(gen);
    m_age=0;
    m_velocity=ngl::Vec3(0.0f,0.0f,0.0f);

    //places the particle randomaly in some place in the bounding box of the parent particle system
    m_position=place(_center,_radius);
}
//------------------------------------------------------------------------------------------------------------------
Particle::~Particle()
{

}
//------------------------------------------------------------------------------------------------------------------
int Particle::checkLife()
{ //this function checkes the lifetime and returns 1 if this life is outrun
    if(m_age >= m_lifetime)
    {
        return 1;
    }
    else {return 0;}
}
//------------------------------------------------------------------------------------------------------------------
void Particle::move(ngl::Vec3 _newCenter,  float _boundingBox)
{
    //places particle at a random position
    m_position=place(_newCenter,_boundingBox);
    m_age++;

}
//------------------------------------------------------------------------------------------------------------------
void Particle::move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox,ngl::Vec3 _tornadoCenter)
{

    /*This function calculates the movement of one particle by testing its position relative to the particle System center and
     *the tornado center and calculates the a velocity combinging thoose two
     *In case the particle is out side of the bounding box it is attracted to the center of the Particle system
     *
     * If its inside of the bounding box it can be on the side of the tornado center or on the opposite
     * it is than pushed away from the center
     *
     * To get a more fluid trasision the previous velocity is taken in consideration
     *
     * and also a softening area between the two extremes is created
    */


    //holds mid calculation results
    ngl::Vec3 particleSysTornadoCenter(_tornadoCenter - _center);
    ngl::Vec3 particleTornadoCenter(_tornadoCenter - m_position);
    ngl::Vec3 particleParticleSys(_center-m_position);
    ngl::Vec3 particleSysVelocity(_newCenter-_center);


    if(particleParticleSys.length()>_boundingBox)
    {
        //checks if particle is on outside of the bounding box
        //than attracs it to the particle system center
        m_velocity=(0.3*m_velocity)+(0.5*particleSysVelocity)+(0.2*particleParticleSys);
    }


    else if(_boundingBox<particleParticleSys.length()<0.6*_boundingBox)
    {
        //buffer area
        m_velocity=m_velocity;
    }


    else if(particleParticleSys.length()<=_boundingBox)
    {
        //inside bounding box
        particleSysTornadoCenter.normalize();
        if(particleSysTornadoCenter.length() > particleTornadoCenter.length())
        {
            //inside tornado
            m_velocity=(0.5*m_velocity)+(0.3*particleSysVelocity)+(0.2*particleSysTornadoCenter);
        }
        else if(particleSysTornadoCenter.length() <= particleTornadoCenter.length())
        {
            //outside tornado
            m_velocity=(0.5*m_velocity)+(0.3*particleSysVelocity)-(0.2*particleSysTornadoCenter);
        }
    }
    m_position+=m_velocity;

    m_age++;
}



ngl::Vec3 Particle::place(ngl::Vec3 _center, float _boundingBox)
{ //This function places the particle at a random point inside the bounding box of the particle system
    ngl::Vec3 position;
    for(int i=0; i<=2;i++)
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());

        std::uniform_real_distribution<float> distribution(-_boundingBox,_boundingBox);

        position[i]=_center[i]+float(distribution(gen));
    }
    return position;

}

ngl::Vec3 Particle::getPoints()
{
    return m_position;
}
