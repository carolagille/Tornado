#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
class Particle
{
public:
    Particle(float _rgba[4]);
    ~Particle();
    int checkLife();
    void move(float _center, int _boundingBox); //maybe make this delete the particle if its lifetime is over
private:
    float m_position[3];
    int m_lifetime;
    int m_age;
    float m_rgbaRange[4];
    float velocity; //speed and direction
};

#endif // PARTICLE_H
