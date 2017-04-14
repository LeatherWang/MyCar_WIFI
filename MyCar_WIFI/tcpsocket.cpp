#include "mainwindow.h"
#include "ui_mainwindow.h"

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

#define BSSID_raw 4
char BSSID[BSSID_raw][18]{"20:0c:c8:4a:df:fa","bc:d1:77:25:11:a2","ec:88:8f:54:10:dc","a8:15:4d:e6:ea:5e"};//SSID:Robot-AN-101, AP1_845, AP2_740, AP3_703 14:cf:92:46:24:86
float RSSIValue[BSSID_raw]={0.0};
float lastRSSIValue[BSSID_raw]={0.0};
QByteArray byteArray;
unsigned char counterAvgrage=0;
void MainWindow::readTCPMessage()
{
    if(tcpSocket->bytesAvailable()>0)
    {
        const QByteArray data = tcpSocket->readAll();
        ui->textBrowser_acceptTCP->append(data);
        tcp_number_recive++;
        ui->label_tcpReceive->setText(QString("已接受%1帧数据").arg(tcp_number_recive));
        for(quint8 i=0; i<BSSID_raw; i++)
        {
            if(data.indexOf(BSSID[i]) < 0)//判断此wifi是否在范围内
            {
                RSSIValue[i] = -99.0;
            }
            else
            {
                byteArray = data.mid(data.indexOf(BSSID[i]) , data.size()-data.indexOf(BSSID[i]));
                RSSIValue[i] = byteArray.mid(byteArray.indexOf("signal:") + 8 , 6).toFloat();

                if(RSSIValue[i] >= 0)//本次数据无效
                    return;
            }
        }

        if(lastRSSIValue[0] == 0.0)//第一帧数据
        {
            for(quint8 i=0; i<BSSID_raw; i++)
            {
                lastRSSIValue[i] = RSSIValue[i];
            }
            return;
        }
        else
        {
            for(quint8 i=0; i<BSSID_raw; i++) //限幅滤波，10DB
            {
                if((lastRSSIValue[i] == -99.0) && (RSSIValue[i] > -99.0)) //突然出现
                {
                    lastRSSIValue[i] = RSSIValue[i];
                }
                else if((RSSIValue[i] == -99.0) && (lastRSSIValue[i] > -99.0)) //突然消失
                {
                    lastRSSIValue[i] = RSSIValue[i];
                }
                else
                {
                    RSSIValue[i] = algorithm.LimitingFilter(RSSIValue[i], lastRSSIValue[i], 10);
                    lastRSSIValue[i] = RSSIValue[i];
                }
            }
        }

        if(counterAvgrage < Algorithm::MOVAVG_SIZE)//algorithm.MOVAVG_SIZE
            counterAvgrage++;
        for(quint8 i=0; i<BSSID_raw; i++)
        {
            algorithm.Queue_NewValue(RSSIValue[i],i); //队列递推
            if(myscope->openFlag == true)
            {
                float avgTemp = algorithm.Queue_getAvg(algorithm.Queue_buffer[i], counterAvgrage);
                float stradDev = algorithm.Queue_getStradDev(algorithm.Queue_buffer[i], avgTemp, counterAvgrage);
                myscope->showAvgAndStradDev(RSSIValue[i], avgTemp, stradDev, i);
            }
        }

        qDebug()<<RSSIValue[0]<<RSSIValue[1]<<RSSIValue[2];

        if(myscope->openFlag == true)
            myscope->showScope(RSSIValue[0] , RSSIValue[1], RSSIValue[2], RSSIValue[3]);
//        if(db.isOpen() == true)
//            this->saveToDatabase(RSSIValue[0],RSSIValue[1],RSSIValue[2],-99);
    }
}

