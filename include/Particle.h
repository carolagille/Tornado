#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Vec4.h>

class Particle
//Particle Class that creates a Partcile and a point representation of it. It moves with its particles origin and creats and in and out movement by
// getting attracted and pushed away from its particle systems center
{
public:
    Particle(ngl::Vec4 _rgba, ngl::Vec3 _center, float _radius);//Constructor get given a random radius and rgba value
    ~Particle();
    int checkLife(); //checkes if the Particle should be killed or not
    void move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox); //moving the particle based on a flock system kind of movement
    void place(ngl::Vec3 _center, float _boundingBox); //called when constructed to place the particle near its particles origin
    ngl::Vec3 getPoints();
private:
    ngl::Vec3 m_position;
    int m_lifetime;
    int m_age;
    ngl::Vec4 m_rgba;

};

#endif // PARTICLE_H
