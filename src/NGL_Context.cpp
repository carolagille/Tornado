#include <QMouseEvent>
#include <QGuiApplication> //includes all the event inter face related stuff
#include "NGL_Context.h"
#include "Tornado.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include <ngl/ShaderLib.h>
#include <ngl/Util.h>

NGL_Context::NGL_Context(Tornado *_tornado)
{
    m_tornado=_tornado;
    setTitle("Tornado Programm");

}

NGL_Context::~NGL_Context()
{
    std::cout<<"NGL Destructor called\n";

}

void NGL_Context::createPoints()
{
   m_tornado->update();
   std::vector<ngl::Vec3> points= m_tornado->getList();
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
  glBufferData(GL_ARRAY_BUFFER, points.size()*sizeof(ngl::Vec3), &points[0].m_x, GL_STATIC_DRAW);
  // now we need to tell OpenGL the size and layout of the data
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,((ngl::Real *)NULL + 0));
  glEnableVertexAttribArray(0);

  // always best to unbind after use
  glBindVertexArray(0);
}

void NGL_Context::updatePoints()
{

    std::vector<ngl::Vec3> points= m_tornado->getList();

    glBindVertexArray(m_vao);
    // now copy the data/  glBindBuffer(GL_ARRAY_BUFFER, m_vao);
    glBufferData(GL_ARRAY_BUFFER, points.size()*sizeof(ngl::Vec3), &points[0].m_x, GL_STATIC_DRAW);
  // always best to unbind after use
    glBindVertexArray(0);
}

void NGL_Context::resizeGL(QResizeEvent *_event)
{
    m_width=_event->size().width()*devicePixelRatio();
    m_height=_event->size().height()*devicePixelRatio();
}

void NGL_Context::resizeGL(int _w, int _h)
{
    m_width=_w*devicePixelRatio();
    m_height=_h*devicePixelRatio();
}

void NGL_Context::initializeGL()
{

    ngl::NGLInit::instance(); //creates one instance of init
    //to prevent you from creating lot of bog instances of smomething that just needs to be used once
    glClearColor(1.0f,1.0f,1.0f,1.0f); //white background
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    ngl::Mat4 view=ngl::lookAt(ngl::Vec3(500,50,500),ngl::Vec3(0,0,0),ngl::Vec3(0,1,0));
    ngl::Mat4 perspective=ngl::perspective(45.0f,float(width()/height()),0.1,1000);
    // store to vp for later use
    m_vp=view*perspective;
    // now load the default nglColour shader and set the colour for it.
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    // set this as the active shader
    shader->use("nglColourShader");
    // set the colour to red
    shader->setShaderParam4f("Colour",0.0f,0.0f,0.0f,1.0f);
    //creating a point??
    createPoints();
    glPointSize(10);
    startTimer(1);
 }

void NGL_Context::paintGL()
{

    m_tornado->update();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_width,m_height);

    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    //ngl::Transformation transform;

    //transform.setPosition(m_vao[0][0],m_vao[0][1],m_vao[0][2]);
    ngl::Mat4 MVP = m_vp;//=transform.getMatrix()*m_vp;
    shader->setRegisteredUniformFromMat4("MVP",MVP);

    glBindVertexArray(m_vao);


    glDrawArrays(GL_POINTS,0,m_tornado->getParticleSysCount());

    glBindVertexArray(0);
    std::cout<<"\n\n\n line 119\n";
}
void NGL_Context::timerEvent(QTimerEvent *_event)
{
   std::cout<<"calling timer event\n";
  m_tornado->update();
  updatePoints();
  update();
}
