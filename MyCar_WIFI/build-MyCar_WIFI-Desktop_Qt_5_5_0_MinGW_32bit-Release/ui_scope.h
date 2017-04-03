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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_scope
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customPlot;

    void setupUi(QWidget *scope)
    {
        if (scope->objectName().isEmpty())
            scope->setObjectName(QStringLiteral("scope"));
        scope->resize(679, 547);
        horizontalLayout = new QHBoxLayout(scope);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customPlot = new QCustomPlot(scope);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        horizontalLayout->addWidget(customPlot);


        retranslateUi(scope);

        QMetaObject::connectSlotsByName(scope);
    } // setupUi

    void retranslateUi(QWidget *scope)
    {
        scope->setWindowTitle(QApplication::translate("scope", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class scope: public Ui_scope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPE_H
