#ifndef TORNADOCURVE_H__
#define TORNADOCURVE_H__

class TornadoCurve
{
 public:
     TornadoCurve(int _changeRate,int* _controlPoint[3]);
     void guideCurve(int _particleTime, int _controlPoint[], int _position, int _curveNum); // make this a class????
     void interpolate(int _frame,int _particleTime);
	 void spiral (int _radius, int _particleTime);
	 int* getPoint();
     void printPoint();
 
private:
 	int m_changeRate;
    int m_controlPoints[3][3];
	int m_tracker;
	float m_resultPoint[3];
    int m_curveCount;
    float m_minHeight;
    float m_maxHeight;
    int m_timeUp;
    int m_midPoint[3];
    float m_curveResult[2][3];
};





#endif 
