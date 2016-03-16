#include <iostream>
#include "TornadoCurve.h"
#include "Tornado.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include <vector>
#include <QtGui/QGuiApplication>
#include "NGL_Context.h"
#include <ngl/Vec3.h>

int main(int argc,char **argv)
{
    std::cout<<"\n\n\n line 13\n";
    //Control points
    ngl::Vec3 control1(130.0f,+10.0f,100.0f);
    ngl::Vec3 control2(-70.0f,-50.0f,100.0f);
    ngl::Vec3 control3(50.0f,100.0f,100.0f);
    ngl::Vec3 controlpoints[3]={control1,control2,control3};

    Tornado tornado1(300,controlpoints,400);
    //std::cout<<"\n\n\n line 21\n";
    QGuiApplication app(argc,argv); //manages your program

    //argv and argc are command line inputs that can be taken by the
    //programm and used by the QGuiApplication
    //std::cout<<"\n\n\n line 26\n";
    QSurfaceFormat format; //manages the buffer stuff
    format.setSamples(4);
    std::cout<<"\n\n\n line 29\n";


     //I'm not really sure what this does....
#if defined( __APPLE__)
  // at present mac osx Mountain Lion only supports GL3.2
  // the new mavericks will have GL 4.x so can change
  format.setMajorVersion(4);
  format.setMinorVersion(1);
#else
  // with luck we have the latest GL version so set to this
  format.setMajorVersion(4);
  format.setMinorVersion(3);
#endif
//stuff???
  //std::cout<<"\n\n\n line 44\n";
  format.setProfile(QSurfaceFormat::CoreProfile);
  //std::cout<<"\n\n\n line 46\n";
  format.setDepthBufferSize(24);


  //starting the actual program
  //creatin a window

  NGL_Context window(&tornado1);

  window.setFormat(format);//formating  out window and program to the before defined values

  window.resize(1024, 720);

  window.show();


  return app.exec();

/*
    TornadoCurve Tornado1(200,controlpoints);
    for(int i=0, j=100; i <= 400; i++,j++)
    {
        Tornado1.interpolate(j,i);
        Tornado1.spiral(1,i);
        //std::cout<< i << std::endl;
        Tornado1.printPoint();
    }
    return 0;
    */

    /*Tornado Tornado1(10,controlpoints,200);
    for(int i=0;i<=400;i++)
    {
        Tornado1.update();
    }
    Tornado1.printList();
    return 0;*/

}
