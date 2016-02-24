#include <iostream>
#include "TornadoCurve.h"
int main()
{
    float control1[3]={10,0,20};
    float control2[3]={10,0,20};
    float control3[3]={10,0,20};
    float* controlpoints[3]={control1,control2,control3};


    TornadoCurve Tornado1(100,controlpoints);
    for(int i=0, j=0; i <= 40; i++,j++)
    {
        Tornado1.interpolate(j,i);
        Tornado1.spiral(5,i);
        //std::cout<< i << std::endl;
        Tornado1.printPoint();
    }
    return 0;
}
