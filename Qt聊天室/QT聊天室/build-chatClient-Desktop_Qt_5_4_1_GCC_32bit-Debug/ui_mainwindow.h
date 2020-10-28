/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QTextBrowser *allText;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *userlist;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *oneText;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *sendData;
    QPushButton *btn_SendAll;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *sendName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *sendData_2;
    QPushButton *btn_SendPer;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *leIP;
    QLabel *label_5;
    QLineEdit *lePort;
    QLabel *label_6;
    QLineEdit *leUserName;
    QPushButton *btn_Connect;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(875, 652);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 5, 1, 1);

        allText = new QTextBrowser(centralWidget);
        allText->setObjectName(QStringLiteral("allText"));
        allText->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(allText, 1, 0, 2, 2);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        userlist = new QTextBrowser(centralWidget);
        userlist->setObjectName(QStringLiteral("userlist"));

        gridLayout_2->addWidget(userlist, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        oneText = new QTextBrowser(centralWidget);
        oneText->setObjectName(QStringLiteral("oneText"));

        gridLayout_2->addWidget(oneText, 1, 5, 2, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sendData = new QLineEdit(centralWidget);
        sendData->setObjectName(QStringLiteral("sendData"));

        horizontalLayout_2->addWidget(sendData);

        btn_SendAll = new QPushButton(centralWidget);
        btn_SendAll->setObjectName(QStringLiteral("btn_SendAll"));

        horizontalLayout_2->addWidget(btn_SendAll);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        sendName = new QLineEdit(centralWidget);
        sendName->setObjectName(QStringLiteral("sendName"));

        horizontalLayout_3->addWidget(sendName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        sendData_2 = new QLineEdit(centralWidget);
        sendData_2->setObjectName(QStringLiteral("sendData_2"));

        horizontalLayout->addWidget(sendData_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        btn_SendPer = new QPushButton(centralWidget);
        btn_SendPer->setObjectName(QStringLiteral("btn_SendPer"));

        verticalLayout_2->addWidget(btn_SendPer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        leIP = new QLineEdit(centralWidget);
        leIP->setObjectName(QStringLiteral("leIP"));

        gridLayout->addWidget(leIP, 0, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lePort = new QLineEdit(centralWidget);
        lePort->setObjectName(QStringLiteral("lePort"));

        gridLayout->addWidget(lePort, 1, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        leUserName = new QLineEdit(centralWidget);
        leUserName->setObjectName(QStringLiteral("leUserName"));

        gridLayout->addWidget(leUserName, 2, 1, 1, 1);

        btn_Connect = new QPushButton(centralWidget);
        btn_Connect->setObjectName(QStringLiteral("btn_Connect"));

        gridLayout->addWidget(btn_Connect, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout_2, 2, 2, 2, 3);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 6, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 3, 7, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\276\244\350\201\212\346\241\206", 0));
        label->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\210\227\350\241\250", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\247\201\350\201\212\346\241\206", 0));
        btn_SendAll->setText(QApplication::translate("MainWindow", "\347\276\244\345\217\221", 0));
        label_8->setText(QApplication::translate("MainWindow", "\347\247\201\345\217\221\345\257\271\350\261\241", 0));
        label_7->setText(QApplication::translate("MainWindow", "\347\247\201\345\217\221\344\277\241\346\201\257", 0));
        btn_SendPer->setText(QApplication::translate("MainWindow", "\347\247\201\345\217\221", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        leIP->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_5->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\346\230\265\347\247\260", 0));
        lePort->setText(QApplication::translate("MainWindow", "10086", 0));
        label_6->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", 0));
        leUserName->setText(QApplication::translate("MainWindow", "jerry", 0));
        btn_Connect->setText(QApplication::translate("MainWindow", "\351\223\276\346\216\245", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\345\257\271\350\257\235\346\241\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
