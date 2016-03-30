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
    void update();
    TornadoCurve m_curve;
    void printList();
    std::vector<ngl::Vec3> getParticleSysList();
    std::vector<ngl::Vec3> getParticleList();
    int getParticleSysCount();
    void changeMaxHeight(int _changeValue);
    int getFullParticleCount();
    void particlesOnOff();

private:
    int m_frame;
    int m_particleSystemTreshold;
    int m_particleSystemCount;
    std::vector<ParticleSystem*> m_particleSystemList;
    int m_maxProductionRate;
    float m_radiusRange[2];
    float m_maxHeight;
    float m_radiusChange;
    int m_radiusDiffrence;
    int m_particleState;

    std::vector<ngl::Vec3> m_storeParticlePos;
    std::vector<ngl::Vec3> m_storeParticleSysList;




};

#endif // Tornado_H
