#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "Particle.h"
#include <forward_list>
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Vec4.h>

class ParticleSystem
//PArticle system Class which creates a colletion of particles that are born live and die over time, they hover around the particle systems center and
// create their own movement. The particle system erases it self when it reaches the top of the tornadoe and is moved along a curve defined int the
//Tornado class.
{
public:
    ParticleSystem(float _radius, float _offset); // constructor takes in the radius from the Tornado class
    ParticleSystem();
    ~ParticleSystem();
    void createParticles(); //creates Particle if the Treshold isn't reached yet
    void move(ngl::Vec3 _position); //moves the particle along the Curve maybe include a age check in here and than delete particle
    int checkKill(float _maxHeight); //if return 0 its keeps living if return 1 it gets killed
    const float m_offset;
    const float m_radius;
    int getAge();
private:

    float m_boundingBox;//for a sphere shape as a fuzzy object (maybe make this a class for diffrent shapes later)
    ngl::Vec3 m_position;
    int m_age;
    ngl::Vec4 m_rgbaRange[2]; //range of colour and transperency the particles are created from
    int m_particleTreshold;
    int m_maxProductionRate;
    int m_particleCount;
    std::vector<Particle*> m_particleList; // list to store the particles


};



#endif
