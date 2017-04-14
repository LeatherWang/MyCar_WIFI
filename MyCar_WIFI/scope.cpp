#include "scope.h"
#include "ui_scope.h"

scope::scope(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scope)
{
    ui->setupUi(this);

    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica",9));
    ui->customPlot->addGraph(); // blue line
    ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->customPlot->graph(0)->setName("Robot_101");
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
    ui->customPlot->graph(1)->setName("AP1_845");\
    ui->customPlot->addGraph(); // green line
    ui->customPlot->graph(2)->setPen(QPen(QColor(13, 134, 64)));
    ui->customPlot->graph(2)->setName("AP2_740");
    ui->customPlot->addGraph(); // yellow line
    ui->customPlot->graph(3)->setPen(QPen(QColor(227, 187, 28)));
    ui->customPlot->graph(3)->setName("OpenW_703");

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-100, 0);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    openFlag = false;
}

scope::~scope()
{
    delete ui;
}

void scope::showScope(float para1, float para2, float para3, float para4)
{
    QTime time(QTime::currentTime());//获取当前时间
    double key = time.hour()*3600 + time.minute()*60 + time.second() + time.msec()*0.001;

    ui->customPlot->graph(0)->addData(key, para1);
    ui->customPlot->graph(1)->addData(key, para2);
    ui->customPlot->graph(2)->addData(key, para3);
    ui->customPlot->graph(3)->addData(key, para4);

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 200, Qt::AlignRight);
    ui->customPlot->replot();
}

void scope::showAvgAndStradDev(float value, float avg, float stradDev, unsigned char index)
{
    switch(index)
    {
    case 0: ui->label_RSSI0Value->setText(QString::number((double)value, 'g', 4));
            ui->label_RSSI0Avg->setText(QString::number((double)avg, 'g', 4));
            ui->label_RSSI0StardDev->setText(QString::number((double)stradDev, '9', 4));
            break;
    case 1: ui->label_RSSI1Value->setText(QString::number((double)value, 'g', 4));
            ui->label_RSSI1Avg->setText(QString::number((double)avg, 'g', 4));
            ui->label_RSSI1StardDev->setText(QString::number((double)stradDev, '9', 4));
            break;
    case 2: ui->label_RSSI2Value->setText(QString::number((double)value, 'g', 4));
            ui->label_RSSI2Avg->setText(QString::number((double)avg, 'g', 4));
            ui->label_RSSI2StardDev->setText(QString::number((double)stradDev, '9', 4));
            break;
    case 3: ui->label_RSSI3Value->setText(QString::number((double)value, 'g', 4));
            ui->label_RSSI3Avg->setText(QString::number((double)avg, 'g', 4));
            ui->label_RSSI3StardDev->setText(QString::number((double)stradDev, '9', 4));
            break;
    default: break;
    }
}

void scope::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    openFlag = false;
}

