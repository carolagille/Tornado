#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__

class TornadoCurve
{
 public:
     TornadoCurve(int _changeRate,float* _controlPoint[3]);
     void guideCurve(int _particleTime, float _controlPoint[], int _position, int _curveNum); // make this a class????
     void interpolate(int _frame,int _particleTime);
	 void spiral (int _radius, int _particleTime);
	 int* getPoint();
     void printPoint();
 
private:
    float m_changeRate;
    float m_controlPoints[3][3];
	int m_tracker;
	float m_resultPoint[3];
    float m_curveCount;
    float m_minHeight;
    float m_maxHeight;
    float m_timeUp;
    float m_midPoint[3];
    float m_curveResult[2][3];
};





#endif 
