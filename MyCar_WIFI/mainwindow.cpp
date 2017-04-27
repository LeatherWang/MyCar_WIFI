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
    //    ui->pushButton_linkSer2net->setStyleSheet("background-color:rgb(145,200,200);");
    //    ui->pushButton_sendSer2net->setStyleSheet("background-color:rgb(180,218,218);");

    ui->pushButton_serialOpen->setStyleSheet("background-color:rgb(145,200,200);");
    ui->pushButton_serialSend->setStyleSheet("background-color:rgb(180,218,218);");

    /*初始化TCP通信*/
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readTCPMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayTCPError(QAbstractSocket::SocketError)));
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectFinish()));
    tcp_number_recive = 0;

    /*初始化ser2net通信*/
    //    ser2netSocket = new QTcpSocket(this);
    //    connect(ser2netSocket,SIGNAL(readyRead()),this,SLOT(readSer2netMessage()));
    //    connect(ser2netSocket,SIGNAL(error(QAbstractSocket::SocketError)),
    //            this,SLOT(displaySer2netError(QAbstractSocket::SocketError)));

    /*初始化串口*/
    m_Com = new QextSerialPort(QextSerialPort::EventDriven,this);
    m_Com->setPortName("-1");
    m_Com_Monitor = new QextSerialEnumerator(); //串口监视器，发布串口增加、移除等信号
    m_Com_Monitor->setUpNotifications();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts()) //利用此循环将serialList显示在portBox中
    {
        ui->comboBox_serialFind->addItem(info.portName);
    }
    ui->comboBox_serialFind->setEditable(false); //set true to make sure user can input their own port name!
    connect(m_Com,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    connect(m_Com_Monitor,SIGNAL(deviceDiscovered(const QextPortInfo&)),this,SLOT(hasComDiscovered(const QextPortInfo&)));
    connect(m_Com_Monitor,SIGNAL(deviceRemoved(const QextPortInfo&)),this,SLOT(hasComRemoved(const QextPortInfo&)));
    connect(ui->comboBox_serialFind,SIGNAL(currentIndexChanged(QString)),this,SLOT(portName_changed(QString)));
    serial_number_recive = 0;
    serial_number_send = 0;

    /*初始化波形窗口*/
    myscope = new scope;
    connect(myscope,SIGNAL(RSSISaveSingal(quint8)),this,SLOT(RSSISaveSlot(quint8)));

    /*初始化地图窗口*/
    myForm = new Form;
    connect(myForm,SIGNAL(MyCarClickedSignal(qint16,qint16,float)),this,SLOT(MyCarClickedSlot(qint16,qint16,float)));

    /*初始化数据库 及 查看数据库窗口*/
    databaseDialog=new Dialogdatabase;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_showScope_clicked()
{
    myscope->show();
    myscope->openFlag = true;
}

void MainWindow::on_pushButton_openMap_clicked()
{
    myForm->show();
    myForm->openFlag = true;
}

/*通过地图向地面车发送目标位置坐标*/
void MainWindow::MyCarClickedSlot(qint16 x, qint16 y, float z)
{
    Leather_Data_Send(x,y,z,0x01);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    QApplication* appl;
    appl->quit();
}

void MainWindow::on_pushButton_databaseOpen_clicked()
{
    databaseDialog->show();
    databaseDialog->openFlag=true;

    //databaseDialog->lookupFromDatabase(2,0);
}


