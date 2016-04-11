#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "Particle.h"
#include <memory>

class ParticleSystem
//PArticle system Class which creates a colletion of particles that are born live and die over time, they hover around the particle systems center and
// create their own movement. The particle system erases it self when it reaches the top of the tornadoe and is moved along a curve defined int the
//Tornado class.
{
public:
    ParticleSystem(float _radius, float _offset, int treshold); // constructor takes in the radius from the Tornado class
    ParticleSystem();
    ~ParticleSystem();
    void createParticles(); //creates Particle if the Treshold isn't reached yet
    std::vector<ngl::Vec3> move(ngl::Vec3 _position, std::vector<ngl::Vec3> _particlePos, ngl::Vec3 _center, int _particleMoveState); //moves the particle along the Curve maybe include a age check in here and than delete particle
    int checkKill(float _maxHeight); //if return 0 its keeps living if return 1 it gets killed
    const float m_offset;
    const float m_radius;
    int getAge();
    int getParticleCount();
    void switchParticles(int value);
    void setCloudHeight(int _changeValue);
private:

    float m_boundingBox;//for a sphere shape as a fuzzy object (maybe make this a class for diffrent shapes later)
    ngl::Vec3 m_position;
    int m_age;

    int m_particleTreshold;
    int m_maxProductionRate;
    int m_particleCount;
    std::vector<std::unique_ptr<Particle>> m_particleList; // list to store the particles
    int m_cloudHeight;
    ngl::Vec2 m_lifeTimeRange;



};



#endif
