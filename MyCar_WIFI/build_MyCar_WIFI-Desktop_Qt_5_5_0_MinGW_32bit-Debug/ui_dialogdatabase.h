/********************************************************************************
** Form generated from reading UI file 'dialogdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDATABASE_H
#define UI_DIALOGDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogdatabase
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *deletepushButton;
    QPushButton *refreshpushButton;

    void setupUi(QDialog *Dialogdatabase)
    {
        if (Dialogdatabase->objectName().isEmpty())
            Dialogdatabase->setObjectName(QStringLiteral("Dialogdatabase"));
        Dialogdatabase->resize(800, 480);
        Dialogdatabase->setMinimumSize(QSize(800, 480));
        horizontalLayout = new QHBoxLayout(Dialogdatabase);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(Dialogdatabase);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(Dialogdatabase);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        deletepushButton = new QPushButton(Dialogdatabase);
        deletepushButton->setObjectName(QStringLiteral("deletepushButton"));

        verticalLayout->addWidget(deletepushButton);

        refreshpushButton = new QPushButton(Dialogdatabase);
        refreshpushButton->setObjectName(QStringLiteral("refreshpushButton"));

        verticalLayout->addWidget(refreshpushButton);


        horizontalLayout->addLayout(verticalLayout);

        deletepushButton->raise();
        refreshpushButton->raise();
        tableView->raise();
        pushButton->raise();

        retranslateUi(Dialogdatabase);

        QMetaObject::connectSlotsByName(Dialogdatabase);
    } // setupUi

    void retranslateUi(QDialog *Dialogdatabase)
    {
        Dialogdatabase->setWindowTitle(QApplication::translate("Dialogdatabase", "Dialog", 0));
        pushButton->setText(QApplication::translate("Dialogdatabase", "\346\267\273\345\212\240\346\225\260\346\215\256", 0));
        deletepushButton->setText(QApplication::translate("Dialogdatabase", "\345\210\240\351\231\244\346\225\260\346\215\256", 0));
        refreshpushButton->setText(QApplication::translate("Dialogdatabase", "\345\210\267\346\226\260\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialogdatabase: public Ui_Dialogdatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDATABASE_H
