#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
class Particle
{
public:
    Particle(float _rgba[4], float _center[3], float _radius);
    ~Particle();
    int checkLife();
    void move(float _center[3], float _boundingBox); //maybe make this delete the particle if its lifetime is over
    void place(float _center[3], float _boundingBox);
private:
    float m_position[3];
    int m_lifetime;
    int m_age;
    float m_rgba[4];
    float m_velocity[3]; //speed and direction
};

#endif // PARTICLE_H
