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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_serialSetting;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_serialSend;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_serialFind;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_serialOpen;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_serialSend;
    QLabel *label_serialState;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_showHex;
    QPushButton *pushButton_serialClearReceive;
    QPushButton *pushButton_openMap;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_serialSendHex;
    QPushButton *pushButton_serialClearSend;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_serialReceive;
    QPushButton *pushButton_serialClearCount;
    QLabel *label_serialSend;
    QTextBrowser *textBrowser_serialReceive;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_TCPSend;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_linkTCP;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_sendTCP;
    QLabel *messageLabel_linkTCPState;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_databaseOpen;
    QPushButton *pushButton_showScope;
    QLabel *label_tcpReceive;
    QTextBrowser *textBrowser_acceptTCP;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(604, 648);
        MainWindow->setMinimumSize(QSize(0, 380));
        action_serialSetting = new QAction(MainWindow);
        action_serialSetting->setObjectName(QStringLiteral("action_serialSetting"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(276, 400));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit_serialSend = new QTextEdit(groupBox_3);
        textEdit_serialSend->setObjectName(QStringLiteral("textEdit_serialSend"));
        textEdit_serialSend->setMinimumSize(QSize(0, 40));
        textEdit_serialSend->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(textEdit_serialSend);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        comboBox_serialFind = new QComboBox(groupBox_3);
        comboBox_serialFind->setObjectName(QStringLiteral("comboBox_serialFind"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_serialFind->sizePolicy().hasHeightForWidth());
        comboBox_serialFind->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(comboBox_serialFind);

        horizontalSpacer_4 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButton_serialOpen = new QPushButton(groupBox_3);
        pushButton_serialOpen->setObjectName(QStringLiteral("pushButton_serialOpen"));
        pushButton_serialOpen->setMinimumSize(QSize(75, 0));
        pushButton_serialOpen->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_6->addWidget(pushButton_serialOpen);

        horizontalSpacer_5 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        pushButton_serialSend = new QPushButton(groupBox_3);
        pushButton_serialSend->setObjectName(QStringLiteral("pushButton_serialSend"));
        pushButton_serialSend->setMinimumSize(QSize(75, 0));
        pushButton_serialSend->setMaximumSize(QSize(75, 16777215));
        pushButton_serialSend->setCheckable(false);
        pushButton_serialSend->setAutoDefault(false);
        pushButton_serialSend->setFlat(false);

        horizontalLayout_6->addWidget(pushButton_serialSend);


        verticalLayout_2->addLayout(horizontalLayout_6);

        label_serialState = new QLabel(groupBox_3);
        label_serialState->setObjectName(QStringLiteral("label_serialState"));
        label_serialState->setMinimumSize(QSize(251, 0));
        label_serialState->setMaximumSize(QSize(251, 16777215));

        verticalLayout_2->addWidget(label_serialState);

        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox_showHex = new QCheckBox(groupBox_3);
        checkBox_showHex->setObjectName(QStringLiteral("checkBox_showHex"));
        checkBox_showHex->setChecked(true);

        verticalLayout_4->addWidget(checkBox_showHex);

        pushButton_serialClearReceive = new QPushButton(groupBox_3);
        pushButton_serialClearReceive->setObjectName(QStringLiteral("pushButton_serialClearReceive"));
        sizePolicy1.setHeightForWidth(pushButton_serialClearReceive->sizePolicy().hasHeightForWidth());
        pushButton_serialClearReceive->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(pushButton_serialClearReceive);


        horizontalLayout_4->addLayout(verticalLayout_4);

        pushButton_openMap = new QPushButton(groupBox_3);
        pushButton_openMap->setObjectName(QStringLiteral("pushButton_openMap"));
        sizePolicy1.setHeightForWidth(pushButton_openMap->sizePolicy().hasHeightForWidth());
        pushButton_openMap->setSizePolicy(sizePolicy1);
        pushButton_openMap->setMinimumSize(QSize(0, 50));

        horizontalLayout_4->addWidget(pushButton_openMap);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkBox_serialSendHex = new QCheckBox(groupBox_3);
        checkBox_serialSendHex->setObjectName(QStringLiteral("checkBox_serialSendHex"));
        checkBox_serialSendHex->setChecked(true);

        verticalLayout_3->addWidget(checkBox_serialSendHex);

        pushButton_serialClearSend = new QPushButton(groupBox_3);
        pushButton_serialClearSend->setObjectName(QStringLiteral("pushButton_serialClearSend"));
        sizePolicy1.setHeightForWidth(pushButton_serialClearSend->sizePolicy().hasHeightForWidth());
        pushButton_serialClearSend->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton_serialClearSend);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_serialReceive = new QLabel(groupBox_3);
        label_serialReceive->setObjectName(QStringLiteral("label_serialReceive"));
        label_serialReceive->setMinimumSize(QSize(90, 0));
        label_serialReceive->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_5->addWidget(label_serialReceive);

        pushButton_serialClearCount = new QPushButton(groupBox_3);
        pushButton_serialClearCount->setObjectName(QStringLiteral("pushButton_serialClearCount"));
        pushButton_serialClearCount->setMinimumSize(QSize(62, 23));
        pushButton_serialClearCount->setMaximumSize(QSize(62, 23));

        horizontalLayout_5->addWidget(pushButton_serialClearCount);

        label_serialSend = new QLabel(groupBox_3);
        label_serialSend->setObjectName(QStringLiteral("label_serialSend"));
        label_serialSend->setMinimumSize(QSize(90, 0));
        label_serialSend->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_5->addWidget(label_serialSend);


        verticalLayout_2->addLayout(horizontalLayout_5);

        textBrowser_serialReceive = new QTextBrowser(groupBox_3);
        textBrowser_serialReceive->setObjectName(QStringLiteral("textBrowser_serialReceive"));
        textBrowser_serialReceive->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(textBrowser_serialReceive);


        horizontalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(276, 400));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit_TCPSend = new QTextEdit(groupBox);
        textEdit_TCPSend->setObjectName(QStringLiteral("textEdit_TCPSend"));
        textEdit_TCPSend->setMinimumSize(QSize(0, 40));
        textEdit_TCPSend->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(textEdit_TCPSend);

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
        messageLabel_linkTCPState->setMaximumSize(QSize(251, 14));

        verticalLayout->addWidget(messageLabel_linkTCPState);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_databaseOpen = new QPushButton(groupBox);
        pushButton_databaseOpen->setObjectName(QStringLiteral("pushButton_databaseOpen"));
        pushButton_databaseOpen->setMinimumSize(QSize(81, 41));
        pushButton_databaseOpen->setMaximumSize(QSize(81, 41));

        horizontalLayout_2->addWidget(pushButton_databaseOpen);

        pushButton_showScope = new QPushButton(groupBox);
        pushButton_showScope->setObjectName(QStringLiteral("pushButton_showScope"));
        pushButton_showScope->setMinimumSize(QSize(81, 41));
        pushButton_showScope->setMaximumSize(QSize(81, 41));

        horizontalLayout_2->addWidget(pushButton_showScope);


        verticalLayout->addLayout(horizontalLayout_2);

        label_tcpReceive = new QLabel(groupBox);
        label_tcpReceive->setObjectName(QStringLiteral("label_tcpReceive"));
        label_tcpReceive->setMinimumSize(QSize(249, 0));

        verticalLayout->addWidget(label_tcpReceive);

        textBrowser_acceptTCP = new QTextBrowser(groupBox);
        textBrowser_acceptTCP->setObjectName(QStringLiteral("textBrowser_acceptTCP"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser_acceptTCP->sizePolicy().hasHeightForWidth());
        textBrowser_acceptTCP->setSizePolicy(sizePolicy2);
        textBrowser_acceptTCP->setMinimumSize(QSize(0, 0));
        textBrowser_acceptTCP->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(textBrowser_acceptTCP);


        horizontalLayout_3->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 604, 23));
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
        menu->addAction(action_serialSetting);

        retranslateUi(MainWindow);

        pushButton_serialSend->setDefault(false);
        pushButton_sendTCP->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_serialSetting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\262\345\217\243", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\234\260\351\235\242\350\275\246<====(serial)====>PC", 0));
        pushButton_serialOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        pushButton_serialSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        label_serialState->setText(QApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\346\234\252\350\277\236\346\216\245\357\274\201\357\274\201\357\274\201", 0));
        checkBox_showHex->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\346\216\245\346\224\266", 0));
        pushButton_serialClearReceive->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266\345\214\272", 0));
        pushButton_openMap->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\234\260\345\233\276", 0));
        checkBox_serialSendHex->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        pushButton_serialClearSend->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", 0));
        label_serialReceive->setText(QApplication::translate("MainWindow", "**", 0));
        pushButton_serialClearCount->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\241\346\225\260", 0));
        label_serialSend->setText(QApplication::translate("MainWindow", "**", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "PC<====(TCP/IP)====>\350\267\257\347\224\261\345\231\250", 0));
        pushButton_linkTCP->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        pushButton_sendTCP->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        messageLabel_linkTCPState->setText(QApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\346\234\252\350\277\236\346\216\245\357\274\201\357\274\201\357\274\201", 0));
        pushButton_databaseOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256\345\272\223", 0));
        pushButton_showScope->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\263\242\345\275\242", 0));
        label_tcpReceive->setText(QApplication::translate("MainWindow", "**", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
