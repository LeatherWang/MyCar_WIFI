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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_9;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *endX_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *endY_label;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *positionX_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *positionY_label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *startX_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *startY_label;
    QLabel *label_12;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLabel *endA_label;
    QFrame *line;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *back_pushButton;
    QPushButton *clear_pushButton;
    QLabel *label_11;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(810, 700);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(706, 20, 100, 350));
        groupBox->setMinimumSize(QSize(100, 350));
        groupBox->setMaximumSize(QSize(100, 350));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 250, 54, 12));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 54, 12));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 110, 54, 12));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 130, 76, 44));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(label_4);

        endX_label = new QLabel(layoutWidget);
        endX_label->setObjectName(QStringLiteral("endX_label"));
        endX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_3->addWidget(endX_label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(16, 16));

        horizontalLayout_4->addWidget(label_5);

        endY_label = new QLabel(layoutWidget);
        endY_label->setObjectName(QStringLiteral("endY_label"));
        endY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_4->addWidget(endY_label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 270, 76, 44));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(16, 16));

        horizontalLayout_5->addWidget(label_7);

        positionX_label = new QLabel(layoutWidget_2);
        positionX_label->setObjectName(QStringLiteral("positionX_label"));
        positionX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_5->addWidget(positionX_label);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(16, 16));

        horizontalLayout_6->addWidget(label_8);

        positionY_label = new QLabel(layoutWidget_2);
        positionY_label->setObjectName(QStringLiteral("positionY_label"));
        positionY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_6->addWidget(positionY_label);


        verticalLayout_3->addLayout(horizontalLayout_6);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 76, 44));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(16, 16));

        horizontalLayout->addWidget(label_2);

        startX_label = new QLabel(layoutWidget1);
        startX_label->setObjectName(QStringLiteral("startX_label"));
        startX_label->setMinimumSize(QSize(50, 16));

        horizontalLayout->addWidget(startX_label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(16, 16));

        horizontalLayout_2->addWidget(label_3);

        startY_label = new QLabel(layoutWidget1);
        startY_label->setObjectName(QStringLiteral("startY_label"));
        startY_label->setMinimumSize(QSize(50, 16));

        horizontalLayout_2->addWidget(startY_label);


        verticalLayout->addLayout(horizontalLayout_2);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 190, 54, 12));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 74, 18));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(16, 16));

        horizontalLayout_7->addWidget(label_10);

        endA_label = new QLabel(groupBox);
        endA_label->setObjectName(QStringLiteral("endA_label"));
        endA_label->setGeometry(QRect(30, 210, 50, 16));
        endA_label->setMinimumSize(QSize(50, 16));
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(705, 0, 3, 700));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(710, 410, 91, 141));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 72, 108));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        back_pushButton = new QPushButton(layoutWidget3);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setMinimumSize(QSize(70, 50));
        back_pushButton->setMaximumSize(QSize(70, 50));

        verticalLayout_4->addWidget(back_pushButton);

        clear_pushButton = new QPushButton(layoutWidget3);
        clear_pushButton->setObjectName(QStringLiteral("clear_pushButton"));
        clear_pushButton->setMinimumSize(QSize(70, 50));
        clear_pushButton->setMaximumSize(QSize(70, 50));

        verticalLayout_4->addWidget(clear_pushButton);

        label_11 = new QLabel(Form);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(720, 570, 71, 71));
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_11->setFont(font);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        groupBox->setTitle(QApplication::translate("Form", "\345\260\217\350\275\246\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("Form", "\344\275\215\347\275\256\357\274\232", 0));
        label_6->setText(QApplication::translate("Form", "\350\265\267\347\202\271\357\274\232", 0));
        label_9->setText(QApplication::translate("Form", "\347\273\210\347\202\271\357\274\232", 0));
        label_4->setText(QApplication::translate("Form", "X:", 0));
        endX_label->setText(QApplication::translate("Form", "\346\234\252\347\237\245", 0));
        label_5->setText(QApplication::translate("Form", "Y:", 0));
        endY_label->setText(QApplication::translate("Form", "\346\234\252\347\237\245", 0));
        label_7->setText(QApplication::translate("Form", "X:", 0));
        positionX_label->setText(QApplication::translate("Form", "\346\234\252\347\237\245", 0));
        label_8->setText(QApplication::translate("Form", "Y:", 0));
        positionY_label->setText(QApplication::translate("Form", "\346\234\252\347\237\245", 0));
        label_2->setText(QApplication::translate("Form", "X:", 0));
        startX_label->setText(QApplication::translate("Form", "0", 0));
        label_3->setText(QApplication::translate("Form", "Y:", 0));
        startY_label->setText(QApplication::translate("Form", "0", 0));
        label_12->setText(QApplication::translate("Form", "\350\247\222\345\272\246\357\274\232", 0));
        label_10->setText(QApplication::translate("Form", "A:", 0));
        endA_label->setText(QApplication::translate("Form", "\346\234\252\347\237\245", 0));
        groupBox_2->setTitle(QApplication::translate("Form", "\346\216\247\345\210\266\345\231\250", 0));
        back_pushButton->setText(QApplication::translate("Form", "\345\233\236\345\210\260\345\216\237\347\202\271", 0));
        clear_pushButton->setText(QApplication::translate("Form", "\346\270\205\351\231\244\350\275\250\350\277\271", 0));
        label_11->setText(QApplication::translate("Form", "\346\217\220\347\244\272\357\274\232\n"
"Y\350\275\264\346\255\243\346\226\271\345\220\221\344\270\272\n"
" \345\200\222\344\270\211\350\247\222\346\234\235\345\220\221\n"
"", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
