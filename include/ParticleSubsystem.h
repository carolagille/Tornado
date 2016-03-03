#ifndef PARTICLESUBSYSTEM_H
#define PARTICLESUBSYSTEM_H
#include "Particle.h"
#include <forward_list>
#include <vector>
class ParticleSubsystem
{
public:
    ParticleSubsystem(float _radius,float _offset); // constructor takes in the radius from the Organizer class
    ~ParticleSubsystem();
    void createParticles(); //creates Particle if the Treshold isn't reached yet
    void move(); //moves the particle along the Curve maybe include a age check in here and than delete particle
    int checkLife(); //if return 0 its keeps living if return 1 it gets killed
private:
    float m_offset;
    float m_boundingBox;//for a sphere shape as a fuzzy object (maybe make this a class for diffrent shapes later)
    float m_position[3];
    int m_lifetime;
    int m_age;
    float m_rgbaRange[2][4]; //range of colour and transperency the particles are created from
    int m_particleTreshold;
    float m_radius;
    int m_maxProductionRate;
    int m_particleCount;
    std::vector<Particle> m_particleList; // list to store the particles
};



#endif // PARTICLESUBSYSTEM_H
