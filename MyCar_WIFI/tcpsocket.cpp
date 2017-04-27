#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "apinfo.h"

bool openCloseFlag = false;
void MainWindow::on_pushButton_linkTCP_clicked()
{
    ui->messageLabel_linkTCPState->clear();
    if(openCloseFlag == false)
    {
        tcpSocket->abort(); //取消已有的连接
        tcpSocket->connectToHost("192.168.10.1",
                                 8082);//连接到主机，这里从界面获取主机地址和端口号
        openCloseFlag = true;
        ui->pushButton_linkTCP->setText("断开服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(255,128,128);");
        ui->messageLabel_linkTCPState->setText(QString("正在连接服务器......"));
    }
    else
    {
        tcpSocket->write("p");
        tcpSocket->disconnectFromHost();
        openCloseFlag = false;
        ui->pushButton_linkTCP->setText("连接服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(145,200,200);");
        ui->messageLabel_linkTCPState->setText(QString("注意：未连接！！！"));
    }
}

void MainWindow::on_pushButton_sendTCP_clicked()
{
    tcpSocket->write(ui->textEdit_TCPSend->toPlainText().toLatin1());
}

void MainWindow::displayTCPError(QAbstractSocket::SocketError)
{
    ui->messageLabel_linkTCPState->setText(QString("<font color=red>Error!!! %1</font>").arg(tcpSocket->errorString()));
}

void MainWindow::connectFinish()
{
    ui->messageLabel_linkTCPState->setText(QString("<font color=green>连接成功！！！</font>"));
}

void MainWindow::on_pushButton_TCPClearCount_clicked()
{
    tcp_number_recive = 0;
    ui->label_tcpReceive->setText(QString("已接受%1帧数据").arg(tcp_number_recive));
}

#define ABS(x) ( (x)>0?(x):-(x) )
void MainWindow::readTCPMessage()
{
    quint8 countFrame;
    if(tcpSocket->bytesAvailable()>0)
    {
        const QByteArray data = tcpSocket->readAll();
        //ui->textBrowser_acceptTCP->append(data);
        for(quint8 i=0; i<BSSID_raw; i++)
        {
            quint8 countTemp=0;
            for(qint16 index=0; (index=data.indexOf(BSSIDList.value(i),index)) != -1; index+=17,countTemp++)
            {
                RSSIValue[i] = data.mid(data.indexOf("signal:",index) + 10 , 3).toFloat();
                if(RSSIValue[i] >= 0)//本次数据无效
                    return;
                if(ABS(lastRSSIValue[i] - RSSIValue[i]) < 20)//TODO
                    RSSIValue[i] = algorithm.LimitingFilter(RSSIValue[i], lastRSSIValue[i], 10);
                lastRSSIValue[i] = RSSIValue[i];
                algorithm.Queue_NewValue(RSSIValue[i],i); //队列递推
            }
            countFrame = countTemp;
            countTemp=0;

            if(myscope->openFlag == true)
            {
                apInformationTemp.RSSIValueAvg[i] = algorithm.Queue_getAvg(algorithm.Queue_buffer[i], Algorithm::MOVAVG_SIZE);
                apInformationTemp.RSSIValueDev[i] = algorithm.Queue_getStradDev(algorithm.Queue_buffer[i], apInformationTemp.RSSIValueAvg[i], Algorithm::MOVAVG_SIZE);
                myscope->showAvgAndStradDev(RSSIValue[i], apInformationTemp.RSSIValueAvg[i], apInformationTemp.RSSIValueDev[i], i);
            }
        }

        if(myscope->openFlag == true)
        {
            RSSIValue[2] =algorithm.KalmanFilter_1(RSSIValue[1], 0.001, 0.8); //algorithm.KalmanFilter_2(RSSIValue[1]);
            myscope->showKFFilter(RSSIValue[2]);//algorithm.KalmanFilter_1(RSSIValue[1], 0.00001, 0.8)
            //myscope->showScope(RSSIValue[0] , RSSIValue[1], RSSIValue[2], RSSIValue[3]);
            myscope->showScope(RSSIValue[0] , RSSIValue[1], RSSIValue[2], RSSIValue[3]);
        }

        tcp_number_recive +=countFrame;
        ui->label_tcpReceive->setText(QString("已接受%1帧数据").arg(tcp_number_recive));
    }
}

/*******************************************
*函数功能：计算P_S_Rn
  *****************************************/
void MainWindow::ComputeP_S_Rn(float *rssiValue)
{
    for(quint8 i=0; i<RiNum; i++)
    {
        P_S_RiValue[i] = ComputeP_S_Ri(i+1, rssiValue);
    }
}

/*******************************************
*函数功能：计算P_S_Ri
  *****************************************/
double MainWindow::ComputeP_S_Ri(quint16 id, float *rssiValue)
{
    float Avg_u[NUMBER_AP], Dev_o[NUMBER_AP];
    quint8 index_u=1, index_o=2;
    double mul_o=1, Exp_pow=0;
    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        Avg_u[i] = databaseDialog->lookupFromDatabase(0, id, index_u);
        Dev_o[i] = databaseDialog->lookupFromDatabase(0, id, index_o);

        Exp_pow += my_pow((rssiValue[i] - Avg_u[i])/Dev_o[i]);
        mul_o *=Dev_o[i];
        index_u +=2;
        index_o +=2;
    }
    return pow(EXP, -Exp_pow/2.0)/(TWOPI2*mul_o);
}

void MainWindow::RSSISaveSlot(quint8 index)
{
    if(index != 4)
    {
        apInformation.RSSIValueAvg[index] = apInformationTemp.RSSIValueAvg[index];
        apInformation.RSSIValueDev[index] = apInformationTemp.RSSIValueDev[index];
    }
    else
    {
        apInformation.id = myscope->apInformation.id;
        apInformation.X = myscope->apInformation.X;
        apInformation.Y = myscope->apInformation.Y;

        if(databaseDialog->Qdb.isOpen() == true)
            databaseDialog->saveToDatabase(apInformation.id, apInformation.RSSIValueAvg, apInformation.RSSIValueDev, apInformation.X, apInformation.Y);
    }
}

