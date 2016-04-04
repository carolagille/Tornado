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

private:
  TornadoCurve *m_curve;
  Ui::MainWindow *m_ui;
  NGL_Context *m_scene;
};

#endif // MAINWINDOW_H
