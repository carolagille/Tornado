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



            m_particleSystemList.push_back(std::unique_ptr<ParticleSystem>(new ParticleSystem(radius,offset,m_particleState)));

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

        m_storeParticleSysList.push_back(point);
        //m_storeParticleSysList.push_back((10.0f,10.0f,10.0f));
        m_storeParticlePos = m_particleSystemList[i]->move(point,m_storeParticlePos,center);
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

void Tornado::save()
{

}

void Tornado::setHeight(int _changeValue)
{
    m_maxHeight=_changeValue;
}
int Tornado::getFullParticleCount()
{

    return m_storeParticlePos.size();
}
void Tornado::particlesOnOff(bool state=0)
{
    if (state==true){m_particleState=m_particleCount;}
    else if (state==false){m_particleState=0;}

    for(int i =0;i<(int)m_storeParticleSysList.size();++i)
    {

      m_particleSystemList[i]->switchParticles(m_particleState);

    }
}
void Tornado::changeParticleCount(int value)
{
  m_particleCount=value;
  if(m_particleState>0)
  {
   m_particleState=m_particleCount;
  for(int i =0;i<(int)m_storeParticleSysList.size();++i)
  {

    m_particleSystemList[i]->switchParticles(m_particleState);

  }
  }
}

void Tornado::setRadiusMin(double _changeValue)
{
  std::cout<<"changing Radius\n";
  m_radiusRange[0]=_changeValue;
}
void Tornado::setRadiusMax(double _changeValue)
{
  m_radiusRange[1]=_changeValue;
}

void Tornado::restart()
{

  m_particleSystemList.clear();
  m_particleCount=1;
  m_particleSystemCount=0;

  m_frame=0;
  m_storeParticleSysList.clear();

  createParticleSystem();
  m_storeParticlePos.clear();


  m_frame=0;
  m_particleSystemTreshold=20000;
  m_maxProductionRate=2;

  m_radiusRange[0]=4.0;
  m_radiusRange[1]=8.0;
  m_maxHeight=400;
  m_radiusChange=10.0;
  m_radiusDiffrence=2;
  m_particleCount=1;
  m_particleState=0;
}
