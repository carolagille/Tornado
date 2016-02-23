#include <iostream>
#include "TornadoCurve.h"
int main()
{
    int control1[3]={-10,-10,5};
    int control2[3]={-10,-10,5};
    int control3[3]={-10,-10,5};
    int* controlpoints[3]={control1,control2,control3};


    TornadoCurve Tornado1(10,controlpoints);
    for(int i=0;i <= 20;i++)
    {
        Tornado1.interpolate(i,i);
        Tornado1.spiral(5,i);
        //std::cout<< i << std::endl;
        Tornado1.printPoint();
    }
    return 0;
}
