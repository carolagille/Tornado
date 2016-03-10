#ifndef TORNADO_H
#define TORNADO_H
#include "TornadoCurve.h"
#include <vector>
#include "ParticleSystem.h"
#include <ngl/Vec3.h>

class Tornado
{
public:
    Tornado(int _changeRate,ngl::Vec3 _controlPoint[3], float _maxHeight);
    ~Tornado();
    void createParticleSystem();
    void save();
    void timerEvent();
    TornadoCurve m_curve;
private:
    int m_frame;
    int m_particleSystemTreshold;
    int m_particleSystemCount;
    std::vector<ParticleSystem*> m_particleSystemList;
    int m_maxProductionRate;
    float m_radiusRange[2];
    float m_maxHeight;




};

#endif // Tornado_H
