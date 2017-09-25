/*******************************************
 * 作者    ：王丕阁
 * 文件名   ：serialtalk.cpp
 * 函数功能 ：串口通信
 * 修改日期 ：2017-04-15
  *****************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

/****************************************
  *类型：       槽
  *对应信号：    串口开关按钮点击
  *功能：       如果串口已打开，将其关闭,关闭定时器。
               否则设置串口属性，打开串口，打开定时器。
  ***************************************/
void MainWindow::on_pushButton_serialOpen_clicked()
{
    if(m_Com->isOpen())
    {
        m_Com->close();
        ui->pushButton_serialOpen->setText("打开串口");
        ui->pushButton_serialOpen->setStyleSheet("background-color:rgb(145,200,200);");
        ui->label_serialState->setText("<font color='red'>注意：串口未打开！！！</font>");
    }
    else
    {
        m_Com->setPortName(ui->comboBox_serialFind->itemText(ui->comboBox_serialFind->currentIndex()));
        m_Com->setBaudRate(BAUD115200);
        m_Com->setDataBits(DATA_8);
        m_Com->setParity(PAR_NONE);
        m_Com->setStopBits(STOP_1);

        if(m_Com->open(QIODevice::ReadWrite))
        {
            ui->pushButton_serialOpen->setText("关闭串口");
            ui->pushButton_serialOpen->setStyleSheet("background-color:rgb(255,128,128);");
            ui->label_serialState->setText("<font color='green'>OK！已打开串口！！！</font>");
        }
        else
            ui->label_serialState->setText("<font color='red'>Failed！打开串口失败！！！</font>");
    }
}

/*******************************************
  *类型：槽
  *对应信号：串口名下拉列表值改变
  *功能：   如果串口打开，关闭串口
  *****************************************/
void MainWindow::portName_changed(QString name)
{
    if (m_Com->isOpen()&&m_Com->portName()!=name)
    {
        m_Com->close();
        ui->pushButton_serialOpen->setText("打开串口");
        ui->pushButton_serialOpen->setStyleSheet("background-color:rgb(145,200,200);");
        ui->label_serialState->setText("<font color='red'>注意：串口未打开！！！</font>");
    }
}

/********************************************
  *类型：槽
  *对应信号：读数据定时器时间到
  *功能：从串口读取数据，并显示在界面
        显示时要根据是否16进制而做改变
  *******************************************/
QByteArray serialByteArray;
void MainWindow::readMyCom()    //读串口发来的数据，并显示出来
{
    if(m_Com->bytesAvailable()>0)
    {
        ui->textBrowser_serialReceive->moveCursor(QTextCursor::End);//保持滚动条在最下方
        const QByteArray data = m_Com->readAll();
        serial_number_recive += data.size();
        if(ui->checkBox_showHex->isChecked())
        {
            QString str;
            for(int i=0;i<data.size();i++)
            {
                if(QString::number(quint8(data.at(i)),16).toUpper().length()==1)//16进制字母均大写
                    str.append(QString("0")+QString::number(quint8(data.at(i)),16).toUpper()+QString(" "));
                else
                    str.append(QString::number(quint8(data.at(i)),16).toUpper()+QString(" "));
            }
            //ui->textBrowser_serialReceive->insertHtml(toBlueText(str));

            /****************************** Start user code for include. **********************************/
            serialByteArray.append(data);

            if(serialByteArray.size() >= 13)//DONE!!
            {
                // qDebug()<<serialByteArray;
                if(serialByteArray.contains(zhentou))
                {
                    QByteArray byteArray_1 =  serialByteArray.mid(serialByteArray.indexOf(zhentou),4);//第四位为数据长度，非帧长度，帧长度=数据长度+5
                    byteArray_1 = serialByteArray.mid(serialByteArray.indexOf(zhentou),byteArray_1.at(3)+5);
                                       // qDebug()<<byteArray_1.size();
                    Leather_Data_Receive(byteArray_1);
                }
                serialByteArray.clear();
            }
            /********************************* End user code. *********************************************/
        }
        else
        {
            ui->textBrowser_serialReceive->insertHtml(toBlueText(QString::fromLocal8Bit(data)));//insertHtml
        }
        showSerialCountNumber();
    }
}

#define BYTE0(dwTemp)       ( *( (quint8 *)(&dwTemp)	) )
#define BYTE1(dwTemp)       ( *( (quint8 *)(&dwTemp) + 1) )//beautiful--Leather
#define BYTE2(dwTemp)       ( *( (quint8 *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (quint8 *)(&dwTemp) + 3) )
typedef union
{
    qint16 sum;//int = qint32
    quint8 son[2];
} MyUnion;
MyUnion Union_dataBuf;

