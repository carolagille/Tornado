#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <vector>
#include"ParticleSubsystem.h"

class Organizer
{
public:
    Organizer();
    ~Organizer();
    void createParticleSubsys();
    void save();
    void timerEvent();
private:
    int m_frame;
    int m_partSubsysTreshold;
    int m_particleSubsysCount;
    std::vector<ParticleSubsystem> m_partSubsysList;
    int m_maxProductionRate;
    float m_radiusRange[2];



};

#endif // ORGANIZER_H
