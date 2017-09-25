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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogdatabase
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_dbAddData;
    QPushButton *pushButton_dbDeleteData;
    QPushButton *pushButton_dbRefresh;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_dbDeleteAll;

    void setupUi(QDialog *Dialogdatabase)
    {
        if (Dialogdatabase->objectName().isEmpty())
            Dialogdatabase->setObjectName(QStringLiteral("Dialogdatabase"));
        Dialogdatabase->resize(808, 480);
        Dialogdatabase->setMinimumSize(QSize(800, 480));
        horizontalLayout = new QHBoxLayout(Dialogdatabase);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(Dialogdatabase);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setDefaultSectionSize(70);

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_dbAddData = new QPushButton(Dialogdatabase);
        pushButton_dbAddData->setObjectName(QStringLiteral("pushButton_dbAddData"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_dbAddData->sizePolicy().hasHeightForWidth());
        pushButton_dbAddData->setSizePolicy(sizePolicy);
        pushButton_dbAddData->setMinimumSize(QSize(75, 40));

        verticalLayout->addWidget(pushButton_dbAddData);

        pushButton_dbDeleteData = new QPushButton(Dialogdatabase);
        pushButton_dbDeleteData->setObjectName(QStringLiteral("pushButton_dbDeleteData"));
        pushButton_dbDeleteData->setMinimumSize(QSize(75, 40));

        verticalLayout->addWidget(pushButton_dbDeleteData);

        pushButton_dbRefresh = new QPushButton(Dialogdatabase);
        pushButton_dbRefresh->setObjectName(QStringLiteral("pushButton_dbRefresh"));
        pushButton_dbRefresh->setMinimumSize(QSize(75, 40));

        verticalLayout->addWidget(pushButton_dbRefresh);

        verticalSpacer = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_dbDeleteAll = new QPushButton(Dialogdatabase);
        pushButton_dbDeleteAll->setObjectName(QStringLiteral("pushButton_dbDeleteAll"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_dbDeleteAll->sizePolicy().hasHeightForWidth());
        pushButton_dbDeleteAll->setSizePolicy(sizePolicy1);
        pushButton_dbDeleteAll->setMinimumSize(QSize(85, 40));

        verticalLayout->addWidget(pushButton_dbDeleteAll);


        horizontalLayout->addLayout(verticalLayout);

        tableView->raise();

        retranslateUi(Dialogdatabase);

        QMetaObject::connectSlotsByName(Dialogdatabase);
    } // setupUi

    void retranslateUi(QDialog *Dialogdatabase)
    {
        Dialogdatabase->setWindowTitle(QApplication::translate("Dialogdatabase", "Dialog", 0));
        pushButton_dbAddData->setText(QApplication::translate("Dialogdatabase", "\346\267\273\345\212\240\346\225\260\346\215\256", 0));
        pushButton_dbDeleteData->setText(QApplication::translate("Dialogdatabase", "\345\210\240\351\231\244\346\225\260\346\215\256", 0));
        pushButton_dbRefresh->setText(QApplication::translate("Dialogdatabase", "\345\210\267\346\226\260\346\225\260\346\215\256", 0));
        pushButton_dbDeleteAll->setText(QApplication::translate("Dialogdatabase", "\345\210\240\351\231\244\346\211\200\346\234\211\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialogdatabase: public Ui_Dialogdatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDATABASE_H
