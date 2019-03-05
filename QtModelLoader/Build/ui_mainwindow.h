/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvtkopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionHelp;
    QAction *actionPrint;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVTKOpenGLWidget *qvtkWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadSTLButton;
    QPushButton *loadModelButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tabInfo;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblObjects;
    QLabel *lblObjCount;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LblMaterial;
    QLabel *lblMat;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lblDensity;
    QLabel *lblDensValue;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tabColour;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinR;
    QLabel *lblR;
    QSlider *slideR;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinG;
    QLabel *lblG;
    QSlider *slideG;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinB;
    QLabel *label_3;
    QSlider *slideB;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *resetColourButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabCS;
    QWidget *tab_8;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 658);
        actionFileOpen = new QAction(MainWindow);
        actionFileOpen->setObjectName(QStringLiteral("actionFileOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileOpen->setIcon(icon);
        actionFileSave = new QAction(MainWindow);
        actionFileSave->setObjectName(QStringLiteral("actionFileSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileSave->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        qvtkWidget = new QVTKOpenGLWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(qvtkWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadSTLButton = new QPushButton(centralwidget);
        loadSTLButton->setObjectName(QStringLiteral("loadSTLButton"));

        horizontalLayout->addWidget(loadSTLButton);

        loadModelButton = new QPushButton(centralwidget);
        loadModelButton->setObjectName(QStringLiteral("loadModelButton"));

        horizontalLayout->addWidget(loadModelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabInfo = new QWidget();
        tabInfo->setObjectName(QStringLiteral("tabInfo"));
        verticalLayout_5 = new QVBoxLayout(tabInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetMaximumSize);
        lblObjects = new QLabel(tabInfo);
        lblObjects->setObjectName(QStringLiteral("lblObjects"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblObjects->sizePolicy().hasHeightForWidth());
        lblObjects->setSizePolicy(sizePolicy);
        lblObjects->setMinimumSize(QSize(50, 0));
        lblObjects->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(lblObjects);

        lblObjCount = new QLabel(tabInfo);
        lblObjCount->setObjectName(QStringLiteral("lblObjCount"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblObjCount->sizePolicy().hasHeightForWidth());
        lblObjCount->setSizePolicy(sizePolicy1);
        lblObjCount->setMinimumSize(QSize(40, 0));
        lblObjCount->setCursor(QCursor(Qt::SizeVerCursor));
        lblObjCount->setScaledContents(false);

        horizontalLayout_7->addWidget(lblObjCount);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        LblMaterial = new QLabel(tabInfo);
        LblMaterial->setObjectName(QStringLiteral("LblMaterial"));
        sizePolicy1.setHeightForWidth(LblMaterial->sizePolicy().hasHeightForWidth());
        LblMaterial->setSizePolicy(sizePolicy1);
        LblMaterial->setMinimumSize(QSize(50, 0));
        LblMaterial->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(LblMaterial);

        lblMat = new QLabel(tabInfo);
        lblMat->setObjectName(QStringLiteral("lblMat"));
        sizePolicy1.setHeightForWidth(lblMat->sizePolicy().hasHeightForWidth());
        lblMat->setSizePolicy(sizePolicy1);
        lblMat->setMinimumSize(QSize(40, 0));

        horizontalLayout_8->addWidget(lblMat);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        lblDensity = new QLabel(tabInfo);
        lblDensity->setObjectName(QStringLiteral("lblDensity"));
        sizePolicy1.setHeightForWidth(lblDensity->sizePolicy().hasHeightForWidth());
        lblDensity->setSizePolicy(sizePolicy1);
        lblDensity->setMinimumSize(QSize(50, 0));
        lblDensity->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(lblDensity);

        lblDensValue = new QLabel(tabInfo);
        lblDensValue->setObjectName(QStringLiteral("lblDensValue"));
        sizePolicy1.setHeightForWidth(lblDensValue->sizePolicy().hasHeightForWidth());
        lblDensValue->setSizePolicy(sizePolicy1);
        lblDensValue->setMinimumSize(QSize(40, 0));

        horizontalLayout_9->addWidget(lblDensValue);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_9);

        tabWidget->addTab(tabInfo, QString());
        tabColour = new QWidget();
        tabColour->setObjectName(QStringLiteral("tabColour"));
        verticalLayout_4 = new QVBoxLayout(tabColour);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spinR = new QSpinBox(tabColour);
        spinR->setObjectName(QStringLiteral("spinR"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinR->sizePolicy().hasHeightForWidth());
        spinR->setSizePolicy(sizePolicy2);
        spinR->setMinimumSize(QSize(40, 0));
        spinR->setMaximumSize(QSize(40, 20));
        spinR->setMinimum(0);
        spinR->setMaximum(255);
        spinR->setValue(0);

        horizontalLayout_5->addWidget(spinR);

        lblR = new QLabel(tabColour);
        lblR->setObjectName(QStringLiteral("lblR"));
        sizePolicy1.setHeightForWidth(lblR->sizePolicy().hasHeightForWidth());
        lblR->setSizePolicy(sizePolicy1);
        lblR->setMinimumSize(QSize(35, 0));
        lblR->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_5->addWidget(lblR);

        slideR = new QSlider(tabColour);
        slideR->setObjectName(QStringLiteral("slideR"));
        slideR->setMaximum(255);
        slideR->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(slideR);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        spinG = new QSpinBox(tabColour);
        spinG->setObjectName(QStringLiteral("spinG"));
        spinG->setMinimumSize(QSize(40, 0));
        spinG->setMaximumSize(QSize(40, 20));
        spinG->setMaximum(255);

        horizontalLayout_3->addWidget(spinG);

        lblG = new QLabel(tabColour);
        lblG->setObjectName(QStringLiteral("lblG"));
        sizePolicy1.setHeightForWidth(lblG->sizePolicy().hasHeightForWidth());
        lblG->setSizePolicy(sizePolicy1);
        lblG->setMinimumSize(QSize(35, 0));
        lblG->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_3->addWidget(lblG);

        slideG = new QSlider(tabColour);
        slideG->setObjectName(QStringLiteral("slideG"));
        slideG->setMaximum(255);
        slideG->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slideG);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        spinB = new QSpinBox(tabColour);
        spinB->setObjectName(QStringLiteral("spinB"));
        spinB->setMinimumSize(QSize(40, 0));
        spinB->setMaximumSize(QSize(40, 20));
        spinB->setMaximum(255);

        horizontalLayout_6->addWidget(spinB);

        label_3 = new QLabel(tabColour);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(35, 0));
        label_3->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_6->addWidget(label_3);

        slideB = new QSlider(tabColour);
        slideB->setObjectName(QStringLiteral("slideB"));
        slideB->setMaximum(255);
        slideB->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(slideB);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        resetColourButton = new QPushButton(tabColour);
        resetColourButton->setObjectName(QStringLiteral("resetColourButton"));
        resetColourButton->setMinimumSize(QSize(85, 0));

        horizontalLayout_2->addWidget(resetColourButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabColour, QString());
        tabCS = new QWidget();
        tabCS->setObjectName(QStringLiteral("tabCS"));
        tabWidget->addTab(tabCS, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget->addTab(tab_8, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 620, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileSave);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFileOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionFileSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
        loadSTLButton->setText(QApplication::translate("MainWindow", "Load STL", nullptr));
        loadModelButton->setText(QApplication::translate("MainWindow", "Load Model", nullptr));
        lblObjects->setText(QApplication::translate("MainWindow", "Objects", nullptr));
        lblObjCount->setText(QString());
        LblMaterial->setText(QApplication::translate("MainWindow", "Material", nullptr));
        lblMat->setText(QString());
        lblDensity->setText(QApplication::translate("MainWindow", "Density", nullptr));
        lblDensValue->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabInfo), QApplication::translate("MainWindow", "Information", nullptr));
        lblR->setText(QApplication::translate("MainWindow", "Red", nullptr));
        lblG->setText(QApplication::translate("MainWindow", "Green", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        resetColourButton->setText(QApplication::translate("MainWindow", "Reset Colours", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabColour), QApplication::translate("MainWindow", "Colour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCS), QApplication::translate("MainWindow", "Cross Section", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Page", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
