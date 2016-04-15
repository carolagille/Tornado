#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__
#include <ngl/Vec3.h>
#include <QObject>
class TornadoCurve:public QObject
{Q_OBJECT
 public slots:
    void setHeight(int _changeValue);
    void setControllPoint1X(int _changeValue);
    void setControllPoint1Z(int _changeValue);
    void setControllPoint2X(int _changeValue);
    void setControllPoint2Z(int _changeValue);
    void setControllPoint3X(int _changeValue);
    void setControllPoint3Z(int _changeValue);
    void setCurveCount(int _changeValue);
    void setPickUpRadius(double _changeValue);
    void setPickUpTime(int _changeValue);
    void setStartValue(int _changeValue);
    void setSpeedUp(double _changeValue);
    void reset();
    void setRadiusGrowth(double _changeValue);


 signals:
    void disableCurve2(bool _state);
    void disableCurve3(bool _state);
    void resetCurveCount(int _value);
    void resetControllPoint1X(int _value);
    void resetControllPoint1Z(int _value);
    void resetControllPoint2X(int _value);
    void resetControllPoint2Z(int _value);
    void resetControllPoint3X(int _value);
    void resetControllPoint3Z(int _value);
    void resetHeight(int _value);
    void resetPickUpRadius(double _changeValue);
    void resetPickUpTime(int _changeValue);
    void resetStartValue(int _changeValue);
    void resetSpeedUp(double _changeValue);
    void resetRadiusGrowth(double _changeValue);


 public:
     TornadoCurve(int _changeRate);
     void guideCurve(int _particleTime, ngl::Vec3 _controlPoint, int _position, int _curveNum); // make this a class????, creates guide curves by interpolating between start and end and a control curve
     void interpolate(int _particleTime);//interpolates between the diffrent guide curves
     void spiral (int _radius, int _particleTime, int _offset);// using the interpolating result this creates a spiral
     void printPoint(); // prints out the point on the curve
     ngl::Vec3 getPoint();
     void frameChange(int _frame);
     void changeRadiusGrowth(float _changeValue);

     void restart();
     ngl::Vec3 getMidPoint();
     void changeSpeed(float _changeValue);


private:
    float m_offset;
    float m_changeRate; //how often it should swtichen between the guide curves
    ngl::Vec3 m_controlPoints[3]; //control points that are stored int a list, they are used to create the guide curves
    int m_tracker; // this keeps track of the curve thats active
    ngl::Vec3 m_resultPoint; // this point is the point calculated by the whole tornado curve class and represents the point where the particle should be
    float m_curveCount; // represents the amount of guid curves used

    ngl::Vec3 m_maxHeight; // max height for the guide curve maybe make this a vector so that it represetn an end point
    float m_timeUp; // represents how long it takes the particle to reach the max height can also be used as lifetime of particle
    ngl::Vec3 m_midPoint; // stores the midpoint calculated by the interpolation function by interpolating between two guide curve points
    ngl::Vec3 m_curveResult[2]; // stores the two results from the guide curve calculation as there are only two that need to be used
    int m_frame;
    float m_speed;
    float m_radiusGrowth;
    float m_speedUp;
    int m_pickUpTime;
    float m_pickUpRadius;
    int m_startValue;

};





#endif 
