#include "include/MainWindow.h"
#include "ui_MainWindow.h"



MainWindow::MainWindow(bool _simple, QWidget *parent) :QMainWindow(parent),m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);

  m_curve= new TornadoCurve(300);
  Tornado *tornado1 = new Tornado(m_curve);


  m_scene=new NGL_Context(this, tornado1);
  m_ui->s_mainWindowGridLayout->addWidget(m_scene,0,0,1,2);
  //QRect size=m_ui->s_mainWindowGridLayout->cellRect(0,0);

 // int simple=_simple-'0';
  //std::cout<<simple<<std::endl;


  connect(m_ui->Down,SIGNAL(clicked(bool)),m_scene,SLOT(down()));
  connect(m_ui->Up,SIGNAL(clicked(bool)),m_scene,SLOT(up()));
  connect(m_ui->Left,SIGNAL(clicked(bool)),m_scene,SLOT(left()));
  connect(m_ui->Right,SIGNAL(clicked(bool)),m_scene,SLOT(right()));
  connect(m_ui->RotateDown,SIGNAL(clicked(bool)),m_scene,SLOT(rotateDown()));
  connect(m_ui->RotateUp,SIGNAL(clicked(bool)),m_scene,SLOT(rotateUp()));
  connect(m_ui->zoomIn,SIGNAL(clicked(bool)),m_scene,SLOT(zoomIn()));
  connect(m_ui->zoomOut,SIGNAL(clicked(bool)),m_scene,SLOT(zoomOut()));

  connect(m_ui->m_RenderButton,SIGNAL(clicked()),m_scene,SLOT(renderOnOff()));
  connect(m_ui->m_restartButton,SIGNAL(clicked()),this,SLOT(restart()));

  connect(m_ui->ParticleCount,SIGNAL(valueChanged(int)),tornado1, SLOT(changeParticleCount(int)));
  connect(m_ui->particleOnOff,SIGNAL(toggled(bool)),tornado1,SLOT(particlesOnOff(bool)));
  connect(m_ui->ParticleSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSize(int)));
  connect(m_ui->ParticleSystemSize,SIGNAL(valueChanged(int)),m_scene,SLOT(changeParticleSubSys(int)));
  connect(m_ui->DephtTest,SIGNAL(toggled(bool)),m_scene,SLOT(setDepthsortValue(bool)));
  connect(m_ui->texureSlot,SIGNAL(textChanged(QString)),m_scene,SLOT(setTexure(QString)));


  connect(m_scene,SIGNAL(resetParticleSize(int)),m_ui->ParticleSize,SLOT(setValue(int)));
  connect(m_scene,SIGNAL(resetParticleSysSize(int)),m_ui->ParticleSystemSize,SLOT(setValue(int)));
  connect(m_scene,SIGNAL(resetTexure(QString)),m_ui->texureSlot,SLOT(setText(QString)));
  connect(tornado1,SIGNAL(resetparticlesOnOff(bool)),m_ui->particleOnOff,SLOT(setChecked(bool)));
  connect(tornado1,SIGNAL(resetParticleCount(int)),m_ui->ParticleCount,SLOT(setValue(int)));
  connect(m_scene,SIGNAL(resetDepthsortValue(bool)),m_ui->DephtTest,SLOT(setChecked(bool)));

  if (_simple)
  {



    m_ui->BG_red->hide();
    m_ui->BG_green->hide();
    m_ui->BG_blue->hide();

    m_ui->advancedControlls->hide();
    m_ui->TornadoBox->hide();
    m_ui->BGCol_label->hide();
  }

  else
  {

  connect(m_ui->Point1X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint1X(int)));
  connect(m_ui->Point1Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint1Z(int)));
  connect(m_ui->Point2X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint2X(int)));
  connect(m_ui->Point2Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint2Z(int)));
  connect(m_ui->Point3X,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint3X(int)));
  connect(m_ui->Point3Z,SIGNAL(valueChanged(int)),m_curve,SLOT(setControllPoint3Z(int)));
  connect(m_ui->Height,SIGNAL(valueChanged(int)),m_curve,SLOT(setHeight(int)));
  connect(m_ui->Height,SIGNAL(valueChanged(int)),tornado1,SLOT(setHeight(int)));


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

  connect(m_ui->SpeedUp,SIGNAL(valueChanged(double)),m_curve,SLOT(setSpeedUp(double)));
  connect(m_ui->ParticleSysTreshold,SIGNAL(valueChanged(int)),tornado1,SLOT(setParticleSysTreshold(int)));
  connect(m_ui->ProductionRate,SIGNAL(valueChanged(int)),tornado1,SLOT(setProductionRate(int)));
  connect(m_ui->RadiusGrowth,SIGNAL(valueChanged(double)),m_curve,SLOT(setRadiusGrowth(double)));
  connect(m_ui->ParticleProduction,SIGNAL(valueChanged(int)),tornado1,SLOT(setParticleProductionRate(int)));

  connect(m_scene,SIGNAL(resetDepthsortValue(bool)),m_ui->DephtTest,SLOT(setChecked(bool)));
  connect(m_scene,SIGNAL(resetBGColourR(double)),m_ui->BG_red,SLOT(setValue(double)));
  connect(m_scene,SIGNAL(resetBGColourG(double)),m_ui->BG_green,SLOT(setValue(double)));
  connect(m_scene,SIGNAL(resetBGColourB(double)),m_ui->BG_blue,SLOT(setValue(double)));


  connect(tornado1,SIGNAL(resetRadiusMin(double)),m_ui->radiusMin,SLOT(setValue(double)));
  connect(tornado1,SIGNAL(resetRadiusMax(double)),m_ui->radiusMax,SLOT(setValue(double)));
  connect(tornado1,SIGNAL(resetCloudHeight(int)),m_ui->CloudHeight,SLOT(setValue(int)));
  connect(tornado1,SIGNAL(resetParticleSysTreshold(int)),m_ui->ParticleSysTreshold,SLOT(setValue(int)));
  connect(tornado1,SIGNAL(resetProductionRate(int)),m_ui->ProductionRate,SLOT(setValue(int)));
  connect(tornado1,SIGNAL(resetParticleProductionRate(int)),m_ui->ParticleProduction,SLOT(setValue(int)));
  connect(tornado1,SIGNAL(resetParticleMoveState(int)),m_ui->MovementSelection,SLOT(setCurrentIndex(int)));
  connect(tornado1,SIGNAL(resetParticleTimeRangeMin(int)),m_ui->minLifetime,SLOT(setValue(int)));
  connect(tornado1,SIGNAL(resetParticleTimeRangeMax(int)),m_ui->maxLifeTime,SLOT(setValue(int)));

  connect(m_curve,SIGNAL(resetCurveCount(int)),m_ui->CurveCount,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(disableCurve2(bool)),m_ui->Point2X,SLOT(setEnabled(bool)));
  connect(m_curve,SIGNAL(disableCurve2(bool)),m_ui->Point2Z,SLOT(setEnabled(bool)));
  connect(m_curve,SIGNAL(disableCurve3(bool)),m_ui->Point3X,SLOT(setEnabled(bool)));
  connect(m_curve,SIGNAL(disableCurve3(bool)),m_ui->Point3Z,SLOT(setEnabled(bool)));
  connect(m_curve,SIGNAL(resetControllPoint1X(int)),m_ui->Point1X,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetControllPoint1Z(int)),m_ui->Point1Z,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetControllPoint2X(int)),m_ui->Point2X,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetControllPoint2Z(int)),m_ui->Point2Z,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetControllPoint3X(int)),m_ui->Point3X,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetControllPoint3Z(int)),m_ui->Point3Z,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetHeight(int)),m_ui->Height,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetPickUpTime(int)),m_ui->PickUpTime,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetPickUpRadius(double)),m_ui->PickUpRadius,SLOT(setValue(double)));
  connect(m_curve,SIGNAL(resetStartValue(int)),m_ui->startValue,SLOT(setValue(int)));
  connect(m_curve,SIGNAL(resetSpeedUp(double)),m_ui->SpeedUp,SLOT(setValue(double)));
  connect(m_curve,SIGNAL(resetRadiusGrowth(double)),m_ui->RadiusGrowth,SLOT(setValue(double)));

  }

}




MainWindow::~MainWindow()
{
  delete m_ui;
  delete m_scene;
  delete m_curve;
}
void MainWindow::restart()
{
  m_scene->restart();
  m_curve->reset();

}




