#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__
#include <ngl/Vec3.h>
class TornadoCurve
{
 public:
    TornadoCurve();
     TornadoCurve(int _changeRate, ngl::Vec3 _controlPoint[3], float _maxHeight);
     void guideCurve(int _particleTime, ngl::Vec3 _controlPoint, int _position, int _curveNum); // make this a class????, creates guide curves by interpolating between start and end and a control curve
     void interpolate(int _particleTime);//interpolates between the diffrent guide curves
     void spiral (int _radius, int _particleTime, int _offset);// using the interpolating result this creates a spiral
     void printPoint(); // prints out the point on the curve
     ngl::Vec3 getPoint();
     void frameChange(int _frame);
     void changeRadiusGrowth(float _changeValue);
     void changeSpeedUp(float _changeValue);
     void changeMaxHeight(float _changeValue);
     ngl::Vec3 getMidPoint();

private:
    float m_offset;
    float m_changeRate; //how often it should swtichen between the guide curves
    ngl::Vec3 m_controlPoints[3]; //control points that are stored int a list, they are used to create the guide curves
    int m_tracker; // this keeps track of the curve thats active
    ngl::Vec3 m_resultPoint; // this point is the point calculated by the whole tornado curve class and represents the point where the particle should be
    float m_curveCount; // represents the amount of guid curves used
    float m_minHeight; // minumum height for the guide curve maybe make this a vector
    ngl::Vec3 m_maxHeight; // max height for the guide curve maybe make this a vector so that it represetn an end point
    float m_timeUp; // represents how long it takes the particle to reach the max height can also be used as lifetime of particle
    ngl::Vec3 m_midPoint; // stores the midpoint calculated by the interpolation function by interpolating between two guide curve points
    ngl::Vec3 m_curveResult[2]; // stores the two results from the guide curve calculation as there are only two that need to be used
    int m_frame;
    float m_speed;
    float m_radiusGrowth;
    float m_speedUp;
};





#endif 
