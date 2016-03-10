#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/Vec4.h>

class Particle
{
public:
    Particle(ngl::Vec4 _rgba, ngl::Vec3 _center, float _radius);
    ~Particle();
    int checkLife();
    void move(ngl::Vec3 _newCenter, ngl::Vec3 _center, float _boundingBox); //maybe make this delete the particle if its lifetime is over
    void place(ngl::Vec3 _center, float _boundingBox);
private:
    ngl::Vec3 m_position;
    int m_lifetime;
    int m_age;
    ngl::Vec4 m_rgba;

};

#endif // PARTICLE_H
