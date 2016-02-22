#include <iostream>
#include "TornadoCurve.h"
int main()
{
    int control1[3]={4,0,5};
    int control2[3]={5,0,5};
    int control3[3]={9,0,5};
    int* controlpoints[3]={control1,control2,control3};


    TornadoCurve Tornado1(5,controlpoints);
    for(int i=0;i <= 20;i++)
    {
        Tornado1.interpolate(i,i);
        Tornado1.spiral(10,i);
        //std::cout<< i << std::endl;
        Tornado1.printPoint();
    }
    return 0;
}
