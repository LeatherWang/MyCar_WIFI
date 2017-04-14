#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_linkSer2net_clicked()
{
    ser2netSocket->abort(); //取消已有的连接
    ser2netSocket->connectToHost("192.168.10.1",
                                2001);//连接到主机，这里从界面获取主机地址和端口号
}

void MainWindow::on_pushButton_sendSer2net_clicked()
{
    ser2netSocket->write(ui->textEdit_ser2netSend->toPlainText().toLatin1());
}

void MainWindow::displaySer2netError(QAbstractSocket::SocketError)
{
    qDebug() <<"error!"<< ser2netSocket->errorString(); //输出错误信息
    ui->messageLabel_linkTCPState->setText("<font color=red>error!!</font>"+ser2netSocket->errorString());
}

QByteArray ser2netByteArray;
void MainWindow::readSer2netMessage()
{
    if(ser2netSocket->bytesAvailable()>0)
    {
        const QByteArray data = ser2netSocket->readAll();
        //m_number_recive += data.size();
        QString str;
        for(int i=0;i<data.size();i++)
        {
            if(QString::number(quint8(data.at(i)),16).toUpper().length()==1)//16进制字母均大写
                str.append(QString("0")+QString::number(quint8(data.at(i)),16).toUpper()+QString(" "));
            else
                str.append(QString::number(quint8(data.at(i)),16).toUpper()+QString(" "));
        }
        //ui->textBrowserSerial->insertHtml(toBlueText(str));
        ui->textBrowser_acceptSer2net->append(str);

        /****************************** Start user code for include. **********************************/
        ser2netByteArray.append(data);

        if(ser2netByteArray.size() >= 9)//DONE!!
        {
            // qDebug()<<byteArray;
            if(ser2netByteArray.contains(zhentou))
            {
                QByteArray byteArray_1 =  ser2netByteArray.mid(ser2netByteArray.indexOf(zhentou),4);//第四位为数据长度，非帧长度，帧长度=数据长度+5
                byteArray_1 = ser2netByteArray.mid(ser2netByteArray.indexOf(zhentou),byteArray_1.at(3)+5);
                //                    qDebug()<<byteArray_1<<"  ";
                //Leather_Data_Receive(byteArray_1);
            }
            ser2netByteArray.clear();
        }
        /********************************* End user code. *********************************************/
    }
}
