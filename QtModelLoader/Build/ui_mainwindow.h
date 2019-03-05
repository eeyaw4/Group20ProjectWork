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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadSTLButton;
    QPushButton *loadModelButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEditR;
    QSlider *sliderR;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditG;
    QSlider *sliderG;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEditB;
    QSlider *sliderB;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *resetColourButton;
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

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
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


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEditR = new QLineEdit(centralwidget);
        lineEditR->setObjectName(QStringLiteral("lineEditR"));
        lineEditR->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(lineEditR);

        sliderR = new QSlider(centralwidget);
        sliderR->setObjectName(QStringLiteral("sliderR"));
        sliderR->setMaximum(100);
        sliderR->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderR);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEditG = new QLineEdit(centralwidget);
        lineEditG->setObjectName(QStringLiteral("lineEditG"));
        lineEditG->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(lineEditG);

        sliderG = new QSlider(centralwidget);
        sliderG->setObjectName(QStringLiteral("sliderG"));
        sliderG->setMaximum(100);
        sliderG->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderG);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lineEditB = new QLineEdit(centralwidget);
        lineEditB->setObjectName(QStringLiteral("lineEditB"));
        lineEditB->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_6->addWidget(lineEditB);

        sliderB = new QSlider(centralwidget);
        sliderB->setObjectName(QStringLiteral("sliderB"));
        sliderB->setMaximum(100);
        sliderB->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sliderB);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        resetColourButton = new QPushButton(centralwidget);
        resetColourButton->setObjectName(QStringLiteral("resetColourButton"));

        horizontalLayout_2->addWidget(resetColourButton);


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
        resetColourButton->setText(QApplication::translate("MainWindow", "Reset Colours", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
