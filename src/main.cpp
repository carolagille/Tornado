#include <iostream>
#include "TornadoCurve.h"
int main()
{
    float control1[3]={30,0,100};
    float control2[3]={-30,0,100};
    float control3[3]={5,0,100};
    float* controlpoints[3]={control1,control2,control3};


    TornadoCurve Tornado1(200,controlpoints);
    for(int i=0, j=0; i <= 400; i++,j++)
    {
        Tornado1.interpolate(j,i);
        Tornado1.spiral(1,i);
        //std::cout<< i << std::endl;
        Tornado1.printPoint();
    }
    return 0;
}
