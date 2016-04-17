#include "ParticleSystem.h"
#include "Particle.h"
#include "TornadoCurve.h"
#include "Tornado.h"


ParticleSystem::ParticleSystem():
m_offset(0),
m_radius(5)
{   // Default constructor
    //std::cout<<"ParticleSystem created\n";

    m_boundingBox = 100.0; //radius of a sphere soroundig the particle
    m_position =ngl::Vec3 (0.0f,0.0f,0.0f);
    m_age = 0;



    m_particleTreshold=1;

    m_maxProductionRate=1;
    m_particleCount=0;

    m_cloudHeight=15;
    m_lifeTimeRange =ngl::Vec2 (100,170);
    createParticles();

}

ParticleSystem::ParticleSystem(float _radius, float _offset, int _treshold, int _cloudHeight, int _productionRate, int _lifetimeRange[2]):
m_offset(_offset),
m_radius(_radius)
{
    //Particle System Constructor with inputs
    //Inputs are used to create individual result for the particle system path
    //std::cout<<"ParticleSystem created\n";
    m_boundingBox = 10; //radius of a sphere soroundig the particle

    m_position =ngl::Vec3 (0.0f,0.0f,0.0f);

    m_age = 0;

    m_cloudHeight=_cloudHeight;
    m_lifeTimeRange=ngl::Vec2(_lifetimeRange[0],_lifetimeRange[1]);
    m_particleTreshold=_treshold;
    m_maxProductionRate=_productionRate;
    m_particleCount=0;

    createParticles();
}

ParticleSystem::~ParticleSystem()
{
  //std::cout<<"Destructor Particle System called"<<std::endl;


}

void ParticleSystem::createParticles()
{
    if (m_particleCount < m_particleTreshold)
    {
        int diffrence=m_particleTreshold - m_particleCount;
        for (int i=0; i<diffrence;i++)
        {

            //for now particles created at the origin

            m_particleList.push_back(std::unique_ptr<Particle>(new Particle(m_position,m_boundingBox,m_lifeTimeRange)));

            m_particleCount++;
            if (m_particleCount >= m_particleTreshold){return;}


        }
    }
}

void ParticleSystem::move(ngl::Vec3 _position, std::vector<ngl::Vec3>* _particlePosList, ngl::Vec3 _center, int _particleMoveState)
{

    createParticles();
    for (int i=0;i<m_particleCount;i++)
    {
      if(_particleMoveState==0)
      {
        m_particleList[i]->move(_position,m_position,m_boundingBox,_center);
      }
      else
      {
        m_particleList[i]->move(_position,m_boundingBox);
       }
        //m_particleList[i]->move(ngl::Vec3(30.0,0.0,0.0),ngl::Vec3(30.0,0.0,0.0),m_boundingBox,ngl::Vec3(0.0,0.0,0.0));

        ngl::Vec3 position(m_particleList[i]->getPoints());
        //std::cout<<"position:"<< position[0]<<position[1]<<position[2]<<"\n";
        _particlePosList->push_back(position);
        //std::cout<<"listSIze"<<_particlePos.size()<<"\n";

        int out=m_particleList[i]->checkLife();
        if (out==1)
        {

           m_particleList.erase(m_particleList.begin()+i);
           m_particleCount--;
        }
        if (m_particleTreshold==0)
        {

          m_particleList.clear();
          m_particleCount=0;
        }
    }

    m_position[0]= _position[0];
    m_position[1]= _position[1];
    m_position[2]= _position[2];

    //insert Curve function stuff here
    m_age++;

}


int ParticleSystem::checkKill(float _maxHeight)
{
    if((m_position[2]-m_cloudHeight) >= _maxHeight)
    {
        return 1;
    }
    else {return 0;}
}

int ParticleSystem::getAge()
{
    return m_age;
}

int ParticleSystem::getParticleCount()
{
    return m_particleCount;
}
void ParticleSystem::setParticles(int _value)
{
  std::cout<<"particle count"<<m_particleTreshold<<std::endl;
    m_particleTreshold=_value;

}
void ParticleSystem::setCloudHeight(int _value)
{
  m_cloudHeight=_value;
}

void ParticleSystem::setlifeTimeRange(int _value, int _minMax)
{
  m_lifeTimeRange[_minMax]=_value;
}

void ParticleSystem::setProductionRate(int _value)
{
  m_maxProductionRate=_value;
}
