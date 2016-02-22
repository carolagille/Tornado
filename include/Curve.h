#ifndef CURVE_H__
#define CURVE_H__

class TornadoCurve
{
 public:
	 void guideCurve(int _particleTime,int _controllPoint, int _timeUp); // make this a class????
	 void interpolate(int _frame,int _particleTime,int _changeRate);
	 void spiral (int _radius, int _particleTime);
	 void TornadoCurve(int _changeRate,int _controllPoints[3][3]);
	 int* getPoint();
 
private:
 	int m_changeRate;
	float m_controllPoints[3][3];
	int m_tracker;
	float m_resultPoint[3];
	int m_CurveCount;
	
 
};





#endif 