#ifndef TORNADO_H
#define TORNADO_H
#include "TornadoCurve.h"
#include "ParticleSystem.h"
#include "QObject"
#include <memory>

/// @file Tornado.h
/// @brief inherites from QObject
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class Tornado
/// @brief Tornado Class that holds the particles systems


class Tornado: public QObject
{
  Q_OBJECT
public slots:
  ///@brief slot that toggles if the particles in the particle systems should be on or off
  /// @param [in] _state value that set on or off
  void particlesOnOff(bool _state);
  ///@brief slot that sets the particle count for the particle systems
  /// @param[in] _value values to set
  void setParticleCount(int _value);
  ///@brief slot that sets the maximum height value of the tornado
  /// @param[in] _value sets the value to set
  void setHeight(int _value);
///@brief slot that sets the radius minumum
/// @param[in] _value value to set
  void setRadiusMin(double _value);
  ///@brief slot that sets the radius maximum
  /// @param[in] _value value to set
  void setRadiusMax(double _value);
  ///@brief slot that sets the cloud height value
  /// @param[in] _value value to set
  void setCloudHeight(int _value);
  ///@brief slot that sets the particle move state to either one or zero representing the way the particle movement is calculated
  /// @param[in] _value value to set
  void setParticleMoveState(int _value);
  ///@brief slot that sets the minimum for the particle life time
  /// @param[in] _value value to set
  void setParticleTimeRangeMin(int _value);
  ///@brief slot that sets the maximum for the particle life time
  /// @param[in] _value value to set
  void setParticleTimeRangeMax(int _changeValue);
  ///@brief slot that sets the particle system treshold
  /// @param[in] _value value to set
  void setParticleSysTreshold(int _value);
  ///@brief slot that sets the maximum production rate of particle systems
  /// @param[in] _value value to set
  void setProductionRate(int _value);
  ///@brief slot that sets the maximum production rate for each particle system which controlls how many particles are produced
  /// @param[in] _value value to set
  void setParticleProductionRate(int _value);
signals:
  ///@brief signal that emmit the radius min when this is resetted
  /// received by the radius min button in the user interface
  /// @param [in] _value value that is emitted
  void resetRadiusMin(double _value);
  ///@brief signal that emmit the radius maxiumum when this is resetted
  /// received by the radius max button in the user interface
  /// @param [in] _value value that is emitted
  void resetRadiusMax(double _value);
  ///@brief signal that emmit the particle state (if particles are displayed or not) when this is resetted
  /// received by the particle tick box in the user interface
  /// @param [in] _state state that is emitted
  void resetparticlesOnOff(bool state);
  ///@brief signal that emmit the particle when this is resetted
  /// received by the particle count field in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleCount(int _value);
  ///@brief signal that emmit the cloud height when this is resetted
  /// received by the cloud height field in the user interface
  /// @param [in] _value value that is emitted
  void resetCloudHeight(int _value);
  ///@brief signal that emmit particle system treshold when this is resetted
  /// received by the particle system field in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleSysTreshold(int _value);
  ///@brief signal that emmit maximum production rate when this is resetted
  /// received by the max production rate field in the user interface
  /// @param [in] _value value that is emitted
  void resetProductionRate(int _value);
  ///@brief signal that emmit maximum particle production rate when this is resetted
  /// received by the particle prodcution rate field in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleProductionRate(int _value);
  ///@brief signal that emmit the move state when this is resetted
  /// received by the move state drop down menue in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleMoveState(int _value);
  ///@brief signal that emmit the minimum time for particle when this is resetted
  /// received by the minumum life range field in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleTimeRangeMin(int _value);
  ///@brief signal that emmit the maximum time for particle when this is resetted
  /// received by the maximum life range field in the user interface
  /// @param [in] _value value that is emitted
  void resetParticleTimeRangeMax(int _value);
public:
  ///@brief Constructor
  /// @param[in] _curve tornado curve pointer to the tornado curve that calculates the particle system positions
    Tornado(TornadoCurve* _curve);
    ///@brief Destructor
    ~Tornado();
    ///@brief creates new particle systems if treshold isn't reached
    void createParticleSystem();
    ///@brief update function that is called each frame and updated the particles system and so the particle positions
    void update();
    ///@brief prints out the particle systems position
    void printList();
    ///@brief returns the amount of particle system
    /// @param [out] returns the particle system count
    int getParticleSysCount();
    ///@brief resets all variables to their default state and emmits their values
    void reset();
    ///@brief returns the amount of particle that exist in all particle systems together
    /// @param [out] returns the particle count
    int getFullParticleCount();
    ///@brief pointer to the tornado curve object that calculates the particle system positions
    TornadoCurve *m_curve;
    ///@brief returns the paricle system position list
    /// @param [out] return value that returns a list of vec3 objects that hold the position of all particle system positions
    std::vector<ngl::Vec3> getParticleSysList();
    ///@brief returns the particle position list
    /// @param [out] return value that returns a list of vec3 objects that hold the position of all particle system positions
    std::vector<ngl::Vec3> getParticleList();
private:
    ///@brief variable that holds the current frame number
    int m_frame;
    ///@brief variable that hold the particle system treshold so the maxixum amount of particles systems
    int m_particleSystemTreshold;
     ///@brief variable that hold the particle for each particle system treshold so the maxixum amount of particles per particle system
    int m_particleSystemCount;
    ///@brief vector that holds unique pointer to all particle system objects
    std::vector<std::unique_ptr<ParticleSystem>> m_particleSystemList;
    ///@brief variable that controlls how many particle systems can be produce at one frame
    int m_maxProductionRate;
    ///@brief variable that holds teh minimum and maximum value for the particles system radius
    float m_radiusRange[2];
    ///@brief variable that hold the maximum height of the tornado
    float m_maxHeight;
    ///@brief variable that controlls how often the distance between the rings, that are created by the increasing the radius,
    /// is changed
    float m_radiusChange;
    ///@brief controlls how much the rings differe from each other
    int m_radiusDiffrence;
    ///@brief controlls if the particle are displayed or not
    int m_particleState;
    ///@brief controlls how many particles are in one particle system
    int m_particleCount;
    ///@brief list that stores the all particle positions
    std::vector<ngl::Vec3> m_storeParticlePos;
    ///@brief list that stores all particle system positions
    std::vector<ngl::Vec3> m_storeParticleSysList;
    ///@brief variable that holds information about what move function is used for the particle movement
    int m_particleMoveState;
    ///@brief variable that holds the tornado cloud height
    /// if the height is increases the radius is in creased as well
    int m_cloudHeight;
    ///@brief controlls how many particles can be produced by a particle system per frame
    int m_particleProdutionRate;
    ///@brief holds the particle life range that is passed to the particle systems
    int m_particleLifeRange[2];




};

#endif // Tornado_H
