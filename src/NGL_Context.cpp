
#include <QGuiApplication> //includes all the event inter face related stuff
#include "NGL_Context.h"
#include "Tornado.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include <ngl/ShaderLib.h>
#include <ngl/Util.h>
#include <stdlib.h>
#include <fstream>
//#include <Magick++.h>
#include <sstream>
#include <ngl/Image.h>
#include "MainWindow.h"
#include <QImage>
NGL_Context::NGL_Context(QWidget *_parent, Tornado *_tornado): QOpenGLWidget(_parent)
{
    setFocus();
    this->resize(_parent->size());
    connect(this,SIGNAL(frameSwapped()),this,SLOT(writeImage()));
    static const GLuint FORMAT_NBYTES = 4;
    m_texure="textures/point.tif" ;
    m_pixels=NULL;
    m_tornado=_tornado;
    m_time=0;
    m_render=0;
    m_pixels =(GLubyte*) malloc(4 * m_width * m_height);
    m_particleSize=4;
    m_particleSubSysSize=4;
    m_bgColour= ngl::Vec3 (1.0f,1.0f,1.0f);

}

NGL_Context::~NGL_Context()
{
    std::cout<<"NGL Destructor called\n";
    free(m_pixels);
    delete m_tornado;
}

void NGL_Context::createPoints()
{

   m_tornado->update();


   std::vector<ngl::Vec3> pointsParticlSys= m_tornado->getParticleSysList();




  //make a vector from the vector that stores points in the Tornado class
  // than bing that later to the buffer
  // create a VAO and store the ID
  glGenVertexArrays(1, &m_vao);


  // first create the VAO
  // to use this it must be bound
  glBindVertexArray(m_vao);

  // now create a buffer for our data
  GLuint vboID;
  glGenBuffers(1, &vboID);
  // now we will bind an array buffer to the first one and load the data for the verts
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  // copy the data
  glBufferData(GL_ARRAY_BUFFER, pointsParticlSys.size()*sizeof(ngl::Vec3), &pointsParticlSys[0].m_x, GL_STATIC_DRAW);
  // now we need to tell OpenGL the size and layout of the data
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,((ngl::Real *)NULL + 0));
  glEnableVertexAttribArray(0);


  // always best to unbind after use
  glBindVertexArray(0);
//---------------------------------//
//second VAO//

  std::vector<ngl::Vec3> pointsParticle= m_tornado->getParticleList();

 glGenVertexArrays(1, &m_vao2);

 glBindVertexArray(m_vao2);

 GLuint vboID2;
 glGenBuffers(1, &vboID2);

 glBindBuffer(GL_ARRAY_BUFFER, vboID2);
 glBufferData(GL_ARRAY_BUFFER, pointsParticle.size()*sizeof(ngl::Vec3), &pointsParticle[0].m_x, GL_STATIC_DRAW);

 glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,((ngl::Real *)NULL + 0));
 glEnableVertexAttribArray(0);

 glBindVertexArray(0);
}

void NGL_Context::updatePoints()
{

    std::vector<ngl::Vec3> pointsParticlSys= m_tornado->getParticleSysList();

    glBindVertexArray(m_vao);
    // now copy the data/
    glBindBuffer(GL_ARRAY_BUFFER, m_vao);
    glBufferData(GL_ARRAY_BUFFER, pointsParticlSys.size()*sizeof(ngl::Vec3), &pointsParticlSys[0].m_x, GL_STATIC_DRAW);
  // always best to unbind after use
    glBindVertexArray(0);


    //Second VAO

    std::vector<ngl::Vec3> pointsParticle= m_tornado->getParticleList();

    glBindVertexArray(m_vao2);
    // now copy the data/
    glBindBuffer(GL_ARRAY_BUFFER, m_vao2);
    glBufferData(GL_ARRAY_BUFFER, pointsParticle.size()*sizeof(ngl::Vec3), &pointsParticle[0].m_x, GL_STATIC_DRAW);
  // always best to unbind after use
    glBindVertexArray(0);

}

void NGL_Context::resizeGL(QResizeEvent *_event)
{

    m_width=_event->size().width()*devicePixelRatio();
    m_height=_event->size().height()*devicePixelRatio();
    m_pixels =(GLubyte*) realloc(m_pixels,4 * m_width * m_height);
    m_text->setScreenSize(width(),height());
}

void NGL_Context::resizeGL(int _w, int _h)
{
    m_width=_w*devicePixelRatio();
    m_height=_h*devicePixelRatio();
    //std::cout<<"height:"<<m_height<<"width:"<<m_width<<"\n";
    m_pixels =(GLubyte*) realloc(m_pixels,4 * m_width * m_height);
    m_text->setScreenSize(width(),height());
}

