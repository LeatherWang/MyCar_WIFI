#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "scope.h"

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
    QTcpSocket *serialSocket;
    QString message;  //存放从服务器接收到的字符串
    quint16 blockSize;  //存放文件的大小信息
    scope *myscope;
    quint64 m_number_recive;
    QByteArray zhentou;

    void stringToHtmlFilter(QString &str);
    void stringToHtml(QString &str,QColor crl);
    QString toBlueText(QString str);
    void Leather_Data_Receive(QByteArray data);

private slots:
    void newConnect(); //连接服务器
    void readMessage();  //接收数据
    void readSerialMessage();  //接收数据
    void displayError(QAbstractSocket::SocketError);  //显示错误
    void displaySerialError(QAbstractSocket::SocketError);  //显示错误
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
