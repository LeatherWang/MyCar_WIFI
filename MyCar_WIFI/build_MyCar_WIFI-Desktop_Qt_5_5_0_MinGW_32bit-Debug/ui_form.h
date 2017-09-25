/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *positionX_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *positionY_label;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLabel *endA_label;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_20;
    QLabel *label_fuseX;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_22;
    QLabel *label_fuseY;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_24;
    QLabel *label_fuseA;
    QLabel *label_25;
    QFrame *line;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_tragetX;
    QLabel *label_10;
    QLineEdit *lineEdit_tragetY;
    QLabel *label_14;
    QPushButton *pushButton_sendTargetPosition;
    QLabel *label_sendCounter;
    QLineEdit *lineEdit_tragetZ;
    QLabel *label_15;
    QPushButton *pushButton_tenFont;
    QPushButton *pushButton_circle;
    QLabel *label_13;
    QLabel *label_11;
    QPushButton *clear_pushButton;
    QGroupBox *groupBox_3;
    QLabel *label_16;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QLabel *label_matPX;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QLabel *label_matPY;
    QTableWidget *tableWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_23;
    QLabel *label_matNo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_19;
    QLabel *label_maxprob;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_21;
    QLabel *label_prob;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_left;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_up;
    QPushButton *back_pushButton;
    QPushButton *pushButton_down;
    QPushButton *pushButton_right;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *startX_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *startY_label;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *endX_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *endY_label;
    QLabel *label_9;
    QLabel *label_28;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(700, 700);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 280, 331, 121));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(1020, 1000));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 71, 16));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 76, 68));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(16, 16));

        horizontalLayout_5->addWidget(label_7);

        positionX_label = new QLabel(layoutWidget);
        positionX_label->setObjectName(QStringLiteral("positionX_label"));
        positionX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_5->addWidget(positionX_label);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(16, 16));

        horizontalLayout_6->addWidget(label_8);

        positionY_label = new QLabel(layoutWidget);
        positionY_label->setObjectName(QStringLiteral("positionY_label"));
        positionY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_6->addWidget(positionY_label);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);

        endA_label = new QLabel(layoutWidget);
        endA_label->setObjectName(QStringLiteral("endA_label"));
        endA_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_8->addWidget(endA_label);


        verticalLayout_3->addLayout(horizontalLayout_8);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(240, 40, 76, 68));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_20 = new QLabel(layoutWidget_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(16, 16));

        horizontalLayout_11->addWidget(label_20);

        label_fuseX = new QLabel(layoutWidget_3);
        label_fuseX->setObjectName(QStringLiteral("label_fuseX"));
        label_fuseX->setMinimumSize(QSize(50, 16));

        horizontalLayout_11->addWidget(label_fuseX);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_22 = new QLabel(layoutWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(16, 16));

        horizontalLayout_12->addWidget(label_22);

        label_fuseY = new QLabel(layoutWidget_3);
        label_fuseY->setObjectName(QStringLiteral("label_fuseY"));
        label_fuseY->setMinimumSize(QSize(50, 16));

        horizontalLayout_12->addWidget(label_fuseY);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_24 = new QLabel(layoutWidget_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_15->addWidget(label_24);

        label_fuseA = new QLabel(layoutWidget_3);
        label_fuseA->setObjectName(QStringLiteral("label_fuseA"));
        label_fuseA->setMinimumSize(QSize(50, 16));

        horizontalLayout_15->addWidget(label_fuseA);


        verticalLayout_5->addLayout(horizontalLayout_15);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(220, 20, 71, 16));
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(355, 0, 3, 700));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(530, 410, 161, 131));
        lineEdit_tragetX = new QLineEdit(groupBox_2);
        lineEdit_tragetX->setObjectName(QStringLiteral("lineEdit_tragetX"));
        lineEdit_tragetX->setGeometry(QRect(30, 20, 61, 20));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 16, 21));
        lineEdit_tragetY = new QLineEdit(groupBox_2);
        lineEdit_tragetY->setObjectName(QStringLiteral("lineEdit_tragetY"));
        lineEdit_tragetY->setGeometry(QRect(30, 50, 61, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 50, 16, 21));
        pushButton_sendTargetPosition = new QPushButton(groupBox_2);
        pushButton_sendTargetPosition->setObjectName(QStringLiteral("pushButton_sendTargetPosition"));
        pushButton_sendTargetPosition->setGeometry(QRect(100, 20, 51, 40));
        label_sendCounter = new QLabel(groupBox_2);
        label_sendCounter->setObjectName(QStringLiteral("label_sendCounter"));
        label_sendCounter->setGeometry(QRect(10, 110, 91, 16));
        lineEdit_tragetZ = new QLineEdit(groupBox_2);
        lineEdit_tragetZ->setObjectName(QStringLiteral("lineEdit_tragetZ"));
        lineEdit_tragetZ->setGeometry(QRect(30, 80, 61, 20));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 80, 16, 21));
        pushButton_tenFont = new QPushButton(groupBox_2);
        pushButton_tenFont->setObjectName(QStringLiteral("pushButton_tenFont"));
        pushButton_tenFont->setGeometry(QRect(100, 70, 51, 25));
        pushButton_circle = new QPushButton(groupBox_2);
        pushButton_circle->setObjectName(QStringLiteral("pushButton_circle"));
        pushButton_circle->setGeometry(QRect(100, 100, 51, 25));
        label_13 = new QLabel(Form);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(360, 610, 91, 91));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/image/img/axid.PNG")));
        label_13->setScaledContents(true);
        label_11 = new QLabel(Form);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 680, 61, 21));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_11->setFont(font);
        clear_pushButton = new QPushButton(Form);
        clear_pushButton->setObjectName(QStringLiteral("clear_pushButton"));
        clear_pushButton->setGeometry(QRect(360, 560, 80, 40));
        clear_pushButton->setMinimumSize(QSize(70, 0));
        clear_pushButton->setMaximumSize(QSize(200, 50));
        groupBox_3 = new QGroupBox(Form);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 10, 331, 261));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(210, 180, 101, 16));
        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(220, 200, 76, 44));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_17 = new QLabel(layoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(16, 16));

        horizontalLayout_9->addWidget(label_17);

        label_matPX = new QLabel(layoutWidget_2);
        label_matPX->setObjectName(QStringLiteral("label_matPX"));
        label_matPX->setMinimumSize(QSize(50, 16));

        horizontalLayout_9->addWidget(label_matPX);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(16, 16));

        horizontalLayout_10->addWidget(label_18);

        label_matPY = new QLabel(layoutWidget_2);
        label_matPY->setObjectName(QStringLiteral("label_matPY"));
        label_matPY->setMinimumSize(QSize(50, 16));

        horizontalLayout_10->addWidget(label_matPY);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 281, 151));
        tableWidget->horizontalHeader()->setDefaultSectionSize(80);
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 180, 162, 68));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_14->addWidget(label_23);

        label_matNo = new QLabel(layoutWidget1);
        label_matNo->setObjectName(QStringLiteral("label_matNo"));
        label_matNo->setMinimumSize(QSize(50, 16));

        horizontalLayout_14->addWidget(label_matNo);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_13->addWidget(label_19);

        label_maxprob = new QLabel(layoutWidget1);
        label_maxprob->setObjectName(QStringLiteral("label_maxprob"));
        label_maxprob->setMinimumSize(QSize(50, 16));

        horizontalLayout_13->addWidget(label_maxprob);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_7->addWidget(label_21);

        label_prob = new QLabel(layoutWidget1);
        label_prob->setObjectName(QStringLiteral("label_prob"));
        label_prob->setMinimumSize(QSize(50, 16));

        horizontalLayout_7->addWidget(label_prob);


        verticalLayout_6->addLayout(horizontalLayout_7);

        groupBox_5 = new QGroupBox(Form);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(510, 550, 181, 151));
        layoutWidget2 = new QWidget(groupBox_5);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 11, 166, 136));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        pushButton_left = new QPushButton(layoutWidget2);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));
        pushButton_left->setMinimumSize(QSize(50, 35));
        pushButton_left->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/img/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_left->setIcon(icon);

        horizontalLayout_16->addWidget(pushButton_left);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_up = new QPushButton(layoutWidget2);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setMinimumSize(QSize(50, 35));
        pushButton_up->setMaximumSize(QSize(50, 35));
        pushButton_up->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/img/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_up->setIcon(icon1);

        verticalLayout_7->addWidget(pushButton_up);

        back_pushButton = new QPushButton(layoutWidget2);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setMinimumSize(QSize(50, 50));
        back_pushButton->setMaximumSize(QSize(50, 50));

        verticalLayout_7->addWidget(back_pushButton);

        pushButton_down = new QPushButton(layoutWidget2);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setMinimumSize(QSize(50, 35));
        pushButton_down->setMaximumSize(QSize(50, 35));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/img/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_down->setIcon(icon2);

        verticalLayout_7->addWidget(pushButton_down);


        horizontalLayout_16->addLayout(verticalLayout_7);

        pushButton_right = new QPushButton(layoutWidget2);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));
        pushButton_right->setMinimumSize(QSize(50, 35));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/img/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_right->setIcon(icon3);

        horizontalLayout_16->addWidget(pushButton_right);

        layoutWidget3 = new QWidget(Form);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(370, 430, 76, 44));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(16, 16));

        horizontalLayout->addWidget(label_2);

        startX_label = new QLabel(layoutWidget3);
        startX_label->setObjectName(QStringLiteral("startX_label"));
        startX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout->addWidget(startX_label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(16, 16));

        horizontalLayout_2->addWidget(label_3);

        startY_label = new QLabel(layoutWidget3);
        startY_label->setObjectName(QStringLiteral("startY_label"));
        startY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_2->addWidget(startY_label);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget4 = new QWidget(Form);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(450, 490, 76, 44));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(label_4);

        endX_label = new QLabel(layoutWidget4);
        endX_label->setObjectName(QStringLiteral("endX_label"));
        endX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_3->addWidget(endX_label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(16, 16));

        horizontalLayout_4->addWidget(label_5);

        endY_label = new QLabel(layoutWidget4);
        endY_label->setObjectName(QStringLiteral("endY_label"));
        endY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_4->addWidget(endY_label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_9 = new QLabel(Form);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(450, 470, 54, 12));
        label_28 = new QLabel(Form);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(370, 410, 71, 16));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        groupBox->setTitle(QApplication::translate("Form", "robot\344\275\215\347\275\256\344\274\260\350\256\241", 0));
        label->setText(QApplication::translate("Form", "\347\274\226\347\240\201\345\231\250\345\256\232\344\275\215\357\274\232", 0));
        label_7->setText(QApplication::translate("Form", "X:", 0));
        positionX_label->setText(QApplication::translate("Form", "**", 0));
        label_8->setText(QApplication::translate("Form", "Y:", 0));
        positionY_label->setText(QApplication::translate("Form", "**", 0));
        label_12->setText(QApplication::translate("Form", "R:", 0));
        endA_label->setText(QApplication::translate("Form", "**", 0));
        label_20->setText(QApplication::translate("Form", "X:", 0));
        label_fuseX->setText(QApplication::translate("Form", "**", 0));
        label_22->setText(QApplication::translate("Form", "Y:", 0));
        label_fuseY->setText(QApplication::translate("Form", "**", 0));
        label_24->setText(QApplication::translate("Form", "R:", 0));
        label_fuseA->setText(QApplication::translate("Form", "**", 0));
        label_25->setText(QApplication::translate("Form", "\350\236\215\345\220\210\344\275\215\347\275\256\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("Form", "\346\216\247\345\210\266\345\231\250", 0));
        lineEdit_tragetX->setText(QApplication::translate("Form", "0", 0));
        label_10->setText(QApplication::translate("Form", "X:", 0));
        lineEdit_tragetY->setText(QApplication::translate("Form", "0", 0));
        label_14->setText(QApplication::translate("Form", "Y:", 0));
        pushButton_sendTargetPosition->setText(QApplication::translate("Form", "\345\217\221\351\200\201", 0));
        label_sendCounter->setText(QApplication::translate("Form", "\345\267\262\345\217\221\351\200\2010\345\270\247", 0));
        lineEdit_tragetZ->setText(QApplication::translate("Form", "0", 0));
        label_15->setText(QApplication::translate("Form", "Z:", 0));
        pushButton_tenFont->setText(QApplication::translate("Form", "\345\215\201\345\255\227", 0));
        pushButton_circle->setText(QApplication::translate("Form", "\350\207\252\346\227\213", 0));
        label_13->setText(QString());
        label_11->setText(QApplication::translate("Form", "\345\215\225\344\275\215\357\274\232cm", 0));
        clear_pushButton->setText(QApplication::translate("Form", "\346\270\205\351\231\244\350\275\250\350\277\271", 0));
        groupBox_3->setTitle(QApplication::translate("Form", "WiFi\345\256\232\344\275\215", 0));
        label_16->setText(QApplication::translate("Form", "\345\214\271\351\205\215\350\256\255\347\273\203\347\202\271\344\275\215\347\275\256\357\274\232", 0));
        label_17->setText(QApplication::translate("Form", "X:", 0));
        label_matPX->setText(QApplication::translate("Form", "**", 0));
        label_18->setText(QApplication::translate("Form", "Y:", 0));
        label_matPY->setText(QApplication::translate("Form", "**", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Form", "\351\207\207\346\240\267\347\202\271\345\235\207\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Form", "\345\214\271\351\205\215\347\202\271\345\235\207\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Form", "\345\267\256\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Form", "AP1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Form", "AP2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Form", "AP3", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Form", "AP4", 0));
        label_23->setText(QApplication::translate("Form", "\345\275\223\345\211\215\345\214\271\351\205\215\347\202\271\347\274\226\345\217\267\357\274\232", 0));
        label_matNo->setText(QApplication::translate("Form", "**", 0));
        label_19->setText(QApplication::translate("Form", "  \346\234\200\345\244\247\344\274\274\347\204\266\346\246\202\347\216\207\357\274\232", 0));
        label_maxprob->setText(QApplication::translate("Form", "**", 0));
        label_21->setText(QApplication::translate("Form", "      \350\257\245\347\202\271\346\246\202\347\216\207\357\274\232", 0));
        label_prob->setText(QApplication::translate("Form", "**", 0));
        groupBox_5->setTitle(QApplication::translate("Form", "\351\201\245\346\216\247\345\231\250", 0));
        pushButton_left->setText(QString());
        pushButton_up->setText(QString());
        back_pushButton->setText(QApplication::translate("Form", "0.0", 0));
        pushButton_down->setText(QString());
        pushButton_right->setText(QString());
        label_2->setText(QApplication::translate("Form", "X:", 0));
        startX_label->setText(QApplication::translate("Form", "**", 0));
        label_3->setText(QApplication::translate("Form", "Y:", 0));
        startY_label->setText(QApplication::translate("Form", "**", 0));
        label_4->setText(QApplication::translate("Form", "X:", 0));
        endX_label->setText(QApplication::translate("Form", "**", 0));
        label_5->setText(QApplication::translate("Form", "Y:", 0));
        endY_label->setText(QApplication::translate("Form", "**", 0));
        label_9->setText(QApplication::translate("Form", "\347\233\256\346\240\207\347\202\271\357\274\232", 0));
        label_28->setText(QApplication::translate("Form", "\345\210\235\345\247\213\345\214\226\344\275\215\347\275\256\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
