#include "NGL_Context.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include <QGuiApplication> //includes all the event inter face related stuff

NGL_Context::NGL_Context()
{
    setTitle("Tornado Programm");
}

NGL_Context::~NGL_Context()
{
    std::cout<<"NGL Destructor called\n";

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
 }

void NGL_Context::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_width,m_height);

}
