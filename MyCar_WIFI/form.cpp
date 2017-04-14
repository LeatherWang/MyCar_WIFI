#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));//窗口背景设置
    setAutoFillBackground(true);
    setFixedSize(810,700);
    setAttribute(Qt::WA_QuitOnClose,false);//主窗口关闭其跟着一起关闭

    PixMapWidth = 700;
    PixMapHeight = 700;
    pix = QPixmap(PixMapWidth,PixMapHeight);
    pix.fill(Qt::white);   //背景填充为红色

    color = QColor(0,0,255);//画笔颜色
    style = Qt::PenStyle(1);//画笔风格，SolidLine
    cap = Qt::PenCapStyle(0x10);//画笔顶帽，SquareCap
    join=Qt::PenJoinStyle(0x40);//画笔连接点，BevelJoin
    value = 3;//设置线宽，0~20
    pen = QPen(color,value,style,cap,join);//设置画笔

    QColor color_brush(100,100,100);//画刷颜色
    Qt::BrushStyle style_brush = Qt::BrushStyle(7);//画刷风格，CrossPattern
    brush = QBrush(color_brush,style_brush);//设置画刷

    Qt::FillRule rule = Qt::FillRule(0);//设置填充模式，OddEvenFill
    fillRule = rule;

    shape = Form::Shape(10);//0->Line, 1->Rct

    endPoint = lastPoint = QPoint(pix.width()/2,pix.height()/2);//起始点坐标，画面中心
    ui->startX_label->setText(QString::number(lastPoint.x(),10));
    ui->startY_label->setText(QString::number(lastPoint.y(),10));

    openFlag = false;
}

Form::~Form()
{
    delete ui;
}

void Form::mousePressEvent(QMouseEvent *event)
{
    if((event->button()==Qt::LeftButton)&&(event->pos().x()<=pix.width())) //鼠标左键按下
    {
        endPoint = event->pos();
        ui->startX_label->setText(QString::number(lastPoint.x(),10));
        ui->startY_label->setText(QString::number(lastPoint.y(),10));
        ui->endX_label->setText(QString::number(endPoint.x(),10));
        ui->endY_label->setText(QString::number(endPoint.y(),10));
//        ui->endA_label->setText();
        update();
        emit MyCarClickedSignal(quint16(endPoint.x()),quint16(endPoint.y()));//0~700
    }
}

bool ComeBackFlag = false;
void Form::MyCarComeBack(quint16 x, quint16 y)
{
    endPoint_1 = QPoint(x,y);
    ComeBackFlag = true;
    update();
}

void Form::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    openFlag = false;
}

void Form::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPainter pp(&pix);
    if(ComeBackFlag == true)
    {
        color = QColor(195,0,0);//画笔颜色
        value = 3;
        style = Qt::PenStyle(1);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        ComeBackFlag = false;
        pp.drawLine(lastPoint, endPoint_1);//绘制连续的线段
        lastPoint = endPoint_1;
    }
    else
    {
        color = QColor(0,0,255);//画笔颜色
        value = 2;
        style = Qt::PenStyle(3);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        pp.drawLine(lastPoint, endPoint);//绘制连续的线段
    }
    painter.drawPixmap(0, 0, pix);

    //painter.setPen(pen);
    painter.setBrush(brush);
    QRect rect(0,0,PixMapWidth,PixMapHeight);

    switch(shape)
    {
       case Line:                                         	//直线
            painter.drawLine(rect.topLeft(),rect.bottomRight()); 	break;
       case Rectangle:                                    	//长方形
            painter.drawRect(rect);	break;
       case RoundRect:                                    	//圆角方形
            painter.drawRoundRect(rect); 	break;
       case Ellipse:                                      	//椭圆形
            painter.drawEllipse(rect); 	break;
//            case Polygon:                                      	//多边形
//                painter.drawPolygon(points,4); 	break;
//            case Polyline:                                      //多边线
//                painter.drawPolyline(points,4); 	break;
//            case Points:                                      	//点
//                painter.drawPoints(points,4); 	break;
//            case Arc:                                          	//弧
//                painter.drawArc(rect,startAngle,spanAngle);	 break;
//            case Path:                                         	//路径
//                painter.drawPath(path); 	break;
        case Text:                                        	//文字
             painter.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));	break;
        case Pixmap:                                      	//图片
             painter.drawRect(rect);painter.drawPixmap(0,634,QPixmap(":/image/img/axid.png")); 	break;
        default: 	break;
    }
}

void Form::on_back_pushButton_clicked()
{
    endPoint = QPoint(pix.width()/2,pix.height()/2);
    ui->startX_label->setText(QString::number(lastPoint.x(),10));
    ui->startY_label->setText(QString::number(lastPoint.y(),10));
    ui->endX_label->setText(QString::number(endPoint.x(),10));
    ui->endY_label->setText(QString::number(endPoint.y(),10));
    update();
    emit MyCarClickedSignal(quint16(endPoint.x()),quint16(endPoint.y()));
}

void Form::on_clear_pushButton_clicked()
{
    QPixmap clearPix =QPixmap(PixMapWidth,PixMapHeight);
    clearPix.fill(Qt::white);
    pix = clearPix;
    update();
}

