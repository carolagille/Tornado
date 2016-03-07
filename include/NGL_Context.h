#ifndef NGL_CONTEXT_H
#define NGL_CONTEXT_H

#include <ngl/Camera.h> // Camera class that allows to movement in openGL
//#include <ngl/Colour.h> //class that can operare on colours add and subract them
#include <ngl/Transformation.h> //includes an object that makes it easier to tranform objects
#include <QOpenGLWindow>

class NGL_Context : public QOpenGLWindow
{
public:
    NGL_Context();
    ~NGL_Context();
    void initializeGL(); //creating an ngl context and window
    void paintGL(); // called whenever the window needs to be redrawn
private:
    void resizeGL(QResizeEvent *_event); //overloaded function that is automatically called when the window is resized
    void resizeGL(int _w,int _h);
    int m_width;
    int m_height;

};


#endif // NGL_CONTEXT_H
