#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zhentou.resize(2);
    zhentou[0] = 0XAA;
    zhentou[1] = 0XAF;
    ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(145,200,200);");
    ui->pushButton_sendTCP->setStyleSheet("background-color:rgb(180,218,218);");

    /*初始化TCP通信*/
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readTCPMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayTCPError(QAbstractSocket::SocketError)));
    ser2netSocket = new QTcpSocket(this);
    connect(ser2netSocket,SIGNAL(readyRead()),this,SLOT(readSer2netMessage()));
    connect(ser2netSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displaySer2netError(QAbstractSocket::SocketError)));

    /*初始化串口*/
    m_Com = new QextSerialPort(QextSerialPort::EventDriven,this);
    m_Com->setPortName("-1");
    m_Com_Monitor = new QextSerialEnumerator(); //串口监视器，发布串口增加、移除等信号
    m_Com_Monitor->setUpNotifications();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts()) //利用此循环将serialList显示在portBox中
    //ui->portBox->addItem(info.portName);
    //ui->portBox->setEditable(false); //set true to make sure user can input their own port name!

    /*初始化波形窗口*/
    myscope = new scope;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool openCloseFlag = false;
void MainWindow::on_pushButton_linkTCP_clicked()
{
    if(openCloseFlag == false)
    {
        tcpSocket->abort(); //取消已有的连接
        tcpSocket->connectToHost("192.168.10.1",
                                 8082);//连接到主机，这里从界面获取主机地址和端口号
        openCloseFlag = true;
        ui->pushButton_linkTCP->setText("断开服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(255,128,128);");
    }
    else
    {
        tcpSocket->write("p");
        tcpSocket->disconnectFromHost();
        openCloseFlag = false;
        ui->pushButton_linkTCP->setText("连接服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(145,200,200);");
    }
}

void MainWindow::on_pushButton_sendTCP_clicked()
{
    tcpSocket->write(ui->lineEdit_sendTCP->text().toLatin1());
}

void MainWindow::on_pushButton_showScope_clicked()
{
    myscope->show();
}

void MainWindow::on_pushButton_linkSer2net_clicked()
{
    ser2netSocket->abort(); //取消已有的连接
    ser2netSocket->connectToHost("192.168.10.1",
                                2001);//连接到主机，这里从界面获取主机地址和端口号
}

void MainWindow::on_pushButton_sendSer2net_clicked()
{
    ser2netSocket->write(ui->lineEdit_sendSer2net->text().toLatin1());
}

void MainWindow::displayTCPError(QAbstractSocket::SocketError)
{
    qDebug() <<"error!"<< tcpSocket->errorString(); //输出错误信息
    ui->messageLabel_linkTCPState->setText("<font color=red>error!!</font>"+tcpSocket->errorString());
}

void MainWindow::displaySer2netError(QAbstractSocket::SocketError)
{
    qDebug() <<"error!"<< ser2netSocket->errorString(); //输出错误信息
    ui->messageLabel_linkTCPState->setText("<font color=red>error!!</font>"+ser2netSocket->errorString());
}

#define BSSID_raw 3
char BSSID[BSSID_raw][18]{"20:0c:c8:4a:df:fa","fc:d7:33:4a:5c:c8","14:cf:92:46:24:86"};//SSID:Robot-AN-101,Robot-IS-108,WW
float RSSIValue[BSSID_raw]={0.0};
QByteArray byteArray;
void MainWindow::readTCPMessage()
{
    if(tcpSocket->bytesAvailable()>0)
    {
        const QByteArray data = tcpSocket->readAll();
        ui->textBrowser_acceptTCP->append(data);

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
            }
        }
        qDebug()<<RSSIValue[0]<<RSSIValue[1]<<RSSIValue[2];

        if(myscope->isActiveWindow())
            myscope->showScope(RSSIValue[0] , RSSIValue[2]);
    }
}

QByteArray serialByteArray;
void MainWindow::readSer2netMessage()
{
    if(ser2netSocket->bytesAvailable()>0)
    {
        const QByteArray data = ser2netSocket->readAll();
        m_number_recive += data.size();
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
        serialByteArray.append(data);

        if(serialByteArray.size() >= 9)//DONE!!
        {
            // qDebug()<<byteArray;
            if(serialByteArray.contains(zhentou))
            {
                QByteArray byteArray_1 =  serialByteArray.mid(serialByteArray.indexOf(zhentou),4);//第四位为数据长度，非帧长度，帧长度=数据长度+5
                byteArray_1 = serialByteArray.mid(serialByteArray.indexOf(zhentou),byteArray_1.at(3)+5);
                //                    qDebug()<<byteArray_1<<"  ";
                Leather_Data_Receive(byteArray_1);
            }
            serialByteArray.clear();
        }
        /********************************* End user code. *********************************************/
    }
}





#include "math.h"
typedef union
{
    quint16 sum;//int = qint32
    quint8 son[2];
} MyUnion;
MyUnion Union_dataBuf;
quint16 Position_A,Position_B;
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
        Position_A = Union_dataBuf.sum;

        Union_dataBuf.son[1] = quint8(data.at(6));
        Union_dataBuf.son[0] = quint8(data.at(7));
        Position_B = Union_dataBuf.sum;
        qDebug()<<Position_A<<Position_B;
        //myForm->MyCarComeBack(Position_A,Position_B);
    }
}

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



