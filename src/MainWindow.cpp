#include "include/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);

  ngl::Vec3 control1(130.0f,+10.0f,100.0f);
  ngl::Vec3 control2(-70.0f,-50.0f,100.0f);
  ngl::Vec3 control3(50.0f,100.0f,100.0f);
  ngl::Vec3 controlpoints[3]={control1,control2,control3};

  Tornado *tornado1 = new Tornado(300,controlpoints,400);

  m_scene=new NGL_Context(this, tornado1);
  m_ui->s_mainWindowGridLayout->addWidget(m_scene,0,0,1,1);

  connect(m_ui->m_RenderButton,SIGNAL(clicked()),m_scene,SLOT(renderOnOff()));
  connect(m_ui->m_restartButton,SIGNAL(clicked()),this,SLOT(test()));
  connect(m_ui->ParticleCount,SIGNAL(valueChanged(int)),tornado1, SLOT(changeParticleCount(int)));
  connect(m_ui->particleOnOff,SIGNAL(toggled(bool)),tornado1,SLOT(particlesOnOff(bool)));
  connect(m_ui->ParticleSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSize(int)));
  connect(m_ui->ParticleSystemSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSubSys(int)));
}

MainWindow::~MainWindow()
{
  delete m_ui;
  delete m_scene;

}
void MainWindow::test()
{
  std::cout<<"button clicked\n";
}
