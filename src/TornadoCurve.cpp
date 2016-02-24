#include "TornadoCurve.h"
#include <iostream>
#include <math.h>
TornadoCurve::TornadoCurve(int _changeRate,float* _allcontrolPoints[3])
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
    m_curveCount=2;
    m_minHeight=0.0;
    m_maxHeight=40.0;
    m_timeUp=40; // needs to be calculated when actually using the curves
    m_midPoint[0]=0;
    m_midPoint[1]=0;
    m_midPoint[2]=0;
}



void TornadoCurve::guideCurve(int _particleTime,float _controlPoint[],int _position,int _curveNum)
{
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


    m_curveResult[_curveNum][_position] = m_minHeight * (pow((1.0-t), 2.0)) + _controlPoint[_position] * (2.0 * t * (1.0-t)) + m_maxHeight * (pow(t,2.0));

    //std::cout<< "curve"<<_curveNum<<": "<< m_curveResult[_curveNum][_position]<< (_position < 2 ? "," : "\n");
    //V=V1(1-t)^2+Vc2t(1-t)+v2*t^2


}


void TornadoCurve::interpolate(int _frame,int _particleTime)
{

    int curveResultTrack=0;

//        for(int i=0;i<=1;i++)
//        {
            if (_frame % (int)m_changeRate == 0)
            {
                m_tracker++;
                m_tracker %= (int)m_curveCount;

            }
            for(int j=0; j<=2;j++)
            {
                guideCurve(_particleTime,m_controlPoints[m_tracker],j,0);
                guideCurve(_particleTime,m_controlPoints[(m_tracker+1)%(int)m_curveCount],j,1);
//                //std::cout<<"m_tracker"<<m_tracker<<std::endl;
//                if(m_tracker<=1)
//                {
//                guideCurve(_particleTime,m_controlPoints[m_tracker+i],j,curveResultTrack);
//                }
//                else
//                {
//                guideCurve(_particleTime,m_controlPoints[m_tracker-i],j,curveResultTrack);
//                }
            }
//            //gives you position on curve equations
//            curveResultTrack++;
//        }
//    std::cout << "Frame " << _frame << " curves: " << m_tracker << ", " << (m_tracker+1)%(int)m_curveCount << "\n";


        // interpolate between position that the curve function return

         float t = (float)(_frame%(int)m_changeRate)/(float)m_changeRate;
         //std::cout<<"t:"<<t<<std::endl;
         //t=0;
         for(int i=0;i<=2;i++)
        {
            m_midPoint[i] = (m_curveResult[0][i] * pow((1-t),2.0)) + 2*t*(1-t) + (m_curveResult[1][i] * pow(t,2.0));
            //m_midPoint[i] = (m_curveResult[0][i] * pow(cos(t),2.0)) + (m_curveResult[1][i] * pow(sin(t),2.0) );
           //m_midPoint[i] = (m_curveResult[0][i]*(1.0-t))+(m_curveResult[1][i]*t); // figure out what t is
           //V=V1 cos^2(1) +V2 sin^2 (t)
            //V=v1(1-t)^2 + 2t(1-t) + v2 t^2
           std::cout << m_midPoint[i] << (i < 2 ? "," : "\n");
        }


}


void TornadoCurve::spiral(int _radius,int _particleTime)
{

    m_resultPoint[0]= (float)m_midPoint[0]+(float) _radius * ((float)_particleTime+20) *  (1.0/2.0)*sin ((float)_particleTime/3.0);
    m_resultPoint[1]= (float)m_midPoint[1]+(float)_radius * ((float)_particleTime+20) *  (1.0/2.0)*cos ((float)_particleTime/3.0);
    //m_resultPoint[2]= (float) m_midPoint[2]+  (float)_particleTime;
    m_resultPoint[2]= (float)_particleTime;
    //std::cout<<"ppointe"<<m_midPoint[2]<< std::endl;
}


void TornadoCurve::printPoint()
{
    //std::cout<< (int)m_resultPoint[0] <<","<< (int)m_resultPoint[1]<<","<< (int)m_resultPoint[2] <<";"<< std::endl;
    //std::cout<< (int)m_midPoint[0] <<","<< (int)m_midPoint[1]<<","<< (int)m_midPoint[2] <<";"<< std::endl;
}


