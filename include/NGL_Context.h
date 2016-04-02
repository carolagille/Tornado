#ifndef NGL_CONTEXT_H
#define NGL_CONTEXT_H

#include <ngl/Camera.h> // Camera class that allows to movement in openGL

#include <ngl/Transformation.h> //includes an object that makes it easier to tranform objects

#include "Tornado.h"
#include <QObject>
#include <QOpenGLWidget>

class NGL_Context : public QOpenGLWidget
{
Q_OBJECT
public slots:
  void renderOnOff();
  void changeParticleSize(int value);
  void changeParticleSubSys(int value);

public:
    NGL_Context(QWidget *_parent ,Tornado *_tornado);
    ~NGL_Context();
    void initializeGL(); //creating an ngl context and window
    void paintGL(); // called whenever the window needs to be redrawn
    void createPoints();
    void updatePoints();
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *_event);
    void saveImage();
    void create_ppm(char *prefix, int frame_id, unsigned int pixel_nbytes );
    void loadTexture();
private:
    void resizeGL(QResizeEvent *_event); //overloaded function that is automatically called when the window is resized
    void resizeGL(int _w,int _h);
    int m_width;
    int m_height;
    ngl::Mat4 m_vp;
    Tornado *m_tornado;
    ngl::Vec3 m_tornadoPosition;
    GLuint m_vao;//my vertex array object that stores the points position
    GLuint m_vao2;
    int m_zoom;
    int m_angleX;
    int m_angleZ;
    int m_gridCenter;
    int m_time;
    int m_render;
    int m_particleSize;
    int m_particleSubSysSize;

    GLubyte *m_pixels;
    GLuint m_textureName;

};


#endif // NGL_CONTEXT_H
