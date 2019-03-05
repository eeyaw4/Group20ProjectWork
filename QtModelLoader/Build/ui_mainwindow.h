/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *tabColour;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinR;
    QSlider *slideR;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinG;
    QSlider *slideG;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinB;
    QSlider *slideB;
    QWidget *tabCS;
    QWidget *tab_7;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *resetColorButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(783, 728);
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
        tabColour = new QWidget();
        tabColour->setObjectName(QStringLiteral("tabColour"));
        verticalLayout_4 = new QVBoxLayout(tabColour);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spinR = new QSpinBox(tabColour);
        spinR->setObjectName(QStringLiteral("spinR"));
        spinR->setMinimum(0);
        spinR->setMaximum(255);
        spinR->setValue(0);

        horizontalLayout_5->addWidget(spinR);

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
        spinG->setMaximum(255);

        horizontalLayout_3->addWidget(spinG);

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
        spinB->setMaximum(255);

        horizontalLayout_6->addWidget(spinB);

        slideB = new QSlider(tabColour);
        slideB->setObjectName(QStringLiteral("slideB"));
        slideB->setMaximum(255);
        slideB->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(slideB);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tabWidget->addTab(tabColour, QString());
        tabCS = new QWidget();
        tabCS->setObjectName(QStringLiteral("tabCS"));
        tabWidget->addTab(tabCS, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget->addTab(tab_8, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        resetColorButton = new QPushButton(centralwidget);
        resetColorButton->setObjectName(QStringLiteral("resetColorButton"));

        horizontalLayout_2->addWidget(resetColorButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 783, 21));
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

        tabWidget->setCurrentIndex(0);


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
        tabWidget->setTabText(tabWidget->indexOf(tabColour), QApplication::translate("MainWindow", "Colour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCS), QApplication::translate("MainWindow", "Cross Section", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Page", nullptr));
        resetColorButton->setText(QApplication::translate("MainWindow", "Reset Colors", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
