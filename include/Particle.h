#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <iostream>
#include <random>

class Particle
//Particle Class that creates a Partcile and a point representation of it. It moves with its particles origin and creats and in and out movement by
// getting attracted and pushed away from its particle systems center
{
public:
    Particle(ngl::Vec3 _center, float _radius,ngl::Vec2 _lifeRange);//Constructor get given a random radius and rgba value
    ~Particle();
    int checkLife(); //checkes if the Particle should be killed or not
    void move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox, ngl::Vec3 _tornadoCenter); //moving the particle based on a flock system kind of movement
    void move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox);
    ngl::Vec3 place(ngl::Vec3 _center, float _boundingBox); //called when constructed to place the particle near its particles origin
    ngl::Vec3 getPoints();
private:
    ngl::Vec3 m_position;
    int m_lifetime;
    int m_age;
    ngl::Vec3 m_velocity;

    int m_counter;
    ngl::Vec3 m_newPosition;

};

#endif // PARTICLE_H
