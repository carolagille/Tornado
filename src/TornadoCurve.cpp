#include "TornadoCurve.h"
#include <iostream>
#include <math.h>

TornadoCurve::TornadoCurve() //Default Constructor
{
  std::cout << "default constructor" << std::endl;
    m_changeRate = 10000;

    m_curveResult[0]=(0.0f);
    m_curveResult[1]=(0.0f);

    m_tracker=0;
    m_resultPoint=ngl::Vec3(0.0f,0.0f,0.0f);

    m_curveCount=3;
    m_minHeight=0.0;
    m_maxHeight=ngl::Vec3(0.0f,0.0f,200.0f);
     // needs to be calculated when actually using the curves
    m_midPoint=(0.0f);
    m_frame=0;

    m_controlPoints[0]=(100.0f);
    m_controlPoints[1]=(100.0f);
    m_controlPoints[2]=ngl::Vec3(100.0f,100.0f,(float)(m_maxHeight[2]/2.0));
    m_speed=5;
    m_speedUp=5;
    m_timeUp=m_maxHeight[2]*m_speed;
    m_radiusGrowth=75.0;
    m_pickUpTime=100;
    m_pickUpRadius=10.0;
}

TornadoCurve::TornadoCurve(int _changeRate, ngl::Vec3 _allcontrolPoints[], float _maxHeight)
{

    m_changeRate = _changeRate;


    m_curveResult[0]=(0);
    m_curveResult[1]=(0);

    m_tracker=0;
    m_resultPoint=(0.0f);
    m_curveCount=3;
    m_minHeight=0.0;

    m_maxHeight=ngl::Vec3(0.0f,0.0f,_maxHeight);
    m_speed=2;
    m_speedUp=2;

    m_timeUp=_maxHeight*m_speedUp; // needs to be calculated when actually using the curves
    m_midPoint=(0.0f);
    m_frame=0;


    m_controlPoints[0]=ngl::Vec3(_allcontrolPoints[0][0],_allcontrolPoints[0][1],(float)(m_maxHeight[2]/2.0));
    m_controlPoints[1]=ngl::Vec3(_allcontrolPoints[1][0],_allcontrolPoints[1][1],(float)(m_maxHeight[2]/2.0));
    m_controlPoints[2]=ngl::Vec3(_allcontrolPoints[2][0],_allcontrolPoints[2][1],(float)(m_maxHeight[2]/2.0));

    m_radiusGrowth=55.0;
    m_pickUpTime=100;
    m_pickUpRadius=10.0;
}


void TornadoCurve::guideCurve(int _particleTime, ngl::Vec3 _controlPoint, int _position, int _curveNum)
{ // this function calculates a points by interpolating between a minumum and maximum height in respect to a control point
    float t;
    //t=0;
    if(_particleTime==0)
    {
        t=0;
    }
    else
    {
        t=(float)_particleTime/(float)m_timeUp;
    }


    m_curveResult[_curveNum][_position] = m_minHeight * (pow((1.0-t), 2.0)) + _controlPoint[_position] * (2.0 * t * (1.0-t)) + m_maxHeight[_position] * (pow(t,2.0));

    //V=V1(1-t)^2+Vc2t(1-t)+v2*t^2


}

void TornadoCurve::frameChange(int _frame)
{



    if (_frame % (int)m_changeRate == 0)
    {
        m_tracker++;
        m_tracker %= (int)m_curveCount;

    }

    m_frame=_frame;

}

void TornadoCurve::interpolate(int _particleTime)
{



            for(int j=0; j<=2;j++)
            {
                guideCurve(_particleTime,m_controlPoints[m_tracker],j,0);
                guideCurve(_particleTime,m_controlPoints[(m_tracker+1)%(int)m_curveCount],j,1);
//
         float t = (float)(m_frame%(int)m_changeRate)/(float)m_changeRate;

         for(int i=0;i<=2;i++)
        {
            m_midPoint[i] = (m_curveResult[0][i]*((2*pow(t ,3.0))- (3*pow(t ,2.0))+1))+(m_curveResult[1][i]*((-2*pow(t ,3.0)) + (3*pow(t ,2.0)))); //cubic interpolation
            //m_midPoint[i] = (m_curveResult[0][i] * pow(cos(t),2.0)) + (m_curveResult[1][i] * pow(sin(t),2.0) ); //quadratic interpolation
           // m_midPoint[i] = (m_curveResult[0][i]*(1.0-t))+(m_curveResult[1][i]*t); // linear interpolation
        }


}
}


