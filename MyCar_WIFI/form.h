#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    enum Shape{Line,Rectangle,RoundRect,Ellipse,Polygon,Polyline,Points,Arc,Path,Text,Pixmap};
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void MyCarComeBack(qint16 x, qint16 y, float z);
    void MyWiFiComeBack(quint8 maxRiNo, double maxValue, double P_Ri_SValue, float *smpRSSIAvg, float *mthRSSIAvg, float positionx, float positiony);
    void WiFiInitLocation(qint16 x, qint16 y);
    void FuseLocate(qint16 x, qint16 y);
//    QPainter *painter;
//    void mouseMoveEvent(QMouseEvent *);
//    void mouseReleaseEvent(QMouseEvent *);
    bool openFlag;
protected:
     void closeEvent(QCloseEvent *event);
private:
    Ui::Form *ui;

    QColor color;
    Qt::PenStyle style;
    Qt::PenCapStyle cap;
    Qt::PenJoinStyle join;
    quint8 value;

    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint,currentPoint, WiFiLocPoint;

    quint16 PixMapWidth;
    quint16 PixMapHeight;

    quint16 sendCounter;
    quint8 ComeBackFlag;

    QTimer *myTimer;

signals:
    void MyCarClickedSignal(qint16, qint16, float);

private slots:
    void on_back_pushButton_clicked();
    void on_clear_pushButton_clicked();
    void on_pushButton_sendTargetPosition_clicked();
    void on_pushButton_up_clicked();
    void on_pushButton_right_clicked();
    void on_pushButton_left_clicked();
    void on_pushButton_down_clicked();
    void on_pushButton_tenFont_clicked();
    void TimerUpdateSlot();
};

#endif // FORM_H
