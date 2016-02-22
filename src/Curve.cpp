#include "Curve.h"


TornadoCurve::TornadoCurve(int _changeRate,int _controllPoints[3][3] )


void TorndoCurve::guideCurve(int _particleTime,int _controllPoint)
{
    float t = (float)_partcielTime/(float)m_timeUp;
    m_resultPoint = m_minHeight*((t-1)**2)+ _controllPoint * (2*t(1-t)) +m_maxHeight*(t**2);
    //new line
}
