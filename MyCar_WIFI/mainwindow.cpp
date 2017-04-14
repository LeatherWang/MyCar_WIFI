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

    /*初始化地图窗口*/
    myForm = new Form;
    connect(myForm,SIGNAL(MyCarClickedSignal(quint16,quint16)),this,SLOT(MyCarClickedSlot(quint16,quint16)));

    /*初始化数据库*/
    if(QSqlDatabase::contains("xxx.db"))
        db = QSqlDatabase::database("xxx.db");
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE", "xxx.db");
        db.setDatabaseName("xxx.db");//设置数据库名，这句话不能少
        bool ok = db.open();         //尝试连接数据库
        if(ok)
            qDebug()<<"链接数据库成功";
        else
            qDebug()<<"链接数据库失败，因为"<<db.lastError().text();

        QSqlQuery query(db);
        bool success=query.exec("create table RSSIValueTable(id integer,RSSI1 integer,RSSI2 integer,RSSI3 integer,RSSI4 integer)");
        if(success)
            qDebug()<<"数据库表创建成功！\n";
        else
            qDebug()<<"数据库表创建失败或者已经存在！\n";
    }

    /*初始化查看数据库窗口*/
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
void MainWindow::MyCarClickedSlot(quint16 x, quint16 y)
{
    Leather_Data_Send(x,y,0x01);
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
}

void MainWindow::saveToDatabase(char RSSI1, char RSSI2, char RSSI3, char RSSI4)
{
    QSqlQuery query(db);

    query.exec("select *from RSSIValueTable");
    query.last(); //query指向结果集的最后一条记录
    int ID = query.value(0).toString().toInt();

    query.prepare("insert into RSSIValueTable values(:id,:RSSI1,:RSSI2,:RSSI3,:RSSI4)");
        query.bindValue(":id",ID+1); //id自加一
        query.bindValue(":RSSI1",RSSI1); //注意qstring类型！！！！！
        query.bindValue(":RSSI2",RSSI2);
        query.bindValue(":RSSI3",RSSI3);
        query.bindValue(":RSSI4",RSSI4);

    qDebug()<<ID+1<<RSSI1<<RSSI2<<RSSI3<<RSSI4;
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<"插入失败";
    }
    //databaseShowDataSlot();
}
