#include "TornadoCurve.h"
#include <iostream>
#include <math.h>
#include <ngl/Vec3.h>
TornadoCurve::TornadoCurve() //Default Constructor
{

    m_changeRate = 10;

    m_curveResult[0]=(0.0f);
    m_curveResult[1]=(0.0f);

    m_tracker=0;
    m_resultPoint=ngl::Vec3(0.0f,0.0f,0.0f);

    m_curveCount=2;
    m_minHeight=0.0;
    m_maxHeight=ngl::Vec3(0.0f,0.0f,200.0f);
    m_timeUp=400; // needs to be calculated when actually using the curves
    m_midPoint=(0.0f);
    m_frame=0;

    m_controlPoints[0]=(100.0f);
    m_controlPoints[1]=(100.0f);
    m_controlPoints[0]=ngl::Vec3(100.0f,100.0f,(float)(m_maxHeight[2]/2.0));


}

TornadoCurve::TornadoCurve(int _changeRate, ngl::Vec3 _allcontrolPoints[], float _maxHeight)
{

    m_changeRate = _changeRate;

    m_curveResult[0]=(0);
    m_curveResult[1]=(0);

    m_tracker=0;
    m_resultPoint=(0.0f);
    m_curveCount=2;
    m_minHeight=0.0;

    m_maxHeight=ngl::Vec3(0.0f,0.0f,_maxHeight);
    std::cout<<"m_maxHeight"<<m_maxHeight[0]<<","<<m_maxHeight[1]<<","<<m_maxHeight[2]<<"\n";
    m_timeUp=400; // needs to be calculated when actually using the curves
    m_midPoint=(0.0f);
    m_frame=0;


    m_controlPoints[0]=ngl::Vec3(_allcontrolPoints[0][0],_allcontrolPoints[0][1],(float)(m_maxHeight[2]/2.0));
    m_controlPoints[1]=ngl::Vec3(_allcontrolPoints[1][0],_allcontrolPoints[1][1],(float)(m_maxHeight[2]/2.0));
    m_controlPoints[2]=ngl::Vec3(_allcontrolPoints[2][0],_allcontrolPoints[2][1],(float)(m_maxHeight[2]/2.0));



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

    //std::cout<<_position<<"\n";
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
    interpolate(_particleTime);
    m_resultPoint[0]= (float)m_midPoint[0]+(float)_radius * ((float)_particleTime/10.0+10) *  (1.0/5.0)*sin (((float)_particleTime/3.0)+ _offset);
    m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime/10.0+10) *  (1.0/5.0)*cos (((float)_particleTime/3.0) + _offset);
    m_resultPoint[2]= (float)_particleTime/4;
    //printPoint();
}


void TornadoCurve::printPoint()
{
    std::cout<< m_resultPoint[0] <<","<< m_resultPoint[1]<<","<< m_resultPoint[2] <<";"<< std::endl;
    //std::cout<< m_midPoint[0] <<","<< m_midPoint[1]<<","<< m_midPoint[2] <<";"<< std::endl;
    //std::cout<<"curve1"<< m_curveResult[0][0] <<","<< (int)m_curveResult[0][1]<<","<< (int)m_curveResult[0][2] <<";"<< std::endl;
    //std::cout<<"curve2"<< m_curveResult[1][0] <<","<< (int)m_curveResult[1][1]<<","<< (int)m_curveResult[1][2] <<";"<< std::endl;
}


ngl::Vec3 TornadoCurve::getPoint()
{
     ngl::Vec3 _destination=(m_resultPoint);
     return _destination;

}
