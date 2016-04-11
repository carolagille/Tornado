#include "include/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);

  ngl::Vec3 control1(130.0f,+10.0f,100.0f);
  ngl::Vec3 control2(-70.0f,-50.0f,100.0f);
  ngl::Vec3 control3(50.0f,100.0f,100.0f);
  ngl::Vec3 controlpoints[3]={control1,control2,control3};
  m_curve= new TornadoCurve(300,controlpoints,400);
  Tornado *tornado1 = new Tornado(m_curve);


  m_scene=new NGL_Context(this, tornado1);
  m_ui->s_mainWindowGridLayout->addWidget(m_scene,0,0,1,2);
  QRect size=m_ui->s_mainWindowGridLayout->cellRect(0,0);



  connect(m_ui->m_RenderButton,SIGNAL(clicked()),m_scene,SLOT(renderOnOff()));
  connect(m_ui->m_restartButton,SIGNAL(clicked()),this,SLOT(restart()));
  connect(m_ui->ParticleCount,SIGNAL(valueChanged(int)),tornado1, SLOT(changeParticleCount(int)));
  connect(m_ui->particleOnOff,SIGNAL(toggled(bool)),tornado1,SLOT(particlesOnOff(bool)));
  connect(m_ui->ParticleSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSize(int)));
  connect(m_ui->ParticleSystemSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSubSys(int)));
  connect(m_ui->Point1X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint1X(int)));
  connect(m_ui->Point1Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint1Z(int)));
  connect(m_ui->Point2X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint2X(int)));
  connect(m_ui->Point2Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint2Z(int)));
  connect(m_ui->Point3X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint3X(int)));
  connect(m_ui->Point3Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint3Z(int)));
  connect(m_ui->Height,SIGNAL(valueChanged(int)),m_curve,SLOT(setHeight(int)));
  connect(m_ui->Height,SIGNAL(valueChanged(int)),tornado1,SLOT(setHeight(int)));
  connect(m_ui->texureSlot,SIGNAL(textChanged(QString)),m_scene,SLOT(setTexure(QString)));
  connect(m_ui->Down,SIGNAL(clicked(bool)),m_scene,SLOT(down()));
  connect(m_ui->Up,SIGNAL(clicked(bool)),m_scene,SLOT(up()));
  connect(m_ui->Left,SIGNAL(clicked(bool)),m_scene,SLOT(left()));
  connect(m_ui->Right,SIGNAL(clicked(bool)),m_scene,SLOT(right()));
  connect(m_ui->RotateDown,SIGNAL(clicked(bool)),m_scene,SLOT(rotateDown()));
  connect(m_ui->RotateUp,SIGNAL(clicked(bool)),m_scene,SLOT(rotateUp()));
  connect(m_ui->zoomIn,SIGNAL(clicked(bool)),m_scene,SLOT(zoomIn()));
  connect(m_ui->zoomOut,SIGNAL(clicked(bool)),m_scene,SLOT(zoomOut()));
  connect(m_ui->CurveCount,SIGNAL(valueChanged(int)),m_curve,SLOT(setCurveCount(int)));
  connect(m_ui->radiusMin,SIGNAL(valueChanged(double)),tornado1,SLOT(setRadiusMin(double)));
  connect(m_ui->radiusMax,SIGNAL(valueChanged(double)),tornado1,SLOT(setRadiusMax(double)));
  connect(m_ui->PickUpTime,SIGNAL(valueChanged(int)),m_curve,SLOT(setPickUpTime(int)));
  connect(m_ui->PickUpRadius,SIGNAL(valueChanged(double)),m_curve,SLOT(setPickUpRadius(double)));
  connect(m_ui->startValue,SIGNAL(valueChanged(int)),m_curve,SLOT(setStartValue(int)));
  connect(m_ui->CloudHeight,SIGNAL(valueChanged(int)),tornado1,SLOT(setCloudHeight(int)));
  connect(m_ui->MovementSelection,SIGNAL(activated(int)),tornado1,SLOT(setParticleMoveState(int)));
  connect(m_ui->minLifetime,SIGNAL(valueChanged(int)),tornado1,SLOT(setParticleTimeRangeMin(int)));
  connect(m_ui->maxLifeTime,SIGNAL(valueChanged(int)),tornado1,SLOT(setParticleTimeRangeMax(int)));
  connect(m_ui->BG_red,SIGNAL(valueChanged(double)),m_scene,SLOT(setBGColourR(double)));
  connect(m_ui->BG_green,SIGNAL(valueChanged(double)),m_scene,SLOT(setBGColourG(double)));
  connect(m_ui->BG_blue,SIGNAL(valueChanged(double)),m_scene,SLOT(setBGColourB(double)));

  connect(m_scene,SIGNAL(resetParticleSize(int)),m_ui->ParticleSize,SLOT(setValue(int)));
  connect(m_scene,SIGNAL(resetParticleSysSize(int)),m_ui->ParticleSystemSize,SLOT(setValue(int)));
  connect(m_scene,SIGNAL(resetTexure(QString)),m_ui->texureSlot,SLOT(setText(QString)));



  connect(tornado1->m_curve,SIGNAL(disableCurve2(bool)),m_ui->Point2X,SLOT(setEnabled(bool)));
  connect(tornado1->m_curve,SIGNAL(disableCurve2(bool)),m_ui->Point2Z,SLOT(setEnabled(bool)));
  connect(tornado1->m_curve,SIGNAL(disableCurve3(bool)),m_ui->Point3X,SLOT(setEnabled(bool)));
  connect(tornado1->m_curve,SIGNAL(disableCurve3(bool)),m_ui->Point3Z,SLOT(setEnabled(bool)));
  //remeber to connect height to tonado and tornado curve

}

MainWindow::~MainWindow()
{
  delete m_ui;
  delete m_scene;
  delete m_curve;
}
void MainWindow::restart()
{ ngl::Vec3 control1(130.0f,+10.0f,100.0f);
  ngl::Vec3 control2(-70.0f,-50.0f,100.0f);
  ngl::Vec3 control3(50.0f,100.0f,100.0f);

  m_scene->restart();


  //ngl::Vec3 controlpoints[3]={control1,control2,control3};
 // m_curve= new TornadoCurve(300,controlpoints,400);



}


void MainWindow::saveImage()
{ //std::cout<<"Calling save image\n";


}


