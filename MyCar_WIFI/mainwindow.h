#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "scope.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include <QMessageBox>
#include <QCloseEvent>
#include "form.h"
#include "dialogdatabase.h"
#include "algorithm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    quint64 tcp_number_recive;
    QTcpSocket *ser2netSocket;
    QString message;  //存放从服务器接收到的字符串
    quint64 ser2net_number_recive;
    QByteArray zhentou;

    QextSerialEnumerator *m_Com_Monitor;
    QextSerialPort *m_Com;
    quint64 serial_number_send;
    quint64 serial_number_recive;
    void showSerialCountNumber();
    void writeCommand(QString str);
    void stringToHtmlFilter(QString &str);
    void stringToHtml(QString &str,QColor crl);
    QString toBlueText(QString str);
    void Leather_Data_Receive(QByteArray data);
    void Leather_Data_Send(quint16 posionX, quint16 posionY, quint8 flag);

    scope *myscope;

    Form *myForm;

    Dialogdatabase *databaseDialog;
    QSqlDatabase db;
    QSqlQuery query;
    void saveToDatabase(char RSSI1, char RSSI2, char RSSI3, char RSSI4);

    Algorithm algorithm;

protected:
     void closeEvent(QCloseEvent *event);//重载函数，纯虚函数

private slots:
    /*TCP槽函数*/
    void readTCPMessage(); //接收数据
    void on_pushButton_linkTCP_clicked();
    void on_pushButton_sendTCP_clicked();
    void on_pushButton_showScope_clicked();
    void displayTCPError(QAbstractSocket::SocketError); //显示错误
    void connectFinish();

    /*ser2net槽函数*/
//    void readSer2netMessage();
//    void on_pushButton_linkSer2net_clicked();
//    void on_pushButton_sendSer2net_clicked();
//    void displaySer2netError(QAbstractSocket::SocketError);

    /*串口槽函数*/
    void readMyCom();
    void hasComDiscovered(const QextPortInfo &info);
    void hasComRemoved(const QextPortInfo &info);
    void on_pushButton_serialClearCount_clicked();
    void on_pushButton_serialClearReceive_clicked();
    void on_pushButton_serialSend_clicked();
    void on_pushButton_serialOpen_clicked();
    void on_pushButton_serialClearSend_clicked();
    void portName_changed(QString name);
    void on_textEdit_serialSend_textChanged();
    void on_checkBox_serialSendHex_clicked();

    void on_pushButton_openMap_clicked();
    void MyCarClickedSlot(quint16 x,quint16 y);
    void on_pushButton_databaseOpen_clicked();

};

#endif // MAINWINDOW_H
