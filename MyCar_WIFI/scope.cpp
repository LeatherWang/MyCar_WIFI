#include "scope.h"
#include "ui_scope.h"

scope::scope(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scope)
{
    ui->setupUi(this);

    ui->customPlot->addGraph(); // blue line
    ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-100, 0);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
}

scope::~scope()
{
    qDebug()<<"fff";
    delete ui;
}

void scope::showScope(float para1, float para2)
{
    QTime time(QTime::currentTime());//获取当前时间
    double key = time.hour()*3600 + time.minute()*60 + time.second() + time.msec()*0.001;

    ui->customPlot->graph(0)->addData(key, para1);
    ui->customPlot->graph(1)->addData(key, para2);

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 100, Qt::AlignRight);
    ui->customPlot->replot();
}
