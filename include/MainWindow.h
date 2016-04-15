#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NGL_Context.h"
#include "TornadoCurve.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public slots:
  /// @brief restart function that resets the tornado and ui
  void restart();


public:
  /// @brief constructor for our main window class
  /// @param _simple bool value that controlls the interface layout 0=advanced UI 1=simple UI
  /// @param [in] parent the parent widget to the class

  explicit MainWindow(bool _simple, QWidget *parent = 0);

  ///@brief destructor
  ~MainWindow();

private:
  /// @brief pointer to the Tornado Curve object
  TornadoCurve *m_curve;
  ///@brief pointer to the UI
  Ui::MainWindow *m_ui;
  ///@brief pointer to the NGL Scene
  NGL_Context *m_scene;


};

#endif // MAINWINDOW_H
