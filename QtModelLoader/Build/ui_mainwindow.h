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
#include <QtWidgets/QCheckBox>
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
    QLabel *lblObjects;
    QLabel *lblObjCount;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LblMaterial;
    QLabel *lblMat;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lblDensity;
    QLabel *lblDensValue;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lblWeight;
    QLabel *lblWeightValue;
    QSpacerItem *horizontalSpacer_6;
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
    QPushButton *btnModelColour;
    QPushButton *btnBGColour;
    QWidget *tabCS;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkCS;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkShrink;
    QSlider *slideShrink;
    QLabel *lblShrink;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 665);
        MainWindow->setMinimumSize(QSize(600, 0));
        MainWindow->setMaximumSize(QSize(16777066, 16777215));
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);
        qvtkWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(qvtkWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadSTLButton = new QPushButton(centralwidget);
        loadSTLButton->setObjectName(QStringLiteral("loadSTLButton"));
        loadSTLButton->setMinimumSize(QSize(0, 20));
        loadSTLButton->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(loadSTLButton);

        loadModelButton = new QPushButton(centralwidget);
        loadModelButton->setObjectName(QStringLiteral("loadModelButton"));
        loadModelButton->setMinimumSize(QSize(0, 20));
        loadModelButton->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(loadModelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 170));
        tabWidget->setMaximumSize(QSize(16777215, 160));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabBarAutoHide(false);
        tabInfo = new QWidget();
        tabInfo->setObjectName(QStringLiteral("tabInfo"));
        tabInfo->setEnabled(true);
        verticalLayout_5 = new QVBoxLayout(tabInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblObjects = new QLabel(tabInfo);
        lblObjects->setObjectName(QStringLiteral("lblObjects"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblObjects->sizePolicy().hasHeightForWidth());
        lblObjects->setSizePolicy(sizePolicy2);
        lblObjects->setMinimumSize(QSize(50, 0));
        lblObjects->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(lblObjects);

        lblObjCount = new QLabel(tabInfo);
        lblObjCount->setObjectName(QStringLiteral("lblObjCount"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblObjCount->sizePolicy().hasHeightForWidth());
        lblObjCount->setSizePolicy(sizePolicy3);
        lblObjCount->setMinimumSize(QSize(40, 0));
        lblObjCount->setCursor(QCursor(Qt::SizeVerCursor));
        lblObjCount->setScaledContents(false);

        horizontalLayout_4->addWidget(lblObjCount);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetMaximumSize);
        LblMaterial = new QLabel(tabInfo);
        LblMaterial->setObjectName(QStringLiteral("LblMaterial"));
        sizePolicy3.setHeightForWidth(LblMaterial->sizePolicy().hasHeightForWidth());
        LblMaterial->setSizePolicy(sizePolicy3);
        LblMaterial->setMinimumSize(QSize(50, 0));
        LblMaterial->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(LblMaterial);

        lblMat = new QLabel(tabInfo);
        lblMat->setObjectName(QStringLiteral("lblMat"));
        sizePolicy3.setHeightForWidth(lblMat->sizePolicy().hasHeightForWidth());
        lblMat->setSizePolicy(sizePolicy3);
        lblMat->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(lblMat);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lblDensity = new QLabel(tabInfo);
        lblDensity->setObjectName(QStringLiteral("lblDensity"));
        sizePolicy3.setHeightForWidth(lblDensity->sizePolicy().hasHeightForWidth());
        lblDensity->setSizePolicy(sizePolicy3);
        lblDensity->setMinimumSize(QSize(50, 0));
        lblDensity->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(lblDensity);

        lblDensValue = new QLabel(tabInfo);
        lblDensValue->setObjectName(QStringLiteral("lblDensValue"));
        sizePolicy3.setHeightForWidth(lblDensValue->sizePolicy().hasHeightForWidth());
        lblDensValue->setSizePolicy(sizePolicy3);
        lblDensValue->setMinimumSize(QSize(40, 0));

        horizontalLayout_8->addWidget(lblDensValue);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        lblWeight = new QLabel(tabInfo);
        lblWeight->setObjectName(QStringLiteral("lblWeight"));
        lblWeight->setMinimumSize(QSize(50, 0));
        lblWeight->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(lblWeight);

        lblWeightValue = new QLabel(tabInfo);
        lblWeightValue->setObjectName(QStringLiteral("lblWeightValue"));
        sizePolicy3.setHeightForWidth(lblWeightValue->sizePolicy().hasHeightForWidth());
        lblWeightValue->setSizePolicy(sizePolicy3);
        lblWeightValue->setMinimumSize(QSize(40, 0));
        lblWeightValue->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_9->addWidget(lblWeightValue);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_9);

        tabWidget->addTab(tabInfo, QString());
        tabColour = new QWidget();
        tabColour->setObjectName(QStringLiteral("tabColour"));
        tabColour->setEnabled(false);
        verticalLayout_4 = new QVBoxLayout(tabColour);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spinR = new QSpinBox(tabColour);
        spinR->setObjectName(QStringLiteral("spinR"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinR->sizePolicy().hasHeightForWidth());
        spinR->setSizePolicy(sizePolicy4);
        spinR->setMinimumSize(QSize(40, 0));
        spinR->setMaximumSize(QSize(40, 20));
        spinR->setMinimum(0);
        spinR->setMaximum(255);
        spinR->setValue(0);

        horizontalLayout_5->addWidget(spinR);

        lblR = new QLabel(tabColour);
        lblR->setObjectName(QStringLiteral("lblR"));
        sizePolicy3.setHeightForWidth(lblR->sizePolicy().hasHeightForWidth());
        lblR->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(lblG->sizePolicy().hasHeightForWidth());
        lblG->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
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

        btnModelColour = new QPushButton(tabColour);
        btnModelColour->setObjectName(QStringLiteral("btnModelColour"));

        horizontalLayout_2->addWidget(btnModelColour);

        btnBGColour = new QPushButton(tabColour);
        btnBGColour->setObjectName(QStringLiteral("btnBGColour"));

        horizontalLayout_2->addWidget(btnBGColour);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabColour, QString());
        tabCS = new QWidget();
        tabCS->setObjectName(QStringLiteral("tabCS"));
        tabCS->setEnabled(false);
        verticalLayout_3 = new QVBoxLayout(tabCS);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkCS = new QCheckBox(tabCS);
        checkCS->setObjectName(QStringLiteral("checkCS"));
        checkCS->setCheckable(true);

        verticalLayout_3->addWidget(checkCS);

        tabWidget->addTab(tabCS, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tab_8->setEnabled(false);
        verticalLayout_7 = new QVBoxLayout(tab_8);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkShrink = new QCheckBox(tab_8);
        checkShrink->setObjectName(QStringLiteral("checkShrink"));

        horizontalLayout_10->addWidget(checkShrink);

        slideShrink = new QSlider(tab_8);
        slideShrink->setObjectName(QStringLiteral("slideShrink"));
        slideShrink->setMinimum(1);
        slideShrink->setMaximum(100);
        slideShrink->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(slideShrink);

        lblShrink = new QLabel(tab_8);
        lblShrink->setObjectName(QStringLiteral("lblShrink"));

        horizontalLayout_10->addWidget(lblShrink);


        verticalLayout_7->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_8, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
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

        tabWidget->setCurrentIndex(3);


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
        lblWeight->setText(QApplication::translate("MainWindow", "Weight", nullptr));
        lblWeightValue->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabInfo), QApplication::translate("MainWindow", "Information", nullptr));
        lblR->setText(QApplication::translate("MainWindow", "Red", nullptr));
        lblG->setText(QApplication::translate("MainWindow", "Green", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        resetColourButton->setText(QApplication::translate("MainWindow", "Reset Colours", nullptr));
        btnModelColour->setText(QApplication::translate("MainWindow", "Change Model Colour", nullptr));
        btnBGColour->setText(QApplication::translate("MainWindow", "Change Background Colour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabColour), QApplication::translate("MainWindow", "Colour", nullptr));
        checkCS->setText(QApplication::translate("MainWindow", "Apply Cross Section", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCS), QApplication::translate("MainWindow", "Cross Section", nullptr));
        checkShrink->setText(QApplication::translate("MainWindow", "Apply Shrink Filter", nullptr));
        lblShrink->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Filters", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
