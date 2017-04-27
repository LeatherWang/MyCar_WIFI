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
    QPoint endPoint,currentPoint;

    quint16 PixMapWidth;
    quint16 PixMapHeight;

    quint16 sendCounter;

signals:
    void MyCarClickedSignal(qint16, qint16, float);

private slots:
    void on_back_pushButton_clicked();
    void on_clear_pushButton_clicked();
    void on_pushButton_sendTargetPosition_clicked();
};

#endif // FORM_H
