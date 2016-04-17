/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *TornadoBox;
    QGridLayout *gridLayout_5;
    QSpinBox *Height;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QSpinBox *Point1Z;
    QSpinBox *CurveCount;
    QLabel *label_12;
    QSpinBox *Point2Z;
    QSpinBox *Point2X;
    QSpinBox *Point1X;
    QLabel *label_5;
    QSpinBox *Point3Z;
    QSpinBox *Point3X;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_9;
    QDoubleSpinBox *radiusMin;
    QLabel *label_11;
    QDoubleSpinBox *radiusMax;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QSpinBox *ParticleCount;
    QLabel *label_6;
    QCheckBox *particleOnOff;
    QLabel *label_10;
    QSpinBox *ParticleSystemSize;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QSpinBox *ParticleSize;
    QLabel *label_8;
    QLabel *label_7;
    QCheckBox *DephtTest;
    QLineEdit *texureSlot;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QPushButton *RotateUp;
    QPushButton *zoomOut;
    QPushButton *zoomIn;
    QPushButton *Right;
    QPushButton *RotateDown;
    QPushButton *Left;
    QLabel *BGCol_label;
    QDoubleSpinBox *BG_green;
    QDoubleSpinBox *BG_red;
    QPushButton *Up;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Down;
    QDoubleSpinBox *BG_blue;
    QGroupBox *advancedControlls;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QLabel *label_17;
    QLabel *label_19;
    QSpinBox *minLifetime;
    QSpinBox *maxLifeTime;
    QComboBox *MovementSelection;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_2;
    QSpinBox *ParticleSysTreshold;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QSpinBox *startValue;
    QSpinBox *PickUpTime;
    QLabel *label_13;
    QDoubleSpinBox *PickUpRadius;
    QSpinBox *CloudHeight;
    QSpinBox *ProductionRate;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_24;
    QDoubleSpinBox *RadiusGrowth;
    QDoubleSpinBox *SpeedUp;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QSpinBox *ParticleProduction;
    QLabel *label_20;
    QSpacerItem *verticalSpacer;
    QPushButton *m_restartButton;
    QPushButton *m_RenderButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(601, 931);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 569, 1257));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        TornadoBox = new QGroupBox(groupBox);
        TornadoBox->setObjectName(QStringLiteral("TornadoBox"));
        gridLayout_5 = new QGridLayout(TornadoBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        Height = new QSpinBox(TornadoBox);
        Height->setObjectName(QStringLiteral("Height"));
        Height->setMaximum(100000);
        Height->setSingleStep(10);
        Height->setValue(400);

        gridLayout_5->addWidget(Height, 2, 1, 1, 2);

        groupBox_2 = new QGroupBox(TornadoBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        Point1Z = new QSpinBox(groupBox_2);
        Point1Z->setObjectName(QStringLiteral("Point1Z"));
        Point1Z->setMinimum(-1000);
        Point1Z->setMaximum(1000);
        Point1Z->setValue(10);

        gridLayout->addWidget(Point1Z, 3, 2, 1, 1);

        CurveCount = new QSpinBox(groupBox_2);
        CurveCount->setObjectName(QStringLiteral("CurveCount"));
        CurveCount->setMinimum(1);
        CurveCount->setMaximum(3);
        CurveCount->setValue(3);

        gridLayout->addWidget(CurveCount, 1, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 1, 1, 1);

        Point2Z = new QSpinBox(groupBox_2);
        Point2Z->setObjectName(QStringLiteral("Point2Z"));
        Point2Z->setMinimum(-1000);
        Point2Z->setMaximum(1000);
        Point2Z->setValue(-50);

        gridLayout->addWidget(Point2Z, 4, 2, 1, 1);

        Point2X = new QSpinBox(groupBox_2);
        Point2X->setObjectName(QStringLiteral("Point2X"));
        Point2X->setMinimum(-1000);
        Point2X->setMaximum(1000);
        Point2X->setValue(-70);

        gridLayout->addWidget(Point2X, 4, 1, 1, 1);

        Point1X = new QSpinBox(groupBox_2);
        Point1X->setObjectName(QStringLiteral("Point1X"));
        Point1X->setMinimum(-1000);
        Point1X->setMaximum(1000);
        Point1X->setValue(130);

        gridLayout->addWidget(Point1X, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        Point3Z = new QSpinBox(groupBox_2);
        Point3Z->setObjectName(QStringLiteral("Point3Z"));
        Point3Z->setMinimum(-1000);
        Point3Z->setMaximum(1000);
        Point3Z->setValue(100);

        gridLayout->addWidget(Point3Z, 5, 2, 1, 1);

        Point3X = new QSpinBox(groupBox_2);
        Point3X->setObjectName(QStringLiteral("Point3X"));
        Point3X->setMinimum(-1000);
        Point3X->setMaximum(1000);
        Point3X->setValue(50);

        gridLayout->addWidget(Point3X, 5, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 3);

        label_9 = new QLabel(TornadoBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        radiusMin = new QDoubleSpinBox(TornadoBox);
        radiusMin->setObjectName(QStringLiteral("radiusMin"));
        radiusMin->setMaximum(100);
        radiusMin->setValue(4);

        gridLayout_5->addWidget(radiusMin, 3, 1, 1, 1);

        label_11 = new QLabel(TornadoBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 3, 0, 1, 1);

        radiusMax = new QDoubleSpinBox(TornadoBox);
        radiusMax->setObjectName(QStringLiteral("radiusMax"));
        radiusMax->setMaximum(100);
        radiusMax->setValue(8);

        gridLayout_5->addWidget(radiusMax, 3, 2, 1, 1);


        verticalLayout->addWidget(TornadoBox);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        ParticleCount = new QSpinBox(groupBox_3);
        ParticleCount->setObjectName(QStringLiteral("ParticleCount"));
        ParticleCount->setMinimum(1);

        gridLayout_3->addWidget(ParticleCount, 2, 3, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 2, 2, 1, 1);

        particleOnOff = new QCheckBox(groupBox_3);
        particleOnOff->setObjectName(QStringLiteral("particleOnOff"));

        gridLayout_3->addWidget(particleOnOff, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        ParticleSystemSize = new QSpinBox(groupBox_3);
        ParticleSystemSize->setObjectName(QStringLiteral("ParticleSystemSize"));
        ParticleSystemSize->setMinimum(1);
        ParticleSystemSize->setMaximum(100);
        ParticleSystemSize->setValue(4);

        gridLayout_3->addWidget(ParticleSystemSize, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ParticleSize = new QSpinBox(groupBox_4);
        ParticleSize->setObjectName(QStringLiteral("ParticleSize"));
        ParticleSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ParticleSize->setMinimum(1);
        ParticleSize->setMaximum(200);
        ParticleSize->setValue(15);

        gridLayout_4->addWidget(ParticleSize, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        DephtTest = new QCheckBox(groupBox_4);
        DephtTest->setObjectName(QStringLiteral("DephtTest"));

        gridLayout_4->addWidget(DephtTest, 1, 2, 1, 1);

        texureSlot = new QLineEdit(groupBox_4);
        texureSlot->setObjectName(QStringLiteral("texureSlot"));

        gridLayout_4->addWidget(texureSlot, 5, 1, 1, 2);


        verticalLayout->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        RotateUp = new QPushButton(groupBox_6);
        RotateUp->setObjectName(QStringLiteral("RotateUp"));

        gridLayout_6->addWidget(RotateUp, 2, 3, 1, 1);

        zoomOut = new QPushButton(groupBox_6);
        zoomOut->setObjectName(QStringLiteral("zoomOut"));

        gridLayout_6->addWidget(zoomOut, 0, 0, 1, 1);

        zoomIn = new QPushButton(groupBox_6);
        zoomIn->setObjectName(QStringLiteral("zoomIn"));

        gridLayout_6->addWidget(zoomIn, 0, 3, 1, 1);

        Right = new QPushButton(groupBox_6);
        Right->setObjectName(QStringLiteral("Right"));

        gridLayout_6->addWidget(Right, 1, 3, 1, 1);

        RotateDown = new QPushButton(groupBox_6);
        RotateDown->setObjectName(QStringLiteral("RotateDown"));

        gridLayout_6->addWidget(RotateDown, 2, 0, 1, 1);

        Left = new QPushButton(groupBox_6);
        Left->setObjectName(QStringLiteral("Left"));

        gridLayout_6->addWidget(Left, 1, 0, 1, 1);

        BGCol_label = new QLabel(groupBox_6);
        BGCol_label->setObjectName(QStringLiteral("BGCol_label"));

        gridLayout_6->addWidget(BGCol_label, 3, 0, 1, 1);

        BG_green = new QDoubleSpinBox(groupBox_6);
        BG_green->setObjectName(QStringLiteral("BG_green"));
        BG_green->setMaximum(1);
        BG_green->setSingleStep(0.05);
        BG_green->setValue(1);

        gridLayout_6->addWidget(BG_green, 3, 2, 1, 1);

        BG_red = new QDoubleSpinBox(groupBox_6);
        BG_red->setObjectName(QStringLiteral("BG_red"));
        BG_red->setMaximum(1);
        BG_red->setSingleStep(0.05);
        BG_red->setValue(1);

        gridLayout_6->addWidget(BG_red, 3, 1, 1, 1);

        Up = new QPushButton(groupBox_6);
        Up->setObjectName(QStringLiteral("Up"));

        gridLayout_6->addWidget(Up, 0, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 1, 1, 2);

        Down = new QPushButton(groupBox_6);
        Down->setObjectName(QStringLiteral("Down"));

        gridLayout_6->addWidget(Down, 2, 1, 1, 2);

        BG_blue = new QDoubleSpinBox(groupBox_6);
        BG_blue->setObjectName(QStringLiteral("BG_blue"));
        BG_blue->setMaximum(1);
        BG_blue->setSingleStep(0.05);
        BG_blue->setValue(1);

        gridLayout_6->addWidget(BG_blue, 3, 3, 1, 1);


        verticalLayout->addWidget(groupBox_6);

        advancedControlls = new QGroupBox(groupBox);
        advancedControlls->setObjectName(QStringLiteral("advancedControlls"));
        gridLayout_7 = new QGridLayout(advancedControlls);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_8 = new QGroupBox(advancedControlls);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_17 = new QLabel(groupBox_8);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_8->addWidget(label_19, 1, 0, 1, 1);

        minLifetime = new QSpinBox(groupBox_8);
        minLifetime->setObjectName(QStringLiteral("minLifetime"));
        minLifetime->setMinimum(1);
        minLifetime->setMaximum(999);
        minLifetime->setValue(100);

        gridLayout_8->addWidget(minLifetime, 1, 1, 1, 1);

        maxLifeTime = new QSpinBox(groupBox_8);
        maxLifeTime->setObjectName(QStringLiteral("maxLifeTime"));
        maxLifeTime->setMinimum(2);
        maxLifeTime->setMaximum(1000);
        maxLifeTime->setValue(170);

        gridLayout_8->addWidget(maxLifeTime, 1, 2, 1, 1);

        MovementSelection = new QComboBox(groupBox_8);
        MovementSelection->setObjectName(QStringLiteral("MovementSelection"));
        MovementSelection->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        MovementSelection->setFrame(true);

        gridLayout_8->addWidget(MovementSelection, 0, 1, 1, 2);


        gridLayout_7->addWidget(groupBox_8, 3, 0, 1, 1);

        groupBox_10 = new QGroupBox(advancedControlls);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_2 = new QGridLayout(groupBox_10);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ParticleSysTreshold = new QSpinBox(groupBox_10);
        ParticleSysTreshold->setObjectName(QStringLiteral("ParticleSysTreshold"));
        ParticleSysTreshold->setMaximum(100000);
        ParticleSysTreshold->setSingleStep(100);
        ParticleSysTreshold->setValue(20000);

        gridLayout_2->addWidget(ParticleSysTreshold, 2, 1, 1, 1);

        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        startValue = new QSpinBox(groupBox_10);
        startValue->setObjectName(QStringLiteral("startValue"));
        startValue->setMaximum(200);
        startValue->setValue(2);

        gridLayout_2->addWidget(startValue, 1, 1, 1, 1);

        PickUpTime = new QSpinBox(groupBox_10);
        PickUpTime->setObjectName(QStringLiteral("PickUpTime"));
        PickUpTime->setMaximum(500);
        PickUpTime->setValue(100);

        gridLayout_2->addWidget(PickUpTime, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_10);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        PickUpRadius = new QDoubleSpinBox(groupBox_10);
        PickUpRadius->setObjectName(QStringLiteral("PickUpRadius"));
        PickUpRadius->setMaximum(500);
        PickUpRadius->setValue(10);

        gridLayout_2->addWidget(PickUpRadius, 0, 3, 1, 1);

        CloudHeight = new QSpinBox(groupBox_10);
        CloudHeight->setObjectName(QStringLiteral("CloudHeight"));
        CloudHeight->setMaximum(400);
        CloudHeight->setValue(15);

        gridLayout_2->addWidget(CloudHeight, 1, 3, 1, 1);

        ProductionRate = new QSpinBox(groupBox_10);
        ProductionRate->setObjectName(QStringLiteral("ProductionRate"));
        ProductionRate->setValue(2);

        gridLayout_2->addWidget(ProductionRate, 2, 3, 1, 1);

        label_22 = new QLabel(groupBox_10);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 2, 2, 1, 1);

        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 2, 0, 1, 1);

        label_23 = new QLabel(groupBox_10);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 3, 0, 1, 1);

        label_24 = new QLabel(groupBox_10);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_2->addWidget(label_24, 3, 2, 1, 1);

        RadiusGrowth = new QDoubleSpinBox(groupBox_10);
        RadiusGrowth->setObjectName(QStringLiteral("RadiusGrowth"));
        RadiusGrowth->setMaximum(200);
        RadiusGrowth->setValue(55);

        gridLayout_2->addWidget(RadiusGrowth, 3, 3, 1, 1);

        SpeedUp = new QDoubleSpinBox(groupBox_10);
        SpeedUp->setObjectName(QStringLiteral("SpeedUp"));
        SpeedUp->setMinimum(0.01);
        SpeedUp->setSingleStep(0.1);
        SpeedUp->setValue(2);

        gridLayout_2->addWidget(SpeedUp, 3, 1, 1, 1);

        label_13->raise();
        PickUpTime->raise();
        startValue->raise();
        label_15->raise();
        label_14->raise();
        label_16->raise();
        PickUpRadius->raise();
        CloudHeight->raise();
        label_21->raise();
        ParticleSysTreshold->raise();
        label_22->raise();
        ProductionRate->raise();
        label_23->raise();
        label_24->raise();
        RadiusGrowth->raise();
        SpeedUp->raise();

        gridLayout_7->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(advancedControlls);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        ParticleProduction = new QSpinBox(groupBox_9);
        ParticleProduction->setObjectName(QStringLiteral("ParticleProduction"));
        ParticleProduction->setValue(1);

        gridLayout_10->addWidget(ParticleProduction, 1, 1, 1, 1);

        label_20 = new QLabel(groupBox_9);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_10->addWidget(label_20, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_9, 2, 0, 1, 1);


        verticalLayout->addWidget(advancedControlls);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_restartButton = new QPushButton(groupBox);
        m_restartButton->setObjectName(QStringLiteral("m_restartButton"));

        verticalLayout->addWidget(m_restartButton);

        m_RenderButton = new QPushButton(groupBox);
        m_RenderButton->setObjectName(QStringLiteral("m_RenderButton"));

        verticalLayout->addWidget(m_RenderButton);


        gridLayout_9->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        s_mainWindowGridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 601, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Tornado Creator", 0));
        TornadoBox->setTitle(QApplication::translate("MainWindow", "Tornado", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "ControlPoints", 0));
        label_4->setText(QApplication::translate("MainWindow", "Point2", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        label_12->setText(QApplication::translate("MainWindow", "Curves", 0));
        label_5->setText(QApplication::translate("MainWindow", "Point3", 0));
        label->setText(QApplication::translate("MainWindow", "Point1", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0));
        label_9->setText(QApplication::translate("MainWindow", "Tornado Height", 0));
        label_11->setText(QApplication::translate("MainWindow", "Radius Range", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Particle System", 0));
        label_6->setText(QApplication::translate("MainWindow", "Particle Count", 0));
        particleOnOff->setText(QApplication::translate("MainWindow", "Particles", 0));
        label_10->setText(QApplication::translate("MainWindow", "Particle System Size", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Particle", 0));
        label_8->setText(QApplication::translate("MainWindow", "Texture", 0));
        label_7->setText(QApplication::translate("MainWindow", "Particle Size", 0));
        DephtTest->setText(QApplication::translate("MainWindow", "Depth Sort", 0));
        texureSlot->setText(QApplication::translate("MainWindow", "textures/particles.png", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Window Controlls", 0));
        RotateUp->setText(QApplication::translate("MainWindow", "Rotate Up", 0));
        zoomOut->setText(QApplication::translate("MainWindow", "Zoom Out", 0));
        zoomIn->setText(QApplication::translate("MainWindow", "Zoom In", 0));
        Right->setText(QApplication::translate("MainWindow", "Right", 0));
        RotateDown->setText(QApplication::translate("MainWindow", "Rotate Down", 0));
        Left->setText(QApplication::translate("MainWindow", "Left", 0));
        BGCol_label->setText(QApplication::translate("MainWindow", "Background Colour", 0));
        Up->setText(QApplication::translate("MainWindow", "Up", 0));
        Down->setText(QApplication::translate("MainWindow", "Down", 0));
        advancedControlls->setTitle(QApplication::translate("MainWindow", "Advanced Controlls", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Particle", 0));
        label_17->setText(QApplication::translate("MainWindow", "Movement Type", 0));
        label_19->setText(QApplication::translate("MainWindow", "Life Time Range", 0));
        MovementSelection->clear();
        MovementSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tornado Center Attraction", 0)
         << QApplication::translate("MainWindow", "Random Points", 0)
        );
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Tornado", 0));
        label_15->setText(QApplication::translate("MainWindow", "Starting Value", 0));
        label_16->setText(QApplication::translate("MainWindow", "Cloud Height", 0));
        label_14->setText(QApplication::translate("MainWindow", "Pick Up Radius", 0));
        label_13->setText(QApplication::translate("MainWindow", "Pick Up Time", 0));
        label_22->setText(QApplication::translate("MainWindow", "Production Rate", 0));
        label_21->setText(QApplication::translate("MainWindow", "Particle System Treshold", 0));
        label_23->setText(QApplication::translate("MainWindow", "Upwards Speed", 0));
        label_24->setText(QApplication::translate("MainWindow", "Radius Growth", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Particle System", 0));
        label_20->setText(QApplication::translate("MainWindow", "Particle Production Rate", 0));
        m_restartButton->setText(QApplication::translate("MainWindow", "Reset", 0));
        m_RenderButton->setText(QApplication::translate("MainWindow", "Render", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
