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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *m_restartButton;
    QPushButton *m_RenderButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *spinBox_4;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
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
    QLineEdit *lineEdit;
    QSpinBox *ParticleSize;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1002, 592);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);

        m_restartButton = new QPushButton(groupBox);
        m_restartButton->setObjectName(QStringLiteral("m_restartButton"));

        gridLayout_2->addWidget(m_restartButton, 4, 2, 1, 1);

        m_RenderButton = new QPushButton(groupBox);
        m_RenderButton->setObjectName(QStringLiteral("m_RenderButton"));

        gridLayout_2->addWidget(m_RenderButton, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 2, 1, 1);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        spinBox_4 = new QSpinBox(groupBox_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        gridLayout->addWidget(spinBox_4, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        spinBox_5 = new QSpinBox(groupBox_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        gridLayout->addWidget(spinBox_5, 3, 1, 1, 1);

        spinBox_6 = new QSpinBox(groupBox_2);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));

        gridLayout->addWidget(spinBox_6, 3, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 2);

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
        ParticleSystemSize->setMinimum(1);
        ParticleSystemSize->setMaximum(100);

        gridLayout_3->addWidget(ParticleSystemSize, 6, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 1, 1, 1, 2);

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

        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 2, 0, 1, 2);

        ParticleSize = new QSpinBox(groupBox_4);
        ParticleSize->setObjectName(QStringLiteral("ParticleSize"));
        ParticleSize->setMinimum(1);
        ParticleSize->setMaximum(200);

        gridLayout_4->addWidget(ParticleSize, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 2, 1, 1, 2);


        s_mainWindowGridLayout->addWidget(groupBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1002, 27));
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
        m_restartButton->setText(QApplication::translate("MainWindow", "Restart", 0));
        m_RenderButton->setText(QApplication::translate("MainWindow", "Render", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "ControlPoints", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        label->setText(QApplication::translate("MainWindow", "Point1", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0));
        label_4->setText(QApplication::translate("MainWindow", "Point2", 0));
        label_5->setText(QApplication::translate("MainWindow", "Point3", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Particle System", 0));
        particleOnOff->setText(QApplication::translate("MainWindow", "Particles", 0));
        label_6->setText(QApplication::translate("MainWindow", "Particle Count", 0));
        label_10->setText(QApplication::translate("MainWindow", "Particle System Size", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Particle", 0));
        label_7->setText(QApplication::translate("MainWindow", "Particle Size", 0));
        label_8->setText(QApplication::translate("MainWindow", "Texure", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
