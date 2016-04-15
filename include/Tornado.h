#ifndef TORNADO_H
#define TORNADO_H
#include "TornadoCurve.h"
#include "ParticleSystem.h"
#include "QObject"
#include <memory>

class Tornado: public QObject
{
  Q_OBJECT
public slots:
  void particlesOnOff(bool state);
  void changeParticleCount(int value);
  void setHeight(int _changeValue);
  void setRadiusMin(double _changeValue);
  void setRadiusMax(double _changeValue);
  void setCloudHeight(int _value);
  void setParticleMoveState(int _changeValue);
  void setParticleTimeRangeMin(int _changeValue);
  void setParticleTimeRangeMax(int _changeValue);
  void setParticleSysTreshold(int _value);
  void setProductionRate(int _value);
  void setParticleProductionRate(int _value);
signals:
  void resetRadiusMin(double _changeValue);
  void resetRadiusMax(double _changeValue);
  void resetparticlesOnOff(bool state);
  void resetParticleCount(int value);
  void resetCloudHeight(int _value);
  void resetParticleSysTreshold(int _value);
  void resetProductionRate(int _value);
  void resetParticleProductionRate(int _value);
  void resetParticleMoveState(int _changeValue);
  void resetParticleTimeRangeMin(int _changeValue);
  void resetParticleTimeRangeMax(int _changeValue);
public:
    Tornado(TornadoCurve* _curve);
    ~Tornado();
    void createParticleSystem();
    void save();
    void update();
    TornadoCurve *m_curve;
    void printList();
    std::vector<ngl::Vec3> getParticleSysList();
    std::vector<ngl::Vec3> getParticleList();
    int getParticleSysCount();
    void restart();
    int getFullParticleCount();

private:
    int m_frame;
    int m_particleSystemTreshold;
    int m_particleSystemCount;
    std::vector<std::unique_ptr<ParticleSystem>> m_particleSystemList;
    int m_maxProductionRate;
    float m_radiusRange[2];
    float m_maxHeight;
    float m_radiusChange;
    int m_radiusDiffrence;
    int m_particleState;
    int m_particleCount;
    std::vector<ngl::Vec3> m_storeParticlePos;
    std::vector<ngl::Vec3> m_storeParticleSysList;
    int m_particleMoveState;
    int m_cloudHeight;
    int m_particleProdutionRate;
    int m_particleLifeRange[2];




};

#endif // Tornado_H