void TornadoCurve::spiral(int _radius, int _particleTime, int _offset)
{

    if((_particleTime<m_pickUpTime)&&(_particleTime>=1))
    {
      float t;
      interpolate(_particleTime);
      if(_particleTime==0)
      {
        t=0;

      }
      else
      {
        t=(float)_particleTime/m_pickUpTime;
      }
      std::cout<<t<<"\n";
      float origin=(float)m_midPoint[0]+(float)_radius * m_pickUpRadius *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
      float normal=(float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);

      m_resultPoint[0]=(1-t)*origin+(t)*normal;
      //m_resultPoint[0]=0.9*origin+0.1*normal;
      origin=(float)m_midPoint[1]+(float)_radius * m_pickUpRadius *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
      normal=(float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);



      m_resultPoint[1]=(1-t)*origin+(t)*normal;
      m_resultPoint[2]= (float)_particleTime/m_speedUp ;
      printPoint();
    }
    else if(_particleTime<m_timeUp)
      {
        interpolate(_particleTime);
        m_resultPoint[0]= (float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
        m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0))) + _offset);

        m_resultPoint[2]= (float)_particleTime/m_speedUp ;
    }
    else
    {
        interpolate(m_timeUp);
        m_resultPoint[0]= (float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/(float)m_speed)*sin (((float)_particleTime/10.0)+ _offset);
        m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+2) *  (1.0/(float)m_speed)*cos (((float)_particleTime/10.0) + _offset);
        //refine this
        m_resultPoint[2]= m_maxHeight[2]+(_particleTime-m_timeUp)/100;
    }
    //printPoint();
}


void TornadoCurve::printPoint()
{
    std::cout<< m_resultPoint[0] <<","<< m_resultPoint[1]<<","<< m_resultPoint[2] <<";"<< std::endl;

}


ngl::Vec3 TornadoCurve::getPoint()
{

     return m_resultPoint;

}
ngl::Vec3 TornadoCurve::getMidPoint()
{
    return m_midPoint;
}

void TornadoCurve::changeRadiusGrowth(float _changeValue)
{
    m_radiusGrowth+=_changeValue;
}

void TornadoCurve::changeSpeedUp(float _changeValue)
{
    m_speedUp+=_changeValue;
    if (m_speedUp<=0){m_speedUp=0.1;}

    m_timeUp=m_maxHeight[2]*m_speedUp;
}
void TornadoCurve::changeSpeed(float _changeValue)
{
    m_speed+=_changeValue;
    if (m_speed<=0){m_speed=0.1;}

    m_timeUp=m_maxHeight[2]*m_speed;
}

void TornadoCurve::setHeight(float _changeValue)
{
    m_maxHeight[2]=_changeValue;
    m_timeUp=m_maxHeight[2]*m_speedUp;
}
void TornadoCurve::setControllPoint1X(int _changeValue)
{
  m_controlPoints[0][0]=_changeValue;
  std::cout<<"changing controll point\n";

}
void TornadoCurve::setControllPoint1Z(int _changeValue)
{
  m_controlPoints[0][1]=_changeValue;

}
void TornadoCurve::setControllPoint2X(int _changeValue)
{
  m_controlPoints[1][0]=_changeValue;

}
void TornadoCurve::setControllPoint2Z(int _changeValue)
{
  m_controlPoints[1][1]=_changeValue;

}
void TornadoCurve::setControllPoint3X(int _changeValue)
{
  m_controlPoints[2][0]=_changeValue;

}
void TornadoCurve::setControllPoint3Z(int _changeValue)
{
  m_controlPoints[2][1]=_changeValue;

}

void TornadoCurve::setCurveCount(int _changeValue)
{
  m_curveCount=_changeValue;
  if(m_curveCount==2)
  {
    emit disableCurve3(false);

    emit disableCurve2(true);
  }
  else if(m_curveCount==1)
  {
    emit disableCurve3(false);
    emit disableCurve2(false);
  }
  else
  {
    emit disableCurve3(true);
    emit disableCurve2(true);
  }

}
void TornadoCurve::setPickUpRadius(double _changeValue)
{
  m_pickUpRadius= _changeValue;

}

void TornadoCurve::setPickUpTime(int _changeValue)
{
  m_pickUpTime=_changeValue;
}
