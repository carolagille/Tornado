#include "Tornado.h"
#include "ParticleSystem.h"
#include "TornadoCurve.h"
#include <math.h>

Tornado::Tornado(TornadoCurve *_curve)

{
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


    //m_particleSystemList = std::vector<ParticleSystem*> ();
    std::cout<< "Tornado created\n";
    createParticleSystem();

}

Tornado::~Tornado()
{

}

void Tornado::createParticleSystem()
{
    if (m_particleSystemCount < m_particleSystemTreshold)
    {
        if(m_frame%50==0)
        {
        std::random_device rd2;
        std::mt19937_64 gen(rd2());

        std::uniform_int_distribution<int> distribution2(10,100);
        m_radiusChange = (float)distribution2(gen);

        std::uniform_int_distribution<int> distribution3(2,4);
        m_radiusDiffrence=distribution3(gen);
        }
        int diffrence=m_particleSystemTreshold - m_particleSystemCount;
        for (int i=0; i<diffrence;i++)
        {
            std::random_device rd;
            std::mt19937_64 gen(rd());

            std::uniform_real_distribution<float> distribution(m_radiusRange[0],m_radiusRange[1]);
            float radius = distribution(gen);
            //std::cout<<"radius"<<radius<<"\n";

            radius+= sqrt(pow((m_radiusDiffrence*sin((1.0/m_radiusChange)*(float)m_frame)),2));

            std::uniform_real_distribution<float> distribution1(0.0,10.0);
            float offset = distribution1(gen);



            m_particleSystemList.push_back(std::unique_ptr<ParticleSystem>(new ParticleSystem(radius,offset,m_particleState,m_cloudHeight,m_particleProdutionRate,m_particleLifeRange)));

            std::vector<ngl::Vec3> particlePoint;

            m_particleSystemCount++;

            if (m_particleSystemCount >= m_particleSystemTreshold){ return;}
            if (i >= m_maxProductionRate){return;}

        }
    }


}

void Tornado::update()
{

    m_storeParticleSysList.clear();
    m_storeParticlePos.clear();



    ngl::Vec3 center;



    m_curve->frameChange(m_frame);


    createParticleSystem();


    for (int i=0;i<m_particleSystemCount;i++)
    {


        int particleAge = m_particleSystemList[i]->getAge();

        m_curve->spiral(m_particleSystemList[i]->m_radius,particleAge, m_particleSystemList[i]->m_offset);
        ngl::Vec3 point = m_curve->getPoint();
        //point=ngl::Vec3(30.0f,0.0f,0.0f);
        center= m_curve->getMidPoint();
        m_storeParticleSysList.push_back(point);
        //m_storeParticleSysList.push_back((10.0f,10.0f,10.0f));
        m_particleSystemList[i]->move(point,&m_storeParticlePos,center,m_particleMoveState);
        int out=m_particleSystemList[i]->checkKill(m_maxHeight);
        if (out==1)
        {
           m_particleSystemList.erase(m_particleSystemList.begin()+i);
           m_particleSystemCount--;
        }
    }
    m_frame++;
}

void Tornado::printList()
{
    for(int i =0;i<(int)m_storeParticleSysList.size();++i)
    {

            std::cout<<m_storeParticleSysList[i].m_x<< "," <<m_storeParticleSysList[i].m_y<<","  <<m_storeParticleSysList[i].m_z<<";\n";

    }
}
std::vector<ngl::Vec3> Tornado::getParticleSysList()
{
    return m_storeParticleSysList;
}

std::vector<ngl::Vec3> Tornado::getParticleList()
{
    return m_storeParticlePos;
}

int Tornado::getParticleSysCount()
{
    return m_particleSystemCount;
}



void Tornado::setHeight(int _value)
{
    m_maxHeight=_value;
}
int Tornado::getFullParticleCount()
{

    return m_storeParticlePos.size();
}
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
  std::cout<<"changing particles\n";
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

void Tornado::setRadiusMin(double _value)
{
  std::cout<<"changing Radius\n";
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
  std::cout<<_value<<"\n";

  m_particleMoveState=_value;
}
void Tornado::setParticleProductionRate(int _value)
{
  m_particleProdutionRate=_value;

  for(int i =0;i<(int)m_particleSystemList.size();++i)
  {

    m_particleSystemList[i]->setProductionRate(_value);

  }

}

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
