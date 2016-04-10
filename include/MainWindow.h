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
  void restart();


public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void saveImage();
private:
  TornadoCurve *m_curve;
  Ui::MainWindow *m_ui;
  NGL_Context *m_scene;
  int m_renderState;

};

#endif // MAINWINDOW_H
