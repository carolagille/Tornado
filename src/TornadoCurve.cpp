#include "TornadoCurve.h"
#include <iostream>
#include <math.h>
TornadoCurve::TornadoCurve(int _changeRate,int* _allcontrolPoints[3])
{
    m_changeRate = _changeRate;
    for(int i=0; i<=2;i++)
    {
        for(int j=0; j<=2;j++)
        {
            m_controlPoints[i][j]= _allcontrolPoints[i][j];
        }
    }
    for(int i=0; i<=1;i++)
    {
        for(int j=0; j<=2;j++)
        {
            m_curveResult[i][j]= 0;

        }
    }
    m_tracker=0;
    m_resultPoint[0]=0; //improve later
    m_resultPoint[1]=0;
    m_resultPoint[2]=0;
    m_curveCount=3;
    m_minHeight=0;
    m_maxHeight=10;
    m_timeUp=20; // needs to be calculated when actually using the curves
    m_midPoint[0]=0;
    m_midPoint[1]=0;
    m_midPoint[2]=0;
}



void TornadoCurve::guideCurve(int _particleTime,int _controlPoint[],int _position,int _curveNum)
{
    float t;

    float procent=(float)( _particleTime % m_changeRate);
    if(procent!=0)
    {
        t = procent/(float)m_changeRate ;
    }
    else
    {
        t=0;
    }

    //std::cout<< "controlPoint"<< _controlPoint[_position]<< std::endl;
    m_curveResult[_curveNum][_position] = m_minHeight*(pow((t-1.0), 2.0)) + _controlPoint[_position] * (2.0 * (1.0-t)) + m_maxHeight * (pow(t,2.0));
    //V=V1(1-t)^2+Vc2t(1-t)+v2*t^2
    //std::cout<<"result: "<<m_curveResult[_curveNum][_position]<<std::endl;
}


void TornadoCurve::interpolate(int _frame,int _particleTime)
{

    int curveResultTrack=0;

        for(int i=0;i<=1;i++)
        {
            if (_frame % m_changeRate == 0)
            {
                m_tracker++;
                m_tracker %= m_curveCount;

            }
            for(int j=0; j<=2;j++)
            {
                //std::cout<<"m_tracker"<<m_tracker<<std::endl;
                if(m_tracker<=1)
                {
                guideCurve(_particleTime,m_controlPoints[m_tracker+i],j,curveResultTrack);
                }
                else
                {
                guideCurve(_particleTime,m_controlPoints[m_tracker-i],j,curveResultTrack);
                }
            }
            curveResultTrack++;
            //gives you position on curve equations

        }



        // interpolate between position that the curve function return

         //float t = (float)_particleTime/(float)m_timeUp;
         float t=1;
         for(int i=0;i<=2;i++)
        {
           m_midPoint[i] = (m_curveResult[1][i]*t)-(m_curveResult[0][i]*(t-1)); // figure out what t is

        }


}


void TornadoCurve::spiral(int _radius,int _particleTime)
{

    m_resultPoint[0]= m_midPoint[0]+_radius * (_particleTime+20) * (1.0/20.0) * sin (_particleTime);
    m_resultPoint[1]= m_midPoint[1]+_radius * (_particleTime+20) * (1.0/20.0) * cos (_particleTime);
    m_resultPoint[2]= m_midPoint[2]+(1.0/2.0) * _particleTime;
    //std::cout<<"particleTime"<<_particleTime<< std::endl;
}


void TornadoCurve::printPoint()
{
    std::cout<< (int)m_resultPoint[0] <<","<< (int)m_resultPoint[1]<<","<< (int)m_resultPoint[2] <<";"<< std::endl;

}


