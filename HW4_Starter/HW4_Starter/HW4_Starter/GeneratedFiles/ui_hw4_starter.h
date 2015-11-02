/********************************************************************************
** Form generated from reading UI file 'hw4_starter.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW4_STARTER_H
#define UI_HW4_STARTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HW4_StarterClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionExit_2;
    QWidget *centralWidget;
    QLabel *label;
    QDial *dial;
    QLabel *label_2;
    QPushButton *Read;
    QPushButton *Write;
    QTextEdit *messageEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *HW4_StarterClass)
    {
        if (HW4_StarterClass->objectName().isEmpty())
            HW4_StarterClass->setObjectName(QStringLiteral("HW4_StarterClass"));
        HW4_StarterClass->resize(932, 777);
        actionOpen = new QAction(HW4_StarterClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(HW4_StarterClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit_2 = new QAction(HW4_StarterClass);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        centralWidget = new QWidget(HW4_StarterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 821, 421));
        label->setFrameShape(QFrame::StyledPanel);
        label->setScaledContents(true);
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(70, 470, 111, 111));
        dial->setMinimum(1);
        dial->setMaximum(8);
        dial->setPageStep(2);
        dial->setNotchesVisible(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 600, 111, 16));
        Read = new QPushButton(centralWidget);
        Read->setObjectName(QStringLiteral("Read"));
        Read->setGeometry(QRect(770, 470, 91, 51));
        Write = new QPushButton(centralWidget);
        Write->setObjectName(QStringLiteral("Write"));
        Write->setGeometry(QRect(770, 530, 91, 51));
        messageEdit = new QTextEdit(centralWidget);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        messageEdit->setGeometry(QRect(200, 470, 541, 131));
        HW4_StarterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HW4_StarterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 932, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        HW4_StarterClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);

        retranslateUi(HW4_StarterClass);
        QObject::connect(actionExit_2, SIGNAL(triggered()), HW4_StarterClass, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), HW4_StarterClass, SLOT(loadFile()));
        QObject::connect(HW4_StarterClass, SIGNAL(sendPixmap(QPixmap)), label, SLOT(setPixmap(QPixmap)));
        QObject::connect(Read, SIGNAL(clicked()), HW4_StarterClass, SLOT(handleReadButton()));
        QObject::connect(Read, SIGNAL(clicked()), messageEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(HW4_StarterClass);
    } // setupUi

    void retranslateUi(QMainWindow *HW4_StarterClass)
    {
        HW4_StarterClass->setWindowTitle(QApplication::translate("HW4_StarterClass", "HW4_Starter", 0));
        actionOpen->setText(QApplication::translate("HW4_StarterClass", "Open...", 0));
        actionExit->setText(QApplication::translate("HW4_StarterClass", "Exit", 0));
        actionExit_2->setText(QApplication::translate("HW4_StarterClass", "Exit", 0));
        label->setText(QApplication::translate("HW4_StarterClass", "TextLabel", 0));
        label_2->setText(QApplication::translate("HW4_StarterClass", "Number of Bits Used", 0));
        Read->setText(QApplication::translate("HW4_StarterClass", "Read", 0));
        Write->setText(QApplication::translate("HW4_StarterClass", "Write", 0));
        menuFile->setTitle(QApplication::translate("HW4_StarterClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class HW4_StarterClass: public Ui_HW4_StarterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW4_STARTER_H
