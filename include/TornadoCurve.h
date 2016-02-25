#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__

class TornadoCurve
{
 public:
     TornadoCurve(int _changeRate,float* _controlPoint[3]);
     void guideCurve(int _particleTime, float _controlPoint[], int _position, int _curveNum); // make this a class????, creates guide curves by interpolating between start and end and a control curve
     void interpolate(int _frame,int _particleTime);//interpolates between the diffrent guide curves
     void spiral (int _radius, int _particleTime);// using the interpolating result this creates a spiral
	 int* getPoint();
     void printPoint(); // prints out the point on the curve
 
private:
    float m_changeRate; //how often it should swtichen between the guide curves
    float m_controlPoints[3][3]; //control points that are stored int a list, they are used to create the guide curves
    int m_tracker; // this keeps track of the curve thats active
    float m_resultPoint[3]; // this point is the point calculated by the whole tornado curve class and represents the point where the particle should be
    float m_curveCount; // represents the amount of guid curves used
    float m_minHeight; // minumum height for the guide curve maybe make this a vector
    float m_maxHeight[3]; // max height for the guide curve maybe make this a vector so that it represetn an end point
    float m_timeUp; // represents how long it takes the particle to reach the max height can also be used as lifetime of particle
    float m_midPoint[3]; // stores the midpoint calculated by the interpolation function by interpolating between two guide curve points
    float m_curveResult[2][3]; // stores the two results from the guide curve calculation as there are only two that need to be used
};





#endif 
