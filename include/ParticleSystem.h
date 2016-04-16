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
    /// @param[in] _radius the radius that is used by the tornado curve class to calculate the radius its rotating around the tornado
    /// @param[in] _offset offset value that is used by the tornado curve to offset the starting position of the rotation
    /// @param[in] _treshold sets a value that hold the treshold so the max particle value of this particle system
    /// @param[in] _cloudHeight defines the height of the cloud that is created a t the top of the tornado
    /// it is used to check when the particle system is meant to be killed
    /// increasing the height will automatically make the cloud wider as it keeps growing outwards
    /// @param[in] _productionRate passes in the particle production so that it can be controlled by the user
    /// @param[in] _lifetimeRange takes in the 2 intergers that define the range for the particle life that is chososen randomly from that range
    ParticleSystem(float _radius, float _offset, int _treshold,int _cloudHeight,int _productionRate,int _lifetimeRange[2]);
    ///@brief default constructor
    ParticleSystem();
    ///@brief destructor
    ~ParticleSystem();
    ///@brief function that creates new particles if the particle treshold isn't reached
    void createParticles();
    ///@briefmoves the particle and all particles inside it and update the list that hold the position information of the particles
    /// @param[in] _position particle systems new position that is calculated by the tornado class
    /// @param[in] _particlePosList passing in the list that holds the postition information of the particle
    /// @param[in] _center passes the tornado center
    /// @param[in] _particleMoveState takes in a value that is responsible fir which move particle move function is going to be called
    void move(ngl::Vec3 _position, std::vector<ngl::Vec3> * _particlePosList, ngl::Vec3 _center, int _particleMoveState);
    ///@brief checks if the particle system reached a maximum height
    /// @param[in] _maxHeight value that is the max height of the tonrdo
    /// this plus the cloud height is the actual height of the whole tornado
    /// @param[out] retruns 1 if particle system is to be deleted
    int checkKill(float _maxHeight);
    ///@brief offset value that needs to be used by tornado class
    const float m_offset;
    ///@brief radius value that
    const float m_radius;
    ///@brief gets tha age value of the particle system
    /// @param[out] returns the age value as an integer
    int getAge();
    ///@brief gets the amount of particles in the particle system
    /// @param [out] return the particleCount variable of the particleSystem class
    int getParticleCount();
    ///@brief sets the particle treshold
    /// @param[in] value to set it
    void setParticles(int _value);
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