typedef union
{
    float sum;//int = qint32
    quint8 son[4];
} UnionFloat;
UnionFloat unionFloat;

void MainWindow::Leather_Data_Receive(QByteArray data)
{
    quint8 sum = 0;
    quint8 num = data.size();
    for(quint8 i=0;i<(num-1);i++)
        sum += (quint8(data.at(i)));
    if(!(sum == quint8(data.at(num-1))))	return;		//判断sum，校验--Leather
    if(!(quint8(data.at(0))==0xAA && quint8(data.at(1))==0xAF))		return;		//判断帧头--Leather

    if(quint8(data.at(2)) == 0X01)
    {
        Union_dataBuf.son[1] = quint8(data.at(4));
        Union_dataBuf.son[0] = quint8(data.at(5));
        if(Union_dataBuf.sum < 0)
            qDebug()<<"odometer.X="<<Union_dataBuf.sum;
            //QMessageBox::warning(this, tr("错误！！"),tr("odometer.X=")+QString::number(Union_dataBuf.sum,10),QMessageBox::Ok);
        else
            odometer.X = Union_dataBuf.sum;

        Union_dataBuf.son[1] = quint8(data.at(6));
        Union_dataBuf.son[0] = quint8(data.at(7));
        if(Union_dataBuf.sum < 0)
            qDebug()<<"odometer.Y="<<Union_dataBuf.sum;
            //QMessageBox::warning(this, tr("错误！！"),tr("odometer.Y=")+QString::number(Union_dataBuf.sum,10),QMessageBox::Ok);
        else
            odometer.Y = Union_dataBuf.sum;

        unionFloat.son[3] = quint8(data.at(8));
        unionFloat.son[2] = quint8(data.at(9));
        unionFloat.son[1] = quint8(data.at(10));
        unionFloat.son[0] = quint8(data.at(11));
        odometer.Z = unionFloat.sum;

        //qDebug()<<Position_Z;
        if(myForm->openFlag == true)
        {
            myForm->MyCarComeBack(odometer.X, odometer.Y, odometer.Z);//调用地图显示
        }
    }
}

/****************************** Start user code for include. **********************************/
void MainWindow::Leather_Data_Send(qint16 posionX, qint16 posionY, float positionZ, quint8 flag)
{
    QByteArray array;
    qDebug()<<posionX<<posionY;
    unsigned char _cnt=0;
    unsigned char i=0;
    unsigned char sum = 0;

    array[_cnt++]=0xAA;
    array[_cnt++]=0xAF;
    array[_cnt++]=flag;
    array[_cnt++]=0;

    array[_cnt++]=BYTE1(posionX);
    array[_cnt++]=BYTE0(posionX);
    array[_cnt++]=BYTE1(posionY);
    array[_cnt++]=BYTE0(posionY);

    array[_cnt++]=BYTE3(positionZ);
    array[_cnt++]=BYTE2(positionZ);
    array[_cnt++]=BYTE1(positionZ);
    array[_cnt++]=BYTE0(positionZ);

    array[3] = _cnt-4;

    for(i=0;i<_cnt;i++)
        sum += array[i];

    array[_cnt++]=sum;

    if(robotInitFlag == true)
    {
        if(m_Com->isOpen())
            m_Com->write(array);
    }
    else
    {
        //QMessageBox::warning(this, tr("错误！！"),tr("robot未初始化完成！！"),QMessageBox::Ok);
        if(m_Com->isOpen())
            m_Com->write(array);
        qDebug()<<"robot未初始化完成！！";
    }
}

/********************************* End user code. *********************************************/

/********************************************************
  *类型：私有函数
  *功能：替换特殊字符，帮助html显示
  ****************************************************/
void MainWindow::stringToHtmlFilter(QString &str)
{
    //注意这几行代码的顺序不能乱，否则会造成多次替换
    str.replace("&","&amp;");
    str.replace(">","&gt;");
    str.replace("<","&lt;");
    str.replace("\"","&quot;");
    str.replace("\'","&#39;");
    str.replace(" ","&nbsp;");
    str.replace("\n","<br>");
    str.replace("\r","<br>");
}

/********************************************************
  *类型：私有函数
  *功能：将替换特殊字符后的QString转换成对应颜色显示的html
  ****************************************************/
void MainWindow::stringToHtml(QString &str,QColor crl)
{
    QByteArray array;
    array.append(crl.red());
    array.append(crl.green());
    array.append(crl.blue());
    QString strC(array.toHex());
    str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
}

/*******************************************************
  *类型：私有函数
  *功能：将一个文本字符串转换成蓝色的html文本颜色
        并换行
  ******************************************************/
