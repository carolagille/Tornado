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
  Tornado *tornado1 = new Tornado(400,m_curve);


  m_scene=new NGL_Context(this, tornado1);
  m_ui->s_mainWindowGridLayout->addWidget(m_scene,0,0,1,1);

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

  //remeber to connect height to tonado and tornado curve

}

MainWindow::~MainWindow()
{
  delete m_ui;
  delete m_scene;
  delete m_curve;
}
void MainWindow::restart()
{

  delete m_scene;
  delete m_curve;

  ngl::Vec3 control1(130.0f,+10.0f,100.0f);
  ngl::Vec3 control2(-70.0f,-50.0f,100.0f);
  ngl::Vec3 control3(50.0f,100.0f,100.0f);
  ngl::Vec3 controlpoints[3]={control1,control2,control3};
  m_curve= new TornadoCurve(300,controlpoints,400);
  Tornado *tornado1 = new Tornado(400,m_curve);


  m_scene=new NGL_Context(this, tornado1);
  m_ui->s_mainWindowGridLayout->addWidget(m_scene,0,0,1,1);
}