void NGL_Context::initializeGL()
{
    m_zoom=500;
    m_angleX=0;
    m_angleZ=0;
    m_gridCenter=100;


    ngl::NGLInit::instance(); //creates one instance of init
    //to prevent you from creating lot of bog instances of smomething that just needs to be used once
    glClearColor(m_bgColour[0],m_bgColour[1],m_bgColour[2],1.0f); //white background
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    ngl::Mat4 view=ngl::lookAt(ngl::Vec3(m_zoom,m_zoom,m_gridCenter),ngl::Vec3(0,0,m_gridCenter),ngl::Vec3(0,0,1));
    ngl::Mat4 perspective=ngl::perspective(45,float(width()/height()),0.1,10000);
    // store to vp for later use
    m_vp=view*perspective;


    // create my shader
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
      // we are creating a shader called Phong
      shader->createShaderProgram("MyShader");
      // now we are going to create empty shaders for Frag and Vert
      shader->attachShader("MyShaderVert",ngl::ShaderType::VERTEX);
      shader->attachShader("MyShaderFrag",ngl::ShaderType::FRAGMENT);


      // attach the source
      shader->loadShaderSource("MyShaderVert","shaders/vertexShader.glsl");
      shader->loadShaderSource("MyShaderFrag","shaders/fragmentShader.glsl");

      // compile the shaders
      shader->compileShader("MyShaderVert");
      shader->compileShader("MyShaderFrag");

      // add them to the program
      shader->attachShaderToProgram("MyShader","MyShaderVert");
      shader->attachShaderToProgram("MyShader","MyShaderFrag");


      // now we have associated this data we can link the shader
      shader->linkProgramObject("MyShader");
      // and make it active ready to load values
      (*shader)["MyShader"]->use();
      shader->autoRegisterUniforms("MyShader");

      loadTexture();

    // now load the default nglColour shader and set the colour for it.




    // set this as the active shader


    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
    // create a plane
    prim->createLineGrid("plane",20,20,30);

    shader->use("nglColourShader");
    // set the colour to red
    shader->setShaderParam4f("Colour",0.545f,0.513f,0.470f,1.0f);


    //creating a point??
    createPoints();
    shader->setShaderParam4f("Colour",1,1,1,1);
    m_text.reset( new ngl::Text(QFont("Courier",18)));
    m_text->setColour(1,1,0);
    m_text->setScreenSize(width(),height());
    glPointSize(5);
    startTimer(20);
 }





void NGL_Context::loadTexture()
{
  glGenTextures(1, &m_textureName);


  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  GLuint shaderHandle = shader->getProgramID("MyShader");



  QImage image;
  bool loaded=image.load(m_texure);
  if(loaded == true)
  {
    int width=image.width();
    int height=image.height();

    unsigned char *data = new unsigned char[ width*height*4];
    unsigned int index=0;
    QRgb colour;
    for( int y=0; y<height; ++y)
    {
      for( int x=0; x<width; ++x)
      {
        colour=image.pixel(x,y);

        data[index++]=qRed(colour);
        data[index++]=qGreen(colour);
        data[index++]=qBlue(colour);
        data[index++]=qAlpha(colour);
      }
    }

  glGenTextures(1,&m_textureName);
  glBindTexture(GL_TEXTURE_2D,m_textureName);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);

  glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

  glUniform1i(glGetUniformLocation(shaderHandle,"tex"),0);

  }
  else
    std::cout<<"TEXURE FILE NOT LOADED\n";
}

void NGL_Context::paintGL()
{

    //loadTexture();
    glBindTexture(GL_TEXTURE_2D,m_textureName);
    ngl::Transformation transform;
    ngl::Mat4 view=ngl::lookAt(ngl::Vec3(m_zoom,m_zoom,m_gridCenter),ngl::Vec3(0,0,m_gridCenter),ngl::Vec3(0,0,1));
    ngl::Mat4 perspective=ngl::perspective(45,float(width()/height()),0.1,10000);
    m_vp=view*perspective;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_width,m_height);

    ngl::ShaderLib *shader=ngl::ShaderLib::instance();

    shader->use("nglColourShader");
    // set the colour to red

    transform.setRotation(m_angleX,0,m_angleZ);

    ngl::Mat4 MVP =transform.getMatrix()*m_vp;
    shader->setRegisteredUniformFromMat4("MVP",MVP);


    //particle sys
    shader->setShaderParam4f("Colour",0.545f,0.513f,0.470f,1.0f);

    glPointSize(m_particleSubSysSize);
    glBindVertexArray(m_vao);

    glDrawArrays(GL_POINTS,0,m_tornado->getParticleSysCount());

    glBindVertexArray(0);
    //case Qt::Key_P: m_tornado->particlesOnOff();break;




    //Grid
    ngl::Transformation transformGrid;
    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//
    //change colour to black
    shader->use("nglColourShader");
    shader->setShaderParam4f("Colour",0.5f,0.5f,0.5f,1.0f);

    transformGrid.setRotation(90+m_angleX,0,m_angleZ);
    transformGrid.setScale(20,20,20);
    ngl::Mat4 MVP2=transformGrid.getMatrix()*m_vp;
    shader->setRegisteredUniformFromMat4("MVP",MVP2);


    prim->draw("plane");
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
//End Grid






    glPointSize(m_particleSize);

    //Particles0.545f,0.513f,0.470f,1.0f
    //shader->use("nglColourShader");
    shader->use("MyShader");
    shader->setRegisteredUniformFromMat4("MVP",MVP);
    //shader->setShaderParam4f("Colour",0.545f,0.513f,0.470f,1.0f);
    glBindVertexArray(m_vao2);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDrawArrays(GL_POINTS,0,m_tornado->getFullParticleCount());

    glBindVertexArray(0);

    glDisable(GL_BLEND);



    m_text->setColour(1,0,0);
    // now render the text using the QT renderText helper function
    QString text=QString("frame %1").arg(m_time);
    m_text->renderText(m_width-160,(m_height-25),text);

    if(m_render)
    {
      saveImage();
    }
