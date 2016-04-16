#ifndef NGL_CONTEXT_H
#define NGL_CONTEXT_H

#include <ngl/Camera.h> // Camera class that allows to movement in openGL
#include <ngl/Transformation.h> //includes an object that makes it easier to tranform objects
#include "Tornado.h"
#include <QObject>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <ngl/Text.h>

/// @file NGL_Context.h
/// @brief this class inherits from QOpenGLWidget
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class NGL_Context
/// @brief Our Ngl Scene that is making a window that is used as a widget and displays the scene and the tornado
///
class NGL_Context : public QOpenGLWidget
{
Q_OBJECT
public slots:
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that toggles the renderer
  //----------------------------------------------------------------------------------------------------------------------
  void renderOnOff();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the particle size
  ///@param[in] _value the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void changeParticleSize(int _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the particle system size
  ///@param[in] _value the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void changeParticleSubSys(int _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the texure name
  ///@param[in] _texureName the QString to set
  //----------------------------------------------------------------------------------------------------------------------
  void setTexure(QString _texureName);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that rotates the tornado up in X direction
  //----------------------------------------------------------------------------------------------------------------------
  void rotateUp();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that rotates the tornado down in X direction
  //----------------------------------------------------------------------------------------------------------------------
  void rotateDown();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that rotates the tornado left in Z direction
  //----------------------------------------------------------------------------------------------------------------------
  void left();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that rotates the tornado right in Z direction
  //----------------------------------------------------------------------------------------------------------------------
  void right();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that moves the center and so the camera up
  //----------------------------------------------------------------------------------------------------------------------
  void up();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that moves the center and so the camera down
  //----------------------------------------------------------------------------------------------------------------------
  void down();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that changes the camera settings so that it zooms in to the image
  //----------------------------------------------------------------------------------------------------------------------
  void zoomIn();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that changes the camera settings so that it zooms out of the image
  //----------------------------------------------------------------------------------------------------------------------
  void zoomOut();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the red value of the background colour
  ///@param[in] _value the value its setting
  //----------------------------------------------------------------------------------------------------------------------
  void setBGColourR(double _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the green value of the background colour
  ///@param[in] _value the value its setting
  //----------------------------------------------------------------------------------------------------------------------
  void setBGColourG(double _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that sets the blue value of the background colour
  ///@param[in] _value the value its setting
  //----------------------------------------------------------------------------------------------------------------------
  void setBGColourB(double _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief slot that turn depth testing on and off
  ///@param[in] _value that set on and off
  //----------------------------------------------------------------------------------------------------------------------
  void setDepthsortValue(bool _value);

signals:
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetParticleSize(int _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetParticleSysSize(int _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when string is reset
  ///@param[in] _value the string it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetTexure(QString _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetDepthsortValue(bool _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetBGColourR(double _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetBGColourG(double _value);
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief emit a signal when value is reset
  ///@param[in] _value the value it is emiting
  //----------------------------------------------------------------------------------------------------------------------
  void resetBGColourB(double _value);

public:
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief Constructor of NGL_Context
  ///@param[in] _parent the parent Window to create the GL context
  ///@param[in] _tornado pointer to tornado object to access data
  //----------------------------------------------------------------------------------------------------------------------
    NGL_Context(QWidget *_parent ,Tornado *_tornado);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief destructor
    //----------------------------------------------------------------------------------------------------------------------
    ~NGL_Context();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief  The following methods must be implimented in the sub class
    /// this is called when the window is created
    //----------------------------------------------------------------------------------------------------------------------
    void initializeGL(); //creating an ngl context and window
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is the main gl drawing routine which is called whenever the window needs to
    /// be re-drawn
    //----------------------------------------------------------------------------------------------------------------------
    void paintGL(); // called whenever the window needs to be redrawn
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief creates vao and bind them for the vectors of particle positions and the vector of particle system position
    //----------------------------------------------------------------------------------------------------------------------
    void createPoints();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief update the vao based on the new particle positions and particle system positions
    //----------------------------------------------------------------------------------------------------------------------
    void updatePoints();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief gets called everytime the timer increases and calls
    /// all update functions
    /// @param[in] _event timer event value
    //----------------------------------------------------------------------------------------------------------------------
    void timerEvent(QTimerEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief saves an image from the frame buffer
    /// it needs the image magick library installed
    //----------------------------------------------------------------------------------------------------------------------
    void saveImage();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief loads a texture and binds it
    //----------------------------------------------------------------------------------------------------------------------
    void loadTexture();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief returns the m_height value
    //----------------------------------------------------------------------------------------------------------------------
    int getHeight();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief returns the m_width value
    //----------------------------------------------------------------------------------------------------------------------
    int getWidth();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief resets all values and emits them
    //----------------------------------------------------------------------------------------------------------------------
    void restart();
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief compares two points regarding their x value
    /// @param[in] _a first comparison value
    /// @param[in] _b second comparison value
    /// @param[out] returns 1 if a is bigger than b
    //----------------------------------------------------------------------------------------------------------------------
    static bool depthSort(ngl::Vec3 _a, ngl::Vec3 _b);


private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called whenever the window is re-sized
    /// @param[in]
    //----------------------------------------------------------------------------------------------------------------------
    void resizeGL(QResizeEvent *_event); //overloaded function that is automatically called when the window is resized
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called whenever the window is re-sized
    /// @param[in] _w the width of the resized window
    /// @param[in] _h the height of the resized window
    //----------------------------------------------------------------------------------------------------------------------
    void resizeGL(int _w,int _h);
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief the width of the window
    //----------------------------------------------------------------------------------------------------------------------
    int m_width;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief the height of the window
    //----------------------------------------------------------------------------------------------------------------------
    int m_height;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief view perspective matrix
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_vp;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief pointer to tornado object that creates all the particle information
    //----------------------------------------------------------------------------------------------------------------------
    Tornado *m_tornado;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief tarray that holds the pixel infromation of the screen to save them to an image
    //----------------------------------------------------------------------------------------------------------------------
    GLubyte *m_pixels;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief vertex array object that holds the infomration about the particle system positions
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_vao;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief second vertex array object that holds the particle positions
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_vao2;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief controlls position of camera
    //----------------------------------------------------------------------------------------------------------------------
    int m_zoom;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief controlls X rotation of tornado
    //----------------------------------------------------------------------------------------------------------------------
    int m_angleX;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief controlls Z rotation of tornado
    //----------------------------------------------------------------------------------------------------------------------
    int m_angleZ;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief controlls the look at position and the height of the tornado
    //----------------------------------------------------------------------------------------------------------------------
    int m_gridCenter;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief keeps track of the time measure by frame
    //----------------------------------------------------------------------------------------------------------------------
    int m_time;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief render status controlling if its rendering or not
    //----------------------------------------------------------------------------------------------------------------------
    int m_render;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief particle size passed to the point size
    //----------------------------------------------------------------------------------------------------------------------
    int m_particleSize;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief particle system size that is passed to the point size
    //----------------------------------------------------------------------------------------------------------------------
    int m_particleSubSysSize;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds string that includes texure path and name
    //----------------------------------------------------------------------------------------------------------------------
    QString m_texureName;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the text that displays the frames
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<ngl::Text> m_text;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief background colour
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_bgColour;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief holds the texture
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_texture;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief controlls if the depth sorting function is called or not
    //----------------------------------------------------------------------------------------------------------------------
    bool m_depthSortState;



};


#endif // NGL_CONTEXT_H
