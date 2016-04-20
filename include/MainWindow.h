#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NGL_Context.h"
#include "TornadoCurve.h"
/// @file NGL_Context.h
/// @brief this class inherits from QOpenGLWidget
/// @author Carola Gille
/// @version 1.0
/// @date 15/04/16
/// @class NGL_Context
/// @brief Our Ngl Scene that is making a window that is used as a widget and displays the scene and the tornado


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public slots:
//----------------------------------------------------------------------------------------------------------------------
/// @brief reset function that resets the tornado and ui
//----------------------------------------------------------------------------------------------------------------------
    void reset();


public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief constructor for our main window class
  /// @param[in] _simple bool value that controlls the interface layout 0=advanced UI 1=simple UI
  /// @param[in] parent the parent widget to the class
  //----------------------------------------------------------------------------------------------------------------------
    explicit MainWindow(bool _simple, QWidget *parent = 0);
//----------------------------------------------------------------------------------------------------------------------
///@brief destructor
//----------------------------------------------------------------------------------------------------------------------
  ~MainWindow();

private:
//----------------------------------------------------------------------------------------------------------------------
/// @brief pointer to the Tornado Curve object
//----------------------------------------------------------------------------------------------------------------------
  TornadoCurve *m_curve;
//----------------------------------------------------------------------------------------------------------------------
///@brief pointer to the UI
//----------------------------------------------------------------------------------------------------------------------
  Ui::MainWindow *m_ui;
//----------------------------------------------------------------------------------------------------------------------
///@brief pointer to the NGL Scene
//----------------------------------------------------------------------------------------------------------------------
  NGL_Context *m_scene;


};

#endif // MAINWINDOW_H