QString MainWindow::toBlueText(QString str)
{
    QColor crl(0,0,255);
    stringToHtmlFilter(str);
    stringToHtml(str,crl);
    return str;
}

/************************************************
  *类型：槽函数
  *对应信号：有新的串口设备被发现
  *功能：在串口下拉列表中加入改串口设备
  *************************************************/
void MainWindow::hasComDiscovered(const QextPortInfo &info)
{
    ui->comboBox_serialFind->addItem(info.portName);
    if(!m_Com->isOpen())
        ui->comboBox_serialFind->setCurrentIndex(ui->comboBox_serialFind->count()-1);
}

/************************************************
  *类型：槽函数
  *对应信号：有串口设备断开连接
  *功能：如果断开的设备是当前打开的设备，就关闭改串口及定时器
        提示用户
        如果不是当前设备，就在串口下拉列表中删除该设备
  *************************************************/
void MainWindow::hasComRemoved(const QextPortInfo &info)
{
    if(info.portName == ui->comboBox_serialFind->currentText())
    {
        m_Com->close();
        ui->pushButton_serialOpen->setText("打开串口");
        ui->pushButton_serialOpen->setStyleSheet("background-color:rgb(145,200,200);");
        ui->label_serialState->setText("<font color='red'>注意：串口未打开！！！</font>");
    }
    for(int i=0;i<ui->comboBox_serialFind->count();i++)
    {
        if(ui->comboBox_serialFind->itemText(i)==info.portName)
            ui->comboBox_serialFind->removeItem(i);
    }
}

//清空接收区
void MainWindow::on_pushButton_serialClearReceive_clicked()
{
    ui->textBrowser_serialReceive->clear();
}

//清空发送区
void MainWindow::on_pushButton_serialClearSend_clicked()
{
    ui->textEdit_serialSend->clear();
}

/*****************************************************
  *类型：私有函数
  *功能：显示计数
  ****************************************************/
void MainWindow::showSerialCountNumber()
{
    if(serial_number_recive >10000)
    {
        on_pushButton_serialClearReceive_clicked();//定期清除接收区
        serial_number_recive = 0;
    }
    ui->label_serialReceive->setText(QString("已接受%1字节").arg(serial_number_recive));
    ui->label_serialSend->setText(QString("已发送%1字节").arg(serial_number_send));
}

/********************************************************
  *类型：私有函数
  *功能：清空计数
  ****************************************************/
void MainWindow::on_pushButton_serialClearCount_clicked()
{
    serial_number_send = 0;
    serial_number_recive = 0;
    showSerialCountNumber();
}

QString lastStr;
QByteArray byteArraySend;//发送给串口
void MainWindow::on_textEdit_serialSend_textChanged()
{
    if(!ui->textEdit_serialSend->toPlainText().isEmpty())
    {
        ui->textEdit_serialSend->moveCursor(QTextCursor::End);
        QChar newAdd = ui->textEdit_serialSend->toPlainText().at(ui->textEdit_serialSend->toPlainText().size()-1);
        bool ok;
        if(ui->checkBox_serialSendHex->isChecked())//对输入的16进制进行判断
        {
            if(newAdd != ' ')
            {
                QByteArray byteArray_1;
                QStringList list = ui->textEdit_serialSend->toPlainText().split(" ");//分割数据
                for(int i =0;i<list.size();i++)
                {
                    char a = list.value(i).toInt(&ok,16);
                    //qDebug()<<QString::number(quint8(a),16).toUpper();
                    if(!ok)
                    {
                        ui->textEdit_serialSend->clear();
                        ui->textEdit_serialSend->setText(lastStr);
                        QMessageBox::warning(this,"提示","非法的16进制数，请重新输入！");
                        return ;
                    }
                    byteArray_1[i] = a;
                }
                byteArraySend = byteArray_1;
            }
            lastStr = ui->textEdit_serialSend->toPlainText();
        }
    }
}

/********************************************************
  *类型：私有函数
  *功能：发送数据
  ****************************************************/
void MainWindow::on_pushButton_serialSend_clicked()
{
    if(!ui->textEdit_serialSend->toPlainText().isEmpty())
    {
        if(ui->checkBox_serialSendHex->isChecked())
        {
            m_Com->write(byteArraySend);
            serial_number_send += byteArraySend.size();
        }
        else
        {
            m_Com->write(ui->textEdit_serialSend->toPlainText().toLocal8Bit());
            serial_number_send += ui->textEdit_serialSend->toPlainText().toLocal8Bit().size();
        }
        showSerialCountNumber();
    }
}

void MainWindow::on_checkBox_serialSendHex_clicked()
{
    ui->textEdit_serialSend->clear();
}
