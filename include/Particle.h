#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <iostream>
#include <random>

/// @file Particle.h
/// @brief
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class Particle
/// @brief Particle Class that defines one single particle


class Particle
{
public:
    ///@brief Particle Constructor
    /// @param[in] _center takes in the center of the particle system
    /// @param[in] _radius defining the radius that the particle can be placed in
    /// @param[in] _lifeRange sets the life time of the particle
    Particle(ngl::Vec3 _center, float _radius,ngl::Vec2 _lifeRange);
    ///@brief Particle Destructor
    ~Particle();
    ///@brief checks if the particle life has exeeded and returns 1 if if did
    /// @param[out] returns 1 if particle should be killed
    int checkLife();
    ///@brief moving function that moves the particle based on attraction to
    /// the tornado center and the particle system movement
    /// @param[in] _newCenter is the particles systems new center
    /// @param[in] _center old center of particle system to calculate the velocity
    /// @param[in] _boundingBox gives the bounding box that the particle can move in
    /// @param[in] _tornadoCenter takes in the tornadoes center
    void move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox, ngl::Vec3 _tornadoCenter);
    /// @brief moving function that moves the particle to a random point in the bounding box
    /// @param[in] _newCenter passes the new center of the particle system
    /// @param[in] _boundinBox defines the boundingBox in which the particle can be placed
    void move(ngl::Vec3 _newCenter, float _boundingBox);
    /// @brief places the particle in a boundbox around a center
    /// @param[in] _center takes in the particle systems center
    /// @param[in] _boundingBox takes in the bounding box in which the particle can be placed
    ngl::Vec3 place(ngl::Vec3 _center, float _boundingBox);
    ///@brief gets the particles position
    ngl::Vec3 getPoints();
private:
    ///@brief stores the particles position
    ngl::Vec3 m_position;
    ///@brief stores the particles lifetime
    int m_lifetime;
    ///@brief saves the particles age
    int m_age;
    ///@brief saves the velocity of the particle
    ngl::Vec3 m_velocity;

};

#endif // PARTICLE_H
