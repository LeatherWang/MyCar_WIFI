#include "scope.h"
#include "ui_scope.h"

scope::scope(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scope)
{
    ui->setupUi(this);

    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica",9));
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(0)->setPen(QPen(QColor(255, 110, 40)));
    ui->customPlot->graph(0)->setName("AP1_845");
    ui->customPlot->addGraph(); // green line
    ui->customPlot->graph(1)->setPen(QPen(QColor(13, 134, 64)));
    ui->customPlot->graph(1)->setName("AP2_740");\
    ui->customPlot->addGraph(); // blue line
    ui->customPlot->graph(2)->setPen(QPen(QColor(40, 110, 255)));
    ui->customPlot->graph(2)->setName("AP3_742");
    ui->customPlot->addGraph(); // black line
    ui->customPlot->graph(3)->setPen(QPen(QColor(0, 0, 0)));
    ui->customPlot->graph(3)->setName("AP4_740");

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

void scope::showKFFilter(float value)
{
    ui->label_RSSI1KFFilter->setText(QString::number((double)value, 'g', 4));
}

void scope::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    openFlag = false;
}

void scope::on_pushButton_RSSI0Save_clicked()
{
    static quint16 counterSave=0;
    counterSave++;
    ui->label_rssi0->setText(QString("%1").arg(counterSave));
    emit this->RSSISaveSingal(0);
}

void scope::on_pushButton_RSSI1Save_clicked()
{
    static quint16 counterSave=0;
    counterSave++;
    ui->label_rssi1->setText(QString("%1").arg(counterSave));
    emit this->RSSISaveSingal(1);
}

void scope::on_pushButton_RSSI2Save_clicked()
{
    static quint16 counterSave=0;
    counterSave++;
    ui->label_rssi2->setText(QString("%1").arg(counterSave));
    emit this->RSSISaveSingal(2);
}

void scope::on_pushButton_RSSI3Save_clicked()
{
    static quint16 counterSave=0;
    counterSave++;
    ui->label_rssi3->setText(QString("%1").arg(counterSave));
    emit this->RSSISaveSingal(3);
}

void scope::on_pushButton_submitAPInfo_clicked()
{
    this->apInformation.id = ui->lineEdit_ID->text().toUShort();
    this->apInformation.X = ui->lineEdit_valueX->text().toFloat();
    this->apInformation.Y = ui->lineEdit_valueY->text().toFloat();
    emit this->RSSISaveSingal(4);
}

