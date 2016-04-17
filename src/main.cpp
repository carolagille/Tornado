#include <iostream>
#include "TornadoCurve.h"
#include "Tornado.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include <vector>
#include <QApplication>
#include "NGL_Context.h"
#include <ngl/Vec3.h>
#include "MainWindow.h"

int main(int argc,char **argv)
{

  // create an OpenGL format specifier
  QSurfaceFormat format;
  // set the number of samples for multisampling
  // will need to enable glEnable(GL_MULTISAMPLE); once we have a context
  format.setSamples(4);
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

  format.setProfile(QSurfaceFormat::CoreProfile);

  format.setDepthBufferSize(24);
  // this will set the format for all widgets

  QSurfaceFormat::setDefaultFormat(format);
  // make an instance of the QApplication
  QApplication a(argc, argv);
  // Create a new MainWindow
  if(argc > 1)
  {
    int simple= argv[1][0]-'0';

    MainWindow window(simple);

    window.show();
    //window.corner()

    return a.exec();
  }
  else
  {
    std::cout << "Usage:\nDefaultUI:\nTornado 0\nSimpleUI:\nTornado 1" << std::endl;
    exit(EXIT_FAILURE);
  }


  /*
   -    Tornado tornado1(300,controlpoints,400);
   -    //std::cout<<"\n\n\n line 21\n";
   -    QGuiApplication app(argc,argv); //manages your program

   -    //argv and argc are command line inputs that can be taken by the
   -    //programm and used by the QGuiApplication
   -    //std::cout<<"\n\n\n line 26\n";
   -    QSurfaceFormat format; //manages the buffer stuff
   -    format.setSamples(4);
   -    std::cout<<"\n\n\n line 29\n";
   -
   -
   -     //I'm not really sure what this does....
   -#if defined( __APPLE__)
   -  // at present mac osx Mountain Lion only supports GL3.2
   -  // the new mavericks will have GL 4.x so can change
   -  format.setMajorVersion(4);
   -  format.setMinorVersion(1);
   -#else
   -  // with luck we have the latest GL version so set to this
   -  format.setMajorVersion(4);
   -  format.setMinorVersion(3);
   -#endif
   -//stuff???
   -  //std::cout<<"\n\n\n line 44\n";
   -  format.setProfile(QSurfaceFormat::CoreProfile);
   -  //std::cout<<"\n\n\n line 46\n";
   -  format.setDepthBufferSize(24);
   -
   -
   -  //starting the actual program
   -  //creatin a window
   -
   -  NGL_Context window(&tornado1);
   -
   -  window.setFormat(format);//formating  out window and program to the before defined values
   -
   -  window.resize(1024, 720);
   -
   -  window.show();
   -
   -
   -  return app.exec();
   -
   -*/


}
