#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "Particle.h"
#include <memory>


/// @file ParticleSystem.h
/// @brief
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class ParticleSystem
/// @brief Particle System Class that defines a particle system holding a list of particle objects


class ParticleSystem
{
public:
    ///@brief Constructor that had input values to allow more control over the particle system
    /// @param _radius the radius that is used by the tornado curve class to calculate the radius its rotating around the tornado
    /// @param _offset offset value that is used by the tornado curve to offset the starting position of the rotation
    /// @param _treshold sets a value that hold the treshold so the max particle value of this particle system
    /// @param _cloudHeight defines the height of the cloud that is created a t the top of the tornado
    /// it is used to check when the particle system is meant to be killed
    /// increasing the height will automatically make the cloud wider as it keeps growing outwards
    /// @param _productionRate
    ParticleSystem(float _radius, float _offset, int _treshold,int _cloudHeight,int _productionRate,int _lifetimeRange[2]); // constructor takes in the radius from the Tornado class
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
    void setlifeTimeRange(int _changeValue, int _minMax);
    void setProductionRate(int _value);
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