m_time++;
}
void NGL_Context::timerEvent(QTimerEvent *_event)
{

  m_tornado->update();
  //m_tornado->printList();
  updatePoints();
  update();

}

void NGL_Context::keyPressEvent(QKeyEvent *_event)
{
  // that method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quit
  //case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  // turn on wirframe rendering


  case Qt::Key_Plus : m_zoom-=50;break;

  case Qt::Key_Minus : break;

  default : break;
  }

    update();
}
void NGL_Context::zoomIn()
{
  m_zoom-=50;
}
void NGL_Context::zoomOut()
{
  m_zoom+=50;
}
void NGL_Context::rotateUp()
{
   m_angleX-=5;
}

void NGL_Context::rotateDown()
{
  m_angleX+=5;
}

void NGL_Context::left()
{
  m_angleZ+=5;
}

void NGL_Context::right()
{
  m_angleZ-=5;
}

void NGL_Context::up()
{
  m_gridCenter+=10;
}

void NGL_Context::down()
{
  m_gridCenter-=10;
}

void NGL_Context::saveImage()
{//boost format
    std::ostringstream filename;



    filename<<"renders/tornado"<<m_time;//<<".jpg";
    QString qfilename= QString::fromStdString(filename.str());
    std::cout<<"working\n";
    QImage image=QOpenGLWidget::grabFramebuffer();

    image.save(qfilename);


//    glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());
//    ngl::Image::saveFrameBufferToFile(filename.str(),0,0,m_width,m_height,ngl::Image::ImageModes::RGB);

    //((MainWindow*)parentWidget())->saveImage();
    //GLuint buffer;

    //glBindBuffer(GL_PIXEL_PACK_BUFFER,buffer);
//    //glReadPixels(0, 0, m_width, m_height, GL_RGB, GL_UNSIGNED_BYTE, m_pixels);
//    Magick::Blob b( m_pixels, 3 * m_width * m_height );
//    Magick::Image i( m_width,
//                     m_height,
//                     "RGB",
//                     Magick::CharPixel,
//                     m_pixels);

//
//    i.write(filename.str());




}

void NGL_Context::renderOnOff()
{

  m_render==0 ? m_render=1 : m_render=0;
}
void NGL_Context::changeParticleSize(int value)
{
  m_particleSize=value;
}
void NGL_Context::changeParticleSubSys(int value)
{
  m_particleSubSysSize=value;
}
void NGL_Context::setTexure(QString _texureName)
{
  m_texure=_texureName;
  loadTexture();
}

int NGL_Context::getHeight()
{
  return m_height;
}

int NGL_Context::getWidth()
{
  return m_width;
}




void NGL_Context::restart()
{
  m_zoom=500;
  m_angleX=0;
  m_angleZ=0;
  m_gridCenter=100;

  ngl::Mat4 view=ngl::lookAt(ngl::Vec3(m_zoom,m_zoom,m_gridCenter),ngl::Vec3(0,0,m_gridCenter),ngl::Vec3(0,0,1));
  ngl::Mat4 perspective=ngl::perspective(45,float(width()/height()),0.1,10000);
  // store to vp for later use
  m_vp=view*perspective;
  //.m_vao.
  //GLuint m_vao2;


  m_time=0;
  m_render=0;
  m_particleSize=4;
  emit resetParticleSize(m_particleSize);
  m_particleSubSysSize=4;
  emit resetParticleSysSize(m_particleSubSysSize);
  m_texure="textures/point.tif" ;
  emit resetTexure(m_texure);

  m_tornado->restart();


}

void NGL_Context::writeImage()

{
    QImage image=QOpenGLWidget::grabFramebuffer();

    image.save("image.png");

}


void NGL_Context::setBGColourR(double _changeValue)
{
  m_bgColour[0]=_changeValue;
  glClearColor(m_bgColour[0],m_bgColour[1],m_bgColour[2],1.0f); //white background
}

void NGL_Context::setBGColourG(double _changeValue)
{
  m_bgColour[1]=_changeValue;
  glClearColor(m_bgColour[0],m_bgColour[1],m_bgColour[2],1.0f); //white background
}

void NGL_Context::setBGColourB(double _changeValue)
{
  m_bgColour[2]=_changeValue;
  glClearColor(m_bgColour[0],m_bgColour[1],m_bgColour[2],1.0f); //white background
}

/*void NGL_Context::wheelEvent(QWheelEvent *_event)
{

  if(_event->delta() > 0)
  {
   m_zoom+=50;
  }
  else if(_event->delta() <0 )
  {
    m_zoom-=50;
  }
  update();
}
*/
