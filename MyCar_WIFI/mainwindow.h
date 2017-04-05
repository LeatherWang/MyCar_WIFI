#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "scope.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"

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
    QTcpSocket *ser2netSocket;
    QString message;  //存放从服务器接收到的字符串
    scope *myscope;
    quint64 m_number_recive;
    QByteArray zhentou;

    QextSerialEnumerator *m_Com_Monitor;
    QextSerialPort *m_Com;

    void stringToHtmlFilter(QString &str);
    void stringToHtml(QString &str,QColor crl);
    QString toBlueText(QString str);
    void Leather_Data_Receive(QByteArray data);

private slots:
    void readTCPMessage();  //接收数据
    void readSer2netMessage();  //接收数据
    void displayTCPError(QAbstractSocket::SocketError);  //显示错误
    void displaySer2netError(QAbstractSocket::SocketError);  //显示错误
    void on_pushButton_linkTCP_clicked();
    void on_pushButton_sendTCP_clicked();
    void on_pushButton_showScope_clicked();
    void on_pushButton_linkSer2net_clicked();
    void on_pushButton_sendSer2net_clicked();
};

#endif // MAINWINDOW_H
