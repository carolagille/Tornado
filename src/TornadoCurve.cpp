#include "TornadoCurve.h"
#include <iostream>
#include <math.h>


TornadoCurve::TornadoCurve(int _changeRate)
{


    m_changeRate = _changeRate;


    m_curveResult[0]=(0);
    m_curveResult[1]=(0);

    m_tracker=0;
    m_resultPoint=(0.0f);
    m_curveCount=3;


    m_maxHeight=ngl::Vec3(0.0f,0.0f,400);
    m_speed=2;

    m_speedUp=2;

    m_timeUp=m_maxHeight[2]*m_speedUp; // needs to be calculated when actually using the curves
    m_midPoint=(0.0f);
    m_frame=0;


    m_controlPoints[0]=ngl::Vec3(130.0f,10.0f,(float)m_maxHeight[2]/2.0);
    m_controlPoints[1]=ngl::Vec3(-70.0f,-50.0f,(float)(m_maxHeight[2]/2.0));
    m_controlPoints[2]=ngl::Vec3(50.0f,100.0f,(float)(m_maxHeight[2]/2.0));

    m_radiusGrowth=55.0;
    m_pickUpTime=100;
    m_pickUpRadius=10.0;
    m_startValue=2;
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


    m_curveResult[_curveNum][_position] = 0 * (pow((1.0-t), 2.0)) + _controlPoint[_position] * (2.0 * t * (1.0-t)) + m_maxHeight[_position] * (pow(t,2.0));

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
      //std::cout<<t<<"\n";
      float origin=(float)m_midPoint[0]+(float)_radius * m_pickUpRadius *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
      float normal=(float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);

      m_resultPoint[0]=(1-t)*origin+(t)*normal;
      //m_resultPoint[0]=0.9*origin+0.1*normal;
      origin=(float)m_midPoint[1]+(float)_radius * m_pickUpRadius *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
      normal=(float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);



      m_resultPoint[1]=(1-t)*origin+(t)*normal;
      m_resultPoint[2]= (float)_particleTime/m_speedUp ;

    }
    else if(_particleTime<m_timeUp)
      {
        interpolate(_particleTime);
        m_resultPoint[0]= (float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/2.0)*sin (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0)))+ _offset);
        m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/2.0)*cos (((float)_particleTime/(10.0/m_speed*(1.0/_particleTime/10.0))) + _offset);

        m_resultPoint[2]= (float)_particleTime/m_speedUp ;
    }
    else
    {
        interpolate(m_timeUp);
        m_resultPoint[0]= (float)m_midPoint[0]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/(float)m_speed)*sin (((float)_particleTime/10.0)+ _offset);
        m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime/m_radiusGrowth+m_startValue) *  (1.0/(float)m_speed)*cos (((float)_particleTime/10.0) + _offset);
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

void TornadoCurve::setSpeedUp(double _value)
{
    m_speedUp=_value;

    m_timeUp=m_maxHeight[2]*m_speedUp;
}
void TornadoCurve::changeSpeed(float _changeValue)
{
    m_speed+=_changeValue;
    if (m_speed<=0){m_speed=0.1;}

    m_timeUp=m_maxHeight[2]*m_speedUp;
}

void TornadoCurve::setHeight(int _value)
{
    m_maxHeight[2]=(float)_value;
    std::cout<<"Height"<<m_maxHeight[2]<<"\n";
    m_timeUp=m_maxHeight[2]*m_speedUp;
}
void TornadoCurve::setControllPoint1X(int _value)
{
  m_controlPoints[0][0]=_value;
  std::cout<<"changing controll point\n";

}
void TornadoCurve::setControllPoint1Z(int _value)
{
  m_controlPoints[0][1]=_value;

}
void TornadoCurve::setControllPoint2X(int _value)
{
  m_controlPoints[1][0]=_value;

}
void TornadoCurve::setControllPoint2Z(int _value)
{
  m_controlPoints[1][1]=_value;

}
void TornadoCurve::setControllPoint3X(int _value)
{
  m_controlPoints[2][0]=_value;

}
void TornadoCurve::setControllPoint3Z(int _value)
{
  m_controlPoints[2][1]=_value;

}

void TornadoCurve::setCurveCount(int _value)
{
  m_curveCount=_value;
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
void TornadoCurve::setPickUpRadius(double _value)
{
  m_pickUpRadius= _value;

}

void TornadoCurve::setPickUpTime(int _value)
{
  m_pickUpTime=_value;
}

void TornadoCurve::setStartValue(int _value)
{

  m_startValue=_value;
}
void TornadoCurve::setRadiusGrowth(double _value)
{
  m_radiusGrowth=_value;
}


void TornadoCurve::reset()
{
  m_curveCount=3;
  emit resetCurveCount(m_curveCount);

  m_controlPoints[0]=ngl::Vec3(130.0f,10.0f,(float)m_maxHeight[2]/2.0);
  emit resetControllPoint1X(m_controlPoints[0][0]);
  emit resetControllPoint1Z(m_controlPoints[0][1]);

  m_controlPoints[1]=ngl::Vec3(-70.0f,-50.0f,(float)(m_maxHeight[2]/2.0));
  emit resetControllPoint2X(m_controlPoints[1][0]);
  emit resetControllPoint2Z(m_controlPoints[1][1]);

  m_controlPoints[2]=ngl::Vec3(50.0f,100.0f,(float)(m_maxHeight[2]/2.0));
  emit resetControllPoint3X(m_controlPoints[2][0]);
  emit resetControllPoint3Z(m_controlPoints[2][1]);

  m_maxHeight[2]=400;
  emit resetHeight(m_maxHeight[2]);

  m_pickUpTime=100;
  emit resetPickUpTime(m_pickUpTime);
  m_pickUpRadius=10.0;
  emit resetPickUpRadius(m_pickUpRadius);

  m_startValue=2;
  emit resetStartValue(m_startValue);

  m_speedUp=2;
  emit resetSpeedUp(m_speedUp);

  m_radiusGrowth=55.0;
  emit resetRadiusGrowth(m_radiusGrowth);

}
