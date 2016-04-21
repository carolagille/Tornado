#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__

#include <ngl/Vec3.h>
#include <QObject>

/// @file TornadoCurve.h
/// @brief inherites from QObject
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class TornadoCurve
/// @brief Tornado Curve class that calculates the particle system positions


class TornadoCurve:public QObject
{Q_OBJECT
 public slots:
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the height value
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setHeight(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the X value of the first point
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint1X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the Z value of the first point
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint1Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the X value of the second point
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint2X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the Z value of the second point
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint2Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the X value of the third point
    ///@param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint3X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the Z value of the third point
    /// @param _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setControllPoint3Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets Curve count and enable curves based on that
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setCurveCount(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the radius of the tornado base
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setPickUpRadius(double _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the time it takes to pick up particles from the ground
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setPickUpTime(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the value of what how much the tonrado should be offsetted
    /// offsetting it more will create a larger starting radius
    /// offsetting it less will create a smaller starting radius
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setStartValue(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the upwards speed value
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setSpeedUp(double _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that resets all values
    //----------------------------------------------------------------------------------------------------------------------
    void reset();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief slot that sets the amount that the radius growthes while going upwards
    /// @param[in] _value value to set
    //----------------------------------------------------------------------------------------------------------------------
    void setRadiusGrowth(double _value);


 signals:
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the state of the curve that than disables or enables the second curve
    /// @param[in] _state state to emmit
    //----------------------------------------------------------------------------------------------------------------------
    void disableCurve2(bool _state);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the state of the curve that than disables or enables the third curve
    /// @param[in] _state state to emmit
    //----------------------------------------------------------------------------------------------------------------------
    void disableCurve3(bool _state);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the curve count value
    /// used by the curve count field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetCurveCount(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the X value of the first control point
    /// used by the control points field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint1X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the Z value of the first control point
    /// used by the control points field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint1Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the X value of the second control point
    /// used by the control points field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint2X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the Z value of the second control point
    /// used by the control points field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint2Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the X value of the third control point
    /// used by the control points field in the ui
    /// @param[in]  _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint3X(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the Z value of the third control point
    /// used by the control points field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetControllPoint3Z(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the maximum height of the Tornado
    /// used by the max height field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetHeight(int _value);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the radius that the tornado picks particles from
    /// used by the pick up radius field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetPickUpRadius(double _changeValue);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the time it takes to pick up the particles from the ground
    /// used by the pick up time field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetPickUpTime(int _changeValue);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the offset for the starting value of the tornado
    /// used by the start value field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetStartValue(int _changeValue);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the speed up value
    /// used by the speed up field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetSpeedUp(double _changeValue);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief emmits the radius growth value
    /// used by the radius growth field in the ui
    /// @param[in] _value value that is emmitted
    //----------------------------------------------------------------------------------------------------------------------
    void resetRadiusGrowth(double _changeValue);


 public:
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief constructor
    //----------------------------------------------------------------------------------------------------------------------
     TornadoCurve();
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief calculates the three diffrent curves by interpolating between start and end and a controll point
     /// it than saves the value of the curve at the given time
     /// @param[in] _particleTime the time passed from the particle (age of the particle) that is used to calculate one specific point on the curve
     /// @param[in] _controlPoint controll point of the accroding curve is used as a controll point for the interpolation
     /// @param[in] _index index number of the position we want to access
     /// @param[in] _curveNum the index number of the according curve that is calculated
     //----------------------------------------------------------------------------------------------------------------------
     void guideCurve(int _particleTime, ngl::Vec3 _controlPoint, int _index, int _curveNum);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief interpolates between two curve points calulated by the guide curve function
     /// @param[in] _particleTime represents the time value for interpolation
     //----------------------------------------------------------------------------------------------------------------------
     void interpolate(int _particleTime);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief calculates the spiral movement based on the midle point calculated by the interpolate function
     ///@param[in] _radius defines the radius of the spiral
     ///@param[in] _particleTime represents the time value for the spiral
     ///@param[in] _offset offset value that sets how much the spiral is offsetted
     //----------------------------------------------------------------------------------------------------------------------
     void spiral (int _radius, int _particleTime, int _offset);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief prints out the point calculated by the spiral function
     //----------------------------------------------------------------------------------------------------------------------
     void printPoint();
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief returns the point that is calculated by the spiral function
     ///@param[out] returns the point
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 getPoint();
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief changes the frame and the tracker value for the curves
     /// @param[in] _frame current frame
     //----------------------------------------------------------------------------------------------------------------------
     void frameChange(int _frame);
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief returns the mid point calculated by the interpolate function
     /// @param [out] returns the mid point
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 getMidPoint();

private:
     //----------------------------------------------------------------------------------------------------------------------
     ///@brief change rate that controlls how fast the interpolation between the curves it going
     //----------------------------------------------------------------------------------------------------------------------
    float m_changeRate;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the controll points for the diffrent curves
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_controlPoints[3];
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the tracker value that tracks which curve is active
    //----------------------------------------------------------------------------------------------------------------------
    int m_tracker;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief this point is the point calculated by the whole tornado curve class and represents the point where the particle should be
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_resultPoint;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the amount of curves that are used
    //----------------------------------------------------------------------------------------------------------------------
    float m_curveCount;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the maximum height of the tornado
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_maxHeight;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief time that takes the particle to get up calculated by the max height and the speed up
    //----------------------------------------------------------------------------------------------------------------------
    float m_timeUp;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the mid point calculated by the interpolation function
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_midPoint;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the results of the guide curve function
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_curveResult[2];
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the frame rate
    //----------------------------------------------------------------------------------------------------------------------
    int m_frame;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the speed value that controlls how fast the tornado spins
    //----------------------------------------------------------------------------------------------------------------------
    float m_speed;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief value that controlls the growth of the radius of the tornado
    //----------------------------------------------------------------------------------------------------------------------
    float m_radiusGrowth;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief value that controlls how fast the tornado travells upwards
    //----------------------------------------------------------------------------------------------------------------------
    float m_speedUp;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief defines the time it takes to pick up a particle from the ground
    //----------------------------------------------------------------------------------------------------------------------
    int m_pickUpTime;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief defines the radius of particles on the ground
    //----------------------------------------------------------------------------------------------------------------------
    float m_pickUpRadius;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief defines that value of when the tornado start a higher value will make the original radius bigger
    //----------------------------------------------------------------------------------------------------------------------
    int m_startValue;

};





#endif 
