#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__

#include <ngl/Vec3.h>
#include <QObject>

/// @file Tornado.h
/// @brief inherites from QObject
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class Tornado
/// @brief Tornado Class that holds the particles systems


class TornadoCurve:public QObject
{Q_OBJECT
 public slots:
    ///@brief slot that sets the height value
    /// @param _value value to set
    void setHeight(int _value);
    ///@brief slot that sets the X value of the first point
    /// @param _value value to set
    void setControllPoint1X(int _value);
    ///@brief slot that sets the Z value of the first point
    /// @param _value value to set
    void setControllPoint1Z(int _value);
    ///@brief slot that sets the X value of the second point
    /// @param _value value to set
    void setControllPoint2X(int _value);
    ///@brief slot that sets the Z value of the second point
    /// @param _value value to set
    void setControllPoint2Z(int _value);
    ///@brief slot that sets the X value of the third point
    ///@param _value value to set
    void setControllPoint3X(int _value);
    ///@brief slot that sets the Z value of the third point
    /// @param _value value to set
    void setControllPoint3Z(int _value);
    ///@brief slot that sets Curve count and enable curves based on that
    /// @param[in] _value value to set
    void setCurveCount(int _value);
    ///@brief slot that sets the radius of the tornado base
    /// @param[in] _value value to set
    void setPickUpRadius(double _value);
    ///@brief slot that sets the time it takes to pick up particles from the ground
    /// @param[in] _value value to set
    void setPickUpTime(int _value);
    ///@brief slot that sets the value of what how much the tonrado should be offsetted
    /// offsetting it more will create a larger starting radius
    /// offsetting it less will create a smaller starting radius
    /// @param[in] _value value to set
    void setStartValue(int _value);
    ///@brief slot that sets the upwards speed value
    /// @param[in] _value value to set
    void setSpeedUp(double _value);
    ///@brief slot that resets all values
    void reset();
    ///@brief slot that sets the amount that the radius growthes while going upwards
    /// @param[in] _value value to set
    void setRadiusGrowth(double _value);


 signals:
    ///@brief emmits the state of the curve that than disables or enables the second curve
    /// @param[in]_state state to emmit
    void disableCurve2(bool _state);
    ///@brief emmits the state of the curve that than disables or enables the third curve
    /// @param[in]_state state to emmit
    void disableCurve3(bool _state);
    ///@brief emmits the curve count value
    /// used by the curve count field in the ui
    /// @param[in]_value value that is emmitted
    void resetCurveCount(int _value);
    ///@brief emmits the X value of the first control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint1X(int _value);
    ///@brief emmits the Z value of the first control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint1Z(int _value);
    ///@brief emmits the X value of the second control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint2X(int _value);
    ///@brief emmits the Z value of the second control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint2Z(int _value);
    ///@brief emmits the X value of the third control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint3X(int _value);
    ///@brief emmits the Z value of the third control point
    /// used by the control points field in the ui
    /// @param[in]_value value that is emmitted
    void resetControllPoint3Z(int _value);
    ///@brief emmits the maximum height of the Tornado
    /// used by the max height field in the ui
    /// @param[in]_value value that is emmitted
    void resetHeight(int _value);
    ///@brief emmits the radius that the tornado picks particles from
    /// used by the pick up radius field in the ui
    /// @param[in]_value value that is emmitted
    void resetPickUpRadius(double _changeValue);
    ///@brief emmits the time it takes to pick up the particles from the ground
    /// used by the pick up time field in the ui
    /// @param[in]_value value that is emmitted
    void resetPickUpTime(int _changeValue);
    ///@brief emmits the offset for the starting value of the tornado
    /// used by the start value field in the ui
    /// @param[in]_value value that is emmitted
    void resetStartValue(int _changeValue);
    ///@brief emmits the speed up value
    /// used by the speed up field in the ui
    /// @param[in]_value value that is emmitted
    void resetSpeedUp(double _changeValue);
    ///@brief emmits the radius growth value
    /// used by the radius growth field in the ui
    /// @param[in]_value value that is emmitted
    void resetRadiusGrowth(double _changeValue);


 public:
    ///@brief constructor
     TornadoCurve();
     ///@brief calculates the three diffrent curves by interpolating between start and end and a controll point
     /// it than saves the value of the curve at the given time
     /// @param _particleTime the time passed from the particle (age of the particle) that is used to calculate one specific point on the curve
     /// @param _controlPoint controll point of the accroding curve is used as a controll point for the interpolation
     /// @param _index index number of the position we want to access
     /// @param _curveNum the index number of the according curve that is calculated
     void guideCurve(int _particleTime, ngl::Vec3 _controlPoint, int _index, int _curveNum);
     ///@brief interpolates between two curve points calulated by the guide curve function
     /// @param _particleTime input that
     void interpolate(int _particleTime);
     void spiral (int _radius, int _particleTime, int _offset);// using the interpolating result this creates a spiral
     void printPoint(); // prints out the point on the curve
     ngl::Vec3 getPoint();
     void frameChange(int _frame);
     void changeRadiusGrowth(float _changeValue);
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
