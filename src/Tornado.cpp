#include "Tornado.h"
#include "ParticleSystem.h"
#include "TornadoCurve.h"
#include <math.h>

Tornado::Tornado(TornadoCurve *_curve)

{
  //setting all default values
    m_curve=_curve;
    m_frame=0;
    m_particleSystemTreshold=20000;
    m_maxProductionRate=2;
    m_particleSystemCount=0;
    m_radiusRange[0]=4.0;
    m_radiusRange[1]=8.0;
    m_maxHeight=400;
    m_radiusChange=10.0;
    m_radiusDiffrence=2;
    m_particleCount=1;
    m_particleState=0;
    m_particleMoveState=0;
    m_cloudHeight=15;
    m_particleProdutionRate=1;
    m_particleLifeRange[0]=100;
    m_particleLifeRange[1]=170;


    std::cout<< "Tornado created\n";
    //creates particle systes to fill up the tornado
    createParticleSystem();

}
//----------------------------------------------------------------------------------------------------------------------
Tornado::~Tornado()
{

}
//----------------------------------------------------------------------------------------------------------------------
void Tornado::createParticleSystem()
{
  //creates new particle systems if the particle systems count hasn't reached the treshold
    if (m_particleSystemCount < m_particleSystemTreshold)
    {

      //changing the every 50 frames how often the radius should change
        if(m_frame%50==0)
        {
          //gets a random change value from 10 to 100 frames
        std::random_device rd2;
        std::mt19937_64 gen(rd2());

        std::uniform_int_distribution<int> distribution2(10,100);
        m_radiusChange = (float)distribution2(gen);

        //gets a random value from the range of 2-4 that controlls how much the diffrent of the radius should be
        std::uniform_int_distribution<int> distribution3(2,4);
        m_radiusDiffrence=distribution3(gen);
        }
        //creating particle systems
        int diffrence=m_particleSystemTreshold - m_particleSystemCount;
        for (int i=0; i<diffrence;i++)
        {
          //gets a random radius from the radius range
            std::random_device rd;
            std::mt19937_64 gen(rd());

            std::uniform_real_distribution<float> distribution(m_radiusRange[0],m_radiusRange[1]);
            float radius = distribution(gen);
            // caclucaltes the radius the is added on top of the original radius to create a ring type shape
            radius+= sqrt(pow((m_radiusDiffrence*sin((1.0/m_radiusChange)*(float)m_frame)),2));

            // gets a random offset value
            std::uniform_real_distribution<float> distribution1(0.0,20.0);
            float offset = distribution1(gen);

            m_particleSystemList.push_back(std::unique_ptr<ParticleSystem>(new ParticleSystem(radius,offset,m_particleState,m_cloudHeight,m_particleProdutionRate,m_particleLifeRange)));

            m_particleSystemCount++;

            if (m_particleSystemCount >= m_particleSystemTreshold){ return;}
            if (i >= m_maxProductionRate){return;}

        }
    }


}
//----------------------------------------------------------------------------------------------------------------------
void Tornado::update()
{

  for (int i=0;i<m_particleSystemCount;i++)
  {
    //kills all particle systems that run out of life
  int out=m_particleSystemList[i]->checkKill(m_maxHeight);
  if (out==1)
  {
     m_particleSystemList.erase(m_particleSystemList.begin()+i);
     m_particleSystemCount--;
  }
  }
    //clears the store list that store the position of particle and particle systems
    m_storeParticleSysList.clear();
    m_storeParticlePos.clear();

    ngl::Vec3 center;

    //chages frame in tornado curve
    m_curve->frameChange(m_frame);

    //creating new particle systems
    createParticleSystem();

    for (int i=0;i<m_particleSystemCount;i++)
    {
        int particleSystemAge = m_particleSystemList[i]->getAge();
        //calculates the position on the spiral through the tornado curve
        m_curve->spiral(m_particleSystemList[i]->m_radius,particleSystemAge, m_particleSystemList[i]->m_offset);
        ngl::Vec3 point = m_curve->getPoint();
        //center of the tornado
        center= m_curve->getMidPoint();
        //stores the particle systems position
        m_storeParticleSysList.push_back(point);
        //moving particle system and all particles in it
        m_particleSystemList[i]->move(point,&m_storeParticlePos,center,m_particleMoveState);

    }
    m_frame++;
}
//----------------------------------------------------------------------------------------------------------------------
void Tornado::printList()
{
    for(int i =0;i<(int)m_storeParticleSysList.size();++i)
    {

            std::cout<<m_storeParticleSysList[i].m_x<< "," <<m_storeParticleSysList[i].m_y<<","  <<m_storeParticleSysList[i].m_z<<";\n";

    }
}
//----------------------------------------------------------------------------------------------------------------------
void Tornado::reset()
{

  m_particleSystemList.clear();

  m_particleSystemCount=0;

  m_frame=0;
  m_storeParticleSysList.clear();

  createParticleSystem();
  m_storeParticlePos.clear();


  m_frame=0;
  m_particleSystemTreshold=20000;
  emit resetParticleSysTreshold(m_particleSystemTreshold);
  m_maxProductionRate=2;
  emit resetProductionRate(m_maxProductionRate);

  m_radiusRange[0]=4.0;
  m_radiusRange[1]=8.0;
  emit resetRadiusMax(m_radiusRange[1]);
  emit resetRadiusMin(m_radiusRange[0]);

  m_maxHeight=400;
  m_radiusChange=10.0;
  m_radiusDiffrence=2;
  m_particleCount=1;
  emit resetParticleCount(m_particleCount);
  m_particleState=false;
  emit resetparticlesOnOff(m_particleState);
  m_cloudHeight=15;
  emit resetCloudHeight(m_cloudHeight);
  m_particleProdutionRate=1;
  emit resetParticleProductionRate(m_particleProdutionRate);
  m_particleMoveState=0;
  emit resetParticleMoveState(m_particleMoveState);
  m_particleLifeRange[0]=100;
  emit resetParticleTimeRangeMin(m_particleLifeRange[0]);
  m_particleLifeRange[1]=170;
  emit resetParticleTimeRangeMax(m_particleLifeRange[1]);

}
//----------------------------------------------------------------------------------------------------------------------
std::vector<ngl::Vec3> Tornado::getParticleSysList()
{
    return m_storeParticleSysList;
}
//----------------------------------------------------------------------------------------------------------------------
std::vector<ngl::Vec3> Tornado::getParticleList()
{
    return m_storeParticlePos;
}
//----------------------------------------------------------------------------------------------------------------------
int Tornado::getParticleSysCount()
{
    return m_particleSystemCount;
}
//----------------------------------------------------------------------------------------------------------------------
int Tornado::getFullParticleCount()
{

    return m_storeParticlePos.size();
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//public slots
void Tornado::particlesOnOff(bool _state=0)
{
    if (_state==true){m_particleState=m_particleCount;}
    else if (_state==false){m_particleState=0;}

    for(int i =0;i<(int)m_storeParticleSysList.size();++i)
    {

      m_particleSystemList[i]->setParticles(m_particleState);

    }
}
void Tornado::setParticleCount(int _value)
{

  m_particleCount=_value;
  if(m_particleState>0)
  {
   m_particleState=m_particleCount;
  for(int i =0;i<(int)m_storeParticleSysList.size();++i)
  {

    m_particleSystemList[i]->setParticles(m_particleState);

  }
  }
}
void Tornado::setHeight(int _value)
{
    m_maxHeight=_value;
}
void Tornado::setRadiusMin(double _value)
{

  m_radiusRange[0]=_value;
}
void Tornado::setRadiusMax(double _value)
{
  m_radiusRange[1]=_value;
}
void Tornado::setCloudHeight(int _value)
{
  m_cloudHeight=_value;

  for(int i =0;i<(int)m_particleSystemList.size();++i)
  {

    m_particleSystemList[i]->setCloudHeight(_value);

  }

}
void Tornado::setParticleMoveState(int _value)
{


  m_particleMoveState=_value;
}
void Tornado::setParticleTimeRangeMin(int _value)
{
  m_particleLifeRange[0]=_value;
  for(int i =0;i<(int)m_particleSystemList.size();++i)
  {

    m_particleSystemList[i]->setlifeTimeRange(_value,0);

  }
}
void Tornado::setParticleTimeRangeMax(int _changeValue)
{
  m_particleLifeRange[1]=_changeValue;
  for(int i =0;i<(int)m_particleSystemList.size();++i)
  {

    m_particleSystemList[i]->setlifeTimeRange(_changeValue,1);

  }
}
void Tornado::setParticleSysTreshold(int _value)
{
  m_particleSystemTreshold=_value;
}
void Tornado::setProductionRate(int _value)
{
  m_maxProductionRate=_value;
}
void Tornado::setParticleProductionRate(int _value)
{
  m_particleProdutionRate=_value;

  for(int i =0;i<(int)m_particleSystemList.size();++i)
  {

    m_particleSystemList[i]->setProductionRate(_value);

  }

}





















