/********************************************************************************
** Form generated from reading UI file 'scope.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPE_H
#define UI_SCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_scope
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customPlot;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_RSSI0Avg;
    QLabel *label_8;
    QLabel *label_RSSI0StardDev;
    QLabel *label;
    QLabel *label_RSSI0Value;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_RSSI1Avg;
    QLabel *label_4;
    QLabel *label_RSSI1StardDev;
    QLabel *label_RSSI1Value;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_RSSI2Avg;
    QLabel *label_6;
    QLabel *label_RSSI2StardDev;
    QLabel *label_RSSI2Value;
    QLabel *label_12;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QLabel *label_RSSI3Avg;
    QLabel *label_10;
    QLabel *label_RSSI3StardDev;
    QLabel *label_RSSI3Value;
    QLabel *label_13;

    void setupUi(QWidget *scope)
    {
        if (scope->objectName().isEmpty())
            scope->setObjectName(QStringLiteral("scope"));
        scope->resize(679, 547);
        horizontalLayout = new QHBoxLayout(scope);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customPlot = new QCustomPlot(scope);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(customPlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(scope);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(120, 80));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 40, 41, 16));
        label_RSSI0Avg = new QLabel(groupBox_3);
        label_RSSI0Avg->setObjectName(QStringLiteral("label_RSSI0Avg"));
        label_RSSI0Avg->setGeometry(QRect(60, 40, 54, 12));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 60, 41, 16));
        label_RSSI0StardDev = new QLabel(groupBox_3);
        label_RSSI0StardDev->setObjectName(QStringLiteral("label_RSSI0StardDev"));
        label_RSSI0StardDev->setGeometry(QRect(60, 60, 54, 12));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 54, 12));
        label_RSSI0Value = new QLabel(groupBox_3);
        label_RSSI0Value->setObjectName(QStringLiteral("label_RSSI0Value"));
        label_RSSI0Value->setGeometry(QRect(60, 20, 54, 12));

        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(scope);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(120, 80));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 41, 16));
        label_RSSI1Avg = new QLabel(groupBox);
        label_RSSI1Avg->setObjectName(QStringLiteral("label_RSSI1Avg"));
        label_RSSI1Avg->setGeometry(QRect(60, 40, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 41, 16));
        label_RSSI1StardDev = new QLabel(groupBox);
        label_RSSI1StardDev->setObjectName(QStringLiteral("label_RSSI1StardDev"));
        label_RSSI1StardDev->setGeometry(QRect(60, 60, 54, 12));
        label_RSSI1Value = new QLabel(groupBox);
        label_RSSI1Value->setObjectName(QStringLiteral("label_RSSI1Value"));
        label_RSSI1Value->setGeometry(QRect(60, 20, 54, 12));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 20, 54, 12));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scope);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(120, 80));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 41, 16));
        label_RSSI2Avg = new QLabel(groupBox_2);
        label_RSSI2Avg->setObjectName(QStringLiteral("label_RSSI2Avg"));
        label_RSSI2Avg->setGeometry(QRect(60, 40, 54, 12));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 60, 41, 16));
        label_RSSI2StardDev = new QLabel(groupBox_2);
        label_RSSI2StardDev->setObjectName(QStringLiteral("label_RSSI2StardDev"));
        label_RSSI2StardDev->setGeometry(QRect(60, 60, 54, 12));
        label_RSSI2Value = new QLabel(groupBox_2);
        label_RSSI2Value->setObjectName(QStringLiteral("label_RSSI2Value"));
        label_RSSI2Value->setGeometry(QRect(60, 20, 54, 12));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 54, 12));

        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(scope);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(120, 80));
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 40, 41, 16));
        label_RSSI3Avg = new QLabel(groupBox_4);
        label_RSSI3Avg->setObjectName(QStringLiteral("label_RSSI3Avg"));
        label_RSSI3Avg->setGeometry(QRect(60, 40, 54, 12));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 41, 16));
        label_RSSI3StardDev = new QLabel(groupBox_4);
        label_RSSI3StardDev->setObjectName(QStringLiteral("label_RSSI3StardDev"));
        label_RSSI3StardDev->setGeometry(QRect(60, 60, 54, 12));
        label_RSSI3Value = new QLabel(groupBox_4);
        label_RSSI3Value->setObjectName(QStringLiteral("label_RSSI3Value"));
        label_RSSI3Value->setGeometry(QRect(60, 20, 54, 12));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 20, 54, 12));

        verticalLayout->addWidget(groupBox_4);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(scope);

        QMetaObject::connectSlotsByName(scope);
    } // setupUi

    void retranslateUi(QWidget *scope)
    {
        scope->setWindowTitle(QApplication::translate("scope", "Form", 0));
        groupBox_3->setTitle(QApplication::translate("scope", "RSSI0-Robot101", 0));
        label_7->setText(QApplication::translate("scope", "\345\235\207\345\200\274\357\274\232", 0));
        label_RSSI0Avg->setText(QApplication::translate("scope", "**", 0));
        label_8->setText(QApplication::translate("scope", "\346\240\207\345\207\206\345\267\256\357\274\232", 0));
        label_RSSI0StardDev->setText(QApplication::translate("scope", "**", 0));
        label->setText(QApplication::translate("scope", "\345\275\223\345\211\215\345\200\274\357\274\232", 0));
        label_RSSI0Value->setText(QApplication::translate("scope", "**", 0));
        groupBox->setTitle(QApplication::translate("scope", "RSSI1-AP1_845", 0));
        label_2->setText(QApplication::translate("scope", "\345\235\207\345\200\274\357\274\232", 0));
        label_RSSI1Avg->setText(QApplication::translate("scope", "**", 0));
        label_4->setText(QApplication::translate("scope", "\346\240\207\345\207\206\345\267\256\357\274\232", 0));
        label_RSSI1StardDev->setText(QApplication::translate("scope", "**", 0));
        label_RSSI1Value->setText(QApplication::translate("scope", "**", 0));
        label_11->setText(QApplication::translate("scope", "\345\275\223\345\211\215\345\200\274\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("scope", "RSSI2-AP2_740", 0));
        label_5->setText(QApplication::translate("scope", "\345\235\207\345\200\274\357\274\232", 0));
        label_RSSI2Avg->setText(QApplication::translate("scope", "**", 0));
        label_6->setText(QApplication::translate("scope", "\346\240\207\345\207\206\345\267\256\357\274\232", 0));
        label_RSSI2StardDev->setText(QApplication::translate("scope", "**", 0));
        label_RSSI2Value->setText(QApplication::translate("scope", "**", 0));
        label_12->setText(QApplication::translate("scope", "\345\275\223\345\211\215\345\200\274\357\274\232", 0));
        groupBox_4->setTitle(QApplication::translate("scope", "RSSI3-OpenWrt703", 0));
        label_9->setText(QApplication::translate("scope", "\345\235\207\345\200\274\357\274\232", 0));
        label_RSSI3Avg->setText(QApplication::translate("scope", "**", 0));
        label_10->setText(QApplication::translate("scope", "\346\240\207\345\207\206\345\267\256\357\274\232", 0));
        label_RSSI3StardDev->setText(QApplication::translate("scope", "**", 0));
        label_RSSI3Value->setText(QApplication::translate("scope", "**", 0));
        label_13->setText(QApplication::translate("scope", "\345\275\223\345\211\215\345\200\274\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class scope: public Ui_scope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPE_H
