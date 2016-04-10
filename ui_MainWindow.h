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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *radiusMax;
    QLabel *label_11;
    QDoubleSpinBox *radiusMin;
    QLabel *label_9;
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
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QSpinBox *ParticleCount;
    QCheckBox *particleOnOff;
    QLabel *label_6;
    QLabel *label_10;
    QSpinBox *ParticleSystemSize;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *texureSlot;
    QSpinBox *ParticleSize;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QPushButton *Left;
    QPushButton *Up;
    QPushButton *Right;
    QPushButton *Down;
    QPushButton *RotateDown;
    QPushButton *zoomIn;
    QPushButton *zoomOut;
    QPushButton *RotateUp;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_8;
    QGroupBox *groupBox_9;
    QGroupBox *groupBox_10;
    QSpacerItem *verticalSpacer;
    QPushButton *m_restartButton;
    QPushButton *m_RenderButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1250, 920);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 442, 984));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        radiusMax = new QDoubleSpinBox(groupBox_5);
        radiusMax->setObjectName(QStringLiteral("radiusMax"));
        radiusMax->setMaximum(100);
        radiusMax->setValue(8);

        gridLayout_5->addWidget(radiusMax, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 3, 0, 1, 1);

        radiusMin = new QDoubleSpinBox(groupBox_5);
        radiusMin->setObjectName(QStringLiteral("radiusMin"));
        radiusMin->setMaximum(100);
        radiusMin->setValue(4);

        gridLayout_5->addWidget(radiusMin, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        Height = new QSpinBox(groupBox_5);
        Height->setObjectName(QStringLiteral("Height"));
        Height->setMaximum(100000);
        Height->setSingleStep(10);
        Height->setValue(400);

        gridLayout_5->addWidget(Height, 2, 1, 1, 2);

        groupBox_2 = new QGroupBox(groupBox_5);
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


        verticalLayout->addWidget(groupBox_5);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        ParticleCount = new QSpinBox(groupBox_3);
        ParticleCount->setObjectName(QStringLiteral("ParticleCount"));
        ParticleCount->setMinimum(1);

        gridLayout_3->addWidget(ParticleCount, 2, 1, 1, 1);

        particleOnOff = new QCheckBox(groupBox_3);
        particleOnOff->setObjectName(QStringLiteral("particleOnOff"));

        gridLayout_3->addWidget(particleOnOff, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 5, 0, 1, 1);

        ParticleSystemSize = new QSpinBox(groupBox_3);
        ParticleSystemSize->setObjectName(QStringLiteral("ParticleSystemSize"));
        ParticleSystemSize->setMinimum(4);
        ParticleSystemSize->setMaximum(100);

        gridLayout_3->addWidget(ParticleSystemSize, 6, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        texureSlot = new QLineEdit(groupBox_4);
        texureSlot->setObjectName(QStringLiteral("texureSlot"));

        gridLayout_4->addWidget(texureSlot, 2, 0, 1, 2);

        ParticleSize = new QSpinBox(groupBox_4);
        ParticleSize->setObjectName(QStringLiteral("ParticleSize"));
        ParticleSize->setMinimum(4);
        ParticleSize->setMaximum(200);

        gridLayout_4->addWidget(ParticleSize, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Left = new QPushButton(groupBox_6);
        Left->setObjectName(QStringLiteral("Left"));

        gridLayout_6->addWidget(Left, 1, 0, 1, 1);

        Up = new QPushButton(groupBox_6);
        Up->setObjectName(QStringLiteral("Up"));

        gridLayout_6->addWidget(Up, 0, 2, 1, 1);

        Right = new QPushButton(groupBox_6);
        Right->setObjectName(QStringLiteral("Right"));

        gridLayout_6->addWidget(Right, 1, 3, 1, 1);

        Down = new QPushButton(groupBox_6);
        Down->setObjectName(QStringLiteral("Down"));

        gridLayout_6->addWidget(Down, 2, 2, 1, 1);

        RotateDown = new QPushButton(groupBox_6);
        RotateDown->setObjectName(QStringLiteral("RotateDown"));

        gridLayout_6->addWidget(RotateDown, 2, 0, 1, 1);

        zoomIn = new QPushButton(groupBox_6);
        zoomIn->setObjectName(QStringLiteral("zoomIn"));

        gridLayout_6->addWidget(zoomIn, 0, 3, 1, 1);

        zoomOut = new QPushButton(groupBox_6);
        zoomOut->setObjectName(QStringLiteral("zoomOut"));

        gridLayout_6->addWidget(zoomOut, 0, 0, 1, 1);

        RotateUp = new QPushButton(groupBox_6);
        RotateUp->setObjectName(QStringLiteral("RotateUp"));

        gridLayout_6->addWidget(RotateUp, 2, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));

        gridLayout_7->addWidget(groupBox_8, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(groupBox_7);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));

        gridLayout_7->addWidget(groupBox_9, 0, 1, 1, 1);

        groupBox_10 = new QGroupBox(groupBox_7);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));

        gridLayout_7->addWidget(groupBox_10, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_restartButton = new QPushButton(groupBox);
        m_restartButton->setObjectName(QStringLiteral("m_restartButton"));

        verticalLayout->addWidget(m_restartButton);

        m_RenderButton = new QPushButton(groupBox);
        m_RenderButton->setObjectName(QStringLiteral("m_RenderButton"));

        verticalLayout->addWidget(m_RenderButton);


        formLayout->setWidget(1, QFormLayout::LabelRole, groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        s_mainWindowGridLayout->addWidget(scrollArea, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1250, 27));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Tornado", 0));
        label_11->setText(QApplication::translate("MainWindow", "Radius Range", 0));
        label_9->setText(QApplication::translate("MainWindow", "Tornado Height", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "ControlPoints", 0));
        label_4->setText(QApplication::translate("MainWindow", "Point2", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        label_12->setText(QApplication::translate("MainWindow", "Curves", 0));
        label_5->setText(QApplication::translate("MainWindow", "Point3", 0));
        label->setText(QApplication::translate("MainWindow", "Point1", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Particle System", 0));
        particleOnOff->setText(QApplication::translate("MainWindow", "Particles", 0));
        label_6->setText(QApplication::translate("MainWindow", "Particle Count", 0));
        label_10->setText(QApplication::translate("MainWindow", "Particle System Size", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Particle", 0));
        label_7->setText(QApplication::translate("MainWindow", "Particle Size", 0));
        label_8->setText(QApplication::translate("MainWindow", "Texure", 0));
        texureSlot->setText(QApplication::translate("MainWindow", "textures/point.tif", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        Left->setText(QApplication::translate("MainWindow", "Left", 0));
        Up->setText(QApplication::translate("MainWindow", "Up", 0));
        Right->setText(QApplication::translate("MainWindow", "Right", 0));
        Down->setText(QApplication::translate("MainWindow", "Down", 0));
        RotateDown->setText(QApplication::translate("MainWindow", "Rotate Down", 0));
        zoomIn->setText(QApplication::translate("MainWindow", "Zoom In", 0));
        zoomOut->setText(QApplication::translate("MainWindow", "Zoom Out", 0));
        RotateUp->setText(QApplication::translate("MainWindow", "Rotate Up", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Advanced Controlls", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Particle", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Particle System", 0));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Tornado", 0));
        m_restartButton->setText(QApplication::translate("MainWindow", "Restart", 0));
        m_RenderButton->setText(QApplication::translate("MainWindow", "Render", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
