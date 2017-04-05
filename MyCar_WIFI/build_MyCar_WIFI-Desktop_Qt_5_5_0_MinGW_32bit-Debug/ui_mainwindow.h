/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_sendTCP;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_linkTCP;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_sendTCP;
    QLabel *messageLabel_linkTCPState;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_database;
    QPushButton *pushButton_showScope;
    QTextBrowser *textBrowser_acceptTCP;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_sendSer2net;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_linkSer2net;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_sendSer2net;
    QLabel *messageLabel_linkSer2netState;
    QTextBrowser *textBrowser_acceptSer2net;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_sendSerial;
    QPushButton *pushButton_openSerial;
    QLineEdit *lineEdit_sendSerial;
    QTextBrowser *textBrowser_acceptSerial;
    QComboBox *comboBox_findSeial;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(906, 636);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(340, 10, 276, 567));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_sendTCP = new QLineEdit(groupBox);
        lineEdit_sendTCP->setObjectName(QStringLiteral("lineEdit_sendTCP"));
        lineEdit_sendTCP->setMinimumSize(QSize(0, 0));
        lineEdit_sendTCP->setMaximumSize(QSize(440, 16777215));

        verticalLayout->addWidget(lineEdit_sendTCP);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_linkTCP = new QPushButton(groupBox);
        pushButton_linkTCP->setObjectName(QStringLiteral("pushButton_linkTCP"));
        pushButton_linkTCP->setMinimumSize(QSize(75, 0));
        pushButton_linkTCP->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(pushButton_linkTCP);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_sendTCP = new QPushButton(groupBox);
        pushButton_sendTCP->setObjectName(QStringLiteral("pushButton_sendTCP"));
        pushButton_sendTCP->setMinimumSize(QSize(75, 0));
        pushButton_sendTCP->setMaximumSize(QSize(75, 16777215));
        pushButton_sendTCP->setCheckable(false);
        pushButton_sendTCP->setAutoDefault(false);
        pushButton_sendTCP->setFlat(false);

        horizontalLayout->addWidget(pushButton_sendTCP);


        verticalLayout->addLayout(horizontalLayout);

        messageLabel_linkTCPState = new QLabel(groupBox);
        messageLabel_linkTCPState->setObjectName(QStringLiteral("messageLabel_linkTCPState"));
        messageLabel_linkTCPState->setMinimumSize(QSize(251, 0));
        messageLabel_linkTCPState->setMaximumSize(QSize(251, 16777215));

        verticalLayout->addWidget(messageLabel_linkTCPState);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_database = new QPushButton(groupBox);
        pushButton_database->setObjectName(QStringLiteral("pushButton_database"));
        pushButton_database->setMinimumSize(QSize(81, 41));
        pushButton_database->setMaximumSize(QSize(81, 41));

        horizontalLayout_2->addWidget(pushButton_database);

        pushButton_showScope = new QPushButton(groupBox);
        pushButton_showScope->setObjectName(QStringLiteral("pushButton_showScope"));
        pushButton_showScope->setMinimumSize(QSize(81, 41));
        pushButton_showScope->setMaximumSize(QSize(81, 41));

        horizontalLayout_2->addWidget(pushButton_showScope);


        verticalLayout->addLayout(horizontalLayout_2);

        textBrowser_acceptTCP = new QTextBrowser(groupBox);
        textBrowser_acceptTCP->setObjectName(QStringLiteral("textBrowser_acceptTCP"));
        textBrowser_acceptTCP->setMinimumSize(QSize(0, 411));

        verticalLayout->addWidget(textBrowser_acceptTCP);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(620, 10, 276, 567));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(27);
        sizePolicy.setVerticalStretch(56);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(276, 567));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_sendSer2net = new QLineEdit(groupBox_2);
        lineEdit_sendSer2net->setObjectName(QStringLiteral("lineEdit_sendSer2net"));
        lineEdit_sendSer2net->setMinimumSize(QSize(0, 0));
        lineEdit_sendSer2net->setMaximumSize(QSize(440, 16777215));

        verticalLayout_2->addWidget(lineEdit_sendSer2net);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_linkSer2net = new QPushButton(groupBox_2);
        pushButton_linkSer2net->setObjectName(QStringLiteral("pushButton_linkSer2net"));
        pushButton_linkSer2net->setMinimumSize(QSize(75, 0));
        pushButton_linkSer2net->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_3->addWidget(pushButton_linkSer2net);

        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_sendSer2net = new QPushButton(groupBox_2);
        pushButton_sendSer2net->setObjectName(QStringLiteral("pushButton_sendSer2net"));
        pushButton_sendSer2net->setMinimumSize(QSize(75, 0));
        pushButton_sendSer2net->setMaximumSize(QSize(75, 16777215));
        pushButton_sendSer2net->setCheckable(false);
        pushButton_sendSer2net->setAutoDefault(false);
        pushButton_sendSer2net->setFlat(false);

        horizontalLayout_3->addWidget(pushButton_sendSer2net);


        verticalLayout_2->addLayout(horizontalLayout_3);

        messageLabel_linkSer2netState = new QLabel(groupBox_2);
        messageLabel_linkSer2netState->setObjectName(QStringLiteral("messageLabel_linkSer2netState"));
        messageLabel_linkSer2netState->setMinimumSize(QSize(251, 0));
        messageLabel_linkSer2netState->setMaximumSize(QSize(251, 16777215));

        verticalLayout_2->addWidget(messageLabel_linkSer2netState);

        textBrowser_acceptSer2net = new QTextBrowser(groupBox_2);
        textBrowser_acceptSer2net->setObjectName(QStringLiteral("textBrowser_acceptSer2net"));

        verticalLayout_2->addWidget(textBrowser_acceptSer2net);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 301, 567));
        groupBox_3->setMinimumSize(QSize(276, 567));
        pushButton_sendSerial = new QPushButton(groupBox_3);
        pushButton_sendSerial->setObjectName(QStringLiteral("pushButton_sendSerial"));
        pushButton_sendSerial->setGeometry(QRect(200, 60, 75, 23));
        pushButton_sendSerial->setMinimumSize(QSize(75, 0));
        pushButton_sendSerial->setMaximumSize(QSize(75, 16777215));
        pushButton_sendSerial->setCheckable(false);
        pushButton_sendSerial->setAutoDefault(false);
        pushButton_sendSerial->setFlat(false);
        pushButton_openSerial = new QPushButton(groupBox_3);
        pushButton_openSerial->setObjectName(QStringLiteral("pushButton_openSerial"));
        pushButton_openSerial->setGeometry(QRect(120, 60, 75, 23));
        pushButton_openSerial->setMinimumSize(QSize(75, 0));
        pushButton_openSerial->setMaximumSize(QSize(75, 16777215));
        lineEdit_sendSerial = new QLineEdit(groupBox_3);
        lineEdit_sendSerial->setObjectName(QStringLiteral("lineEdit_sendSerial"));
        lineEdit_sendSerial->setGeometry(QRect(20, 33, 256, 20));
        lineEdit_sendSerial->setMinimumSize(QSize(0, 0));
        lineEdit_sendSerial->setMaximumSize(QSize(440, 16777215));
        textBrowser_acceptSerial = new QTextBrowser(groupBox_3);
        textBrowser_acceptSerial->setObjectName(QStringLiteral("textBrowser_acceptSerial"));
        textBrowser_acceptSerial->setGeometry(QRect(20, 130, 256, 411));
        textBrowser_acceptSerial->setMinimumSize(QSize(0, 411));
        comboBox_findSeial = new QComboBox(groupBox_3);
        comboBox_findSeial->setObjectName(QStringLiteral("comboBox_findSeial"));
        comboBox_findSeial->setGeometry(QRect(40, 60, 69, 22));
        pushButton_sendSer2net->raise();
        pushButton_linkSer2net->raise();
        lineEdit_sendSer2net->raise();
        pushButton_sendSerial->raise();
        pushButton_openSerial->raise();
        lineEdit_sendSerial->raise();
        textBrowser_acceptSerial->raise();
        comboBox_findSeial->raise();
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 906, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButton_sendTCP->setDefault(false);
        pushButton_sendSer2net->setDefault(false);
        pushButton_sendSerial->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "PC<-->\350\267\257\347\224\261\345\231\250", 0));
        pushButton_linkTCP->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        pushButton_sendTCP->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        messageLabel_linkTCPState->setText(QApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\346\234\252\350\277\236\346\216\245\357\274\201\357\274\201\357\274\201", 0));
        pushButton_database->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", 0));
        pushButton_showScope->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\263\242\345\275\242", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\350\267\257\347\224\261\345\231\250<-->\345\234\260\351\235\242\350\275\246", 0));
        pushButton_linkSer2net->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245ser2net", 0));
        pushButton_sendSer2net->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        messageLabel_linkSer2netState->setText(QApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\346\234\252\350\277\236\346\216\245\357\274\201\357\274\201\357\274\201", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButton_sendSerial->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        pushButton_openSerial->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
