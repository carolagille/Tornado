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

  format.setMajorVersion(4);
  format.setMinorVersion(3);
#endif


  format.setProfile(QSurfaceFormat::CoreProfile);

  format.setDepthBufferSize(24);


  QSurfaceFormat::setDefaultFormat(format);
  // make an instance of the QApplication
  QApplication a(argc, argv);
  // Create a new MainWindow
  if(argc > 1)
  {
    int simple= argv[1][0]-'0';

    MainWindow window(simple);

    window.show();

    return a.exec();
  }
  else
  {
    std::cout << "Usage:\nDefaultUI:\nTornado 0\nSimpleUI:\nTornado 1" << std::endl;
    exit(EXIT_FAILURE);
  }


}
