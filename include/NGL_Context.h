#ifndef NGL_CONTEXT_H
#define NGL_CONTEXT_H

#include <ngl/Camera.h> // Camera class that allows to movement in openGL
//#include <ngl/Colour.h> //class that can operare on colours add and subract them
#include <ngl/Transformation.h> //includes an object that makes it easier to tranform objects
#include <QOpenGLWindow>
#include "Tornado.h"
class NGL_Context : public QOpenGLWindow
{
public:
    NGL_Context(Tornado *_tornado);
    ~NGL_Context();
    void initializeGL(); //creating an ngl context and window
    void paintGL(); // called whenever the window needs to be redrawn
    void createPoints();
    void updatePoints();
    void timerEvent(QTimerEvent *);
private:
    void resizeGL(QResizeEvent *_event); //overloaded function that is automatically called when the window is resized
    void resizeGL(int _w,int _h);
    int m_width;
    int m_height;
    ngl::Mat4 m_vp;
    Tornado *m_tornado;
    GLuint m_vao;//my vertex array object that stores the points position


};


#endif // NGL_CONTEXT_H
