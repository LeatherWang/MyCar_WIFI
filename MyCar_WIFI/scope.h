#ifndef SCOPE_H
#define SCOPE_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class scope;
}
struct APInformation_1
{
    quint16 id;
    float RSSIValueAvg[4];
    float RSSIValueDev[4];
    float X;
    float Y;
};

class scope : public QWidget
{
    Q_OBJECT

public:
    explicit scope(QWidget *parent = 0);
    ~scope();

    void showScope(float para1 , float para2, float para3, float para4);
    bool openFlag;
    void showAvgAndStradDev(float value, float avg, float stradDev, unsigned char index);
    void showKFFilter(float value);
    struct APInformation_1 apInformation;
protected:
     void closeEvent(QCloseEvent *event);

private slots:


     void on_pushButton_RSSI1Save_clicked();

     void on_pushButton_RSSI2Save_clicked();

     void on_pushButton_RSSI3Save_clicked();

     void on_pushButton_submitAPInfo_clicked();

     void on_pushButton_RSSI0Save_clicked();

private:
    Ui::scope *ui;

signals:
    void RSSISaveSingal(quint8);
};

#endif // SCOPE_H
