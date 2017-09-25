/*******************************************
 * 作者     ：王丕阁
 * 文件名   ：form.cpp
 * 函数功能 ：定位结果输出查看、地图显示
 * 修改日期 ：2017-05-18
  *****************************************/
#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("地图");
    setPalette(QPalette(Qt::white));//窗口背景设置
    setAutoFillBackground(true);
    setFixedSize(700,700);
    setAttribute(Qt::WA_QuitOnClose,false);//主窗口关闭其跟着一起关闭

    PixMapWidth = 350;
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
    Qt::BrushStyle style_brush = Qt::BrushStyle(11);//画刷风格，CrossPattern
    brush = QBrush(color_brush,style_brush);//设置画刷

    Qt::FillRule rule = Qt::FillRule(0);//设置填充模式，OddEvenFill
    fillRule = rule;

    shape = Form::Shape(10);//0->Line, 1->Rct

    endPoint = lastPoint = QPoint(0, 0);//起始点坐标，左上角
    ui->startX_label->setText(QString::number(lastPoint.x(),10));
    ui->startY_label->setText(QString::number(lastPoint.y(),10));

    //设置表格整行选取
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    openFlag = false;
    sendCounter =0;
    ComeBackFlag = 0;

    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(TimerUpdateSlot()));
}

Form::~Form()
{
    delete ui;
}

void Form::mousePressEvent(QMouseEvent *event)//单击发送
{
    if((event->button()==Qt::LeftButton)&&(event->pos().x()<=pix.width())) //鼠标左键按下
    {
        endPoint = event->pos();
        ui->endX_label->setText(QString::number(endPoint.x(),10));
        ui->endY_label->setText(QString::number(endPoint.y(),10));
        ComeBackFlag = 0;
        update();
        emit MyCarClickedSignal(quint16(endPoint.x()), quint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());//-350~+350
    }
}

void Form::on_pushButton_sendTargetPosition_clicked()//手动发送
{
    if(!ui->lineEdit_tragetX->text().isEmpty() && !ui->lineEdit_tragetY->text().isEmpty() && !ui->lineEdit_tragetZ->text().isEmpty())
    {
        sendCounter++;
        ui->label_sendCounter->setText(QString("已发送%1帧").arg(sendCounter));

        endPoint = QPoint(ui->lineEdit_tragetX->text().toInt(), ui->lineEdit_tragetY->text().toInt());
        ui->endX_label->setText(QString::number(endPoint.x(),10));
        ui->endY_label->setText(QString::number(endPoint.y(),10));
        ComeBackFlag = 0;
        update();
        emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());//-350~+350
    }
}

void Form::MyCarComeBack(qint16 x, qint16 y, float z)
{
    currentPoint = QPoint(x,y); //TODO:变换坐标范围
    ui->positionX_label->setText(QString::number(x,10));
    ui->positionY_label->setText(QString::number(y,10));
    ui->endA_label->setText(QString::number((double)z, 'g', 4));
    //ComeBackFlag = 1;
    //update();
}

void Form::MyWiFiComeBack(quint8 maxRiNo, double maxValue, double P_Ri_SValue, float *smpRSSIAvg, float *mthRSSIAvg, float positionx, float positiony)
{
    ui->label_matNo->setText(QString::number(maxRiNo, 10));
    ui->label_maxprob->setText(QString::number((double)maxValue, 'g', 4));
    ui->label_prob->setText(QString::number((double)P_Ri_SValue, 'g', 4));

    for(quint8 i=0; i< 4; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number((double)*(smpRSSIAvg +i), 'g', 4)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number((double)*(mthRSSIAvg +i), 'g', 4)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number((double)(*(smpRSSIAvg +i) - *(mthRSSIAvg +i)), 'g', 4)));
    }

    ui->label_matPX->setText(QString::number((double)positionx, 'g', 4));
    ui->label_matPY->setText(QString::number((double)positiony, 'g', 4));
}

void Form::WiFiInitLocation(qint16 x, qint16 y)
{
    WiFiLocPoint = QPoint(x, y);
    ui->startX_label->setText(QString::number(x,10));
    ui->startY_label->setText(QString::number(y,10));
    ComeBackFlag = 3;
    update();
}

void Form::FuseLocate(qint16 x, qint16 y)
{
    currentPoint = QPoint(x,y); //TODO:变换坐标范围
    ui->label_fuseX->setText(QString::number(x,10));
    ui->label_fuseY->setText(QString::number(y,10));
    ComeBackFlag = 2;
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
    switch (ComeBackFlag)
    {
    case 0: //起始点连线
        color = QColor(200,0,0);//画笔颜色
        value = 1;
        style = Qt::PenStyle(3);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        pp.drawLine(lastPoint+QPoint(175,10), endPoint+QPoint(175,10));//绘制连续的线段
        break;
    case 1: //编码器轨迹
        color = QColor(195,0,0);//画笔颜色
        value = 3;
        style = Qt::PenStyle(1);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        pp.drawLine(lastPoint+QPoint(175,10), currentPoint+QPoint(175,10));//绘制连续的线段
        lastPoint = currentPoint;
        break;
    case 2: //融合轨迹
        color = QColor(0,200,0);//画笔颜色
        value = 3;
        style = Qt::PenStyle(1);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        pp.drawLine(lastPoint+QPoint(175,10), currentPoint+QPoint(175,10));//绘制连续的线段
        lastPoint = currentPoint;
        break;
    case 3:
        color = QColor(43,53,244);//画笔颜色
        value = 12;
        style = Qt::PenStyle(1);
        pen = QPen(color,value,style,cap,join);
        pp.setPen(pen);
        pp.drawPoint(WiFiLocPoint.x()+175, WiFiLocPoint.y()+10);
        lastPoint = WiFiLocPoint;
        break;
    default:
        break;
    }
    ComeBackFlag = 0;

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
        case Text:                                        	//文字
             painter.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));	break;
        case Pixmap:                                      	//图片
             painter.drawRect(rect);painter.drawPixmap(0,634,QPixmap(":/image/img/axid.png")); 	break;
        default: 	break;
    }
}

void Form::on_back_pushButton_clicked()
{
    endPoint = QPoint(0, 0);
    ui->endX_label->setText(QString::number(endPoint.x(),10));
    ui->endY_label->setText(QString::number(endPoint.y(),10));
    update();
    emit MyCarClickedSignal(quint16(endPoint.x()), quint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
}

void Form::on_clear_pushButton_clicked()
{
    QPixmap clearPix =QPixmap(PixMapWidth,PixMapHeight);
    clearPix.fill(Qt::white);
    pix = clearPix;
    update();
}


void Form::on_pushButton_up_clicked()
{
    endPoint =QPoint(endPoint.x(), currentPoint.y()+10);
    ui->endX_label->setText(QString::number(endPoint.x(),10));
    ui->endY_label->setText(QString::number(endPoint.y(),10));
    update();
    emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
}

void Form::on_pushButton_down_clicked()
{
    if(currentPoint.y()>10)
    {
        endPoint =QPoint(endPoint.x(), currentPoint.y()-10);
        ui->endX_label->setText(QString::number(endPoint.x(),10));
        ui->endY_label->setText(QString::number(endPoint.y(),10));
        update();
        emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
    }
}

void Form::on_pushButton_right_clicked()
{
    endPoint =QPoint(currentPoint.x()+10, endPoint.y());
    ui->endX_label->setText(QString::number(endPoint.x(),10));
    ui->endY_label->setText(QString::number(endPoint.y(),10));
    update();
    emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
}

void Form::on_pushButton_left_clicked()
{
    if(currentPoint.x()>10)
    {
        endPoint =QPoint(currentPoint.x()-10, endPoint.y());
        ui->endX_label->setText(QString::number(endPoint.x(),10));
        ui->endY_label->setText(QString::number(endPoint.y(),10));
        update();
        emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
    }
}

void Form::on_pushButton_tenFont_clicked()
{
    TimerUpdateSlot();
    myTimer->start(5000);
}

void Form::TimerUpdateSlot()
{
    static quint8 index=1;
    static QPoint PointTemp;
    switch (index)
    {
    case 1:
        PointTemp = currentPoint;
        endPoint = PointTemp + QPoint(20, 0);
        break;
    case 2:
        endPoint = PointTemp + QPoint(0, 20);
        break;
    case 3:
        endPoint = PointTemp + QPoint(-20, 0);
        break;
    case 4:
        endPoint = PointTemp + QPoint(0, -20);
        break;
    case 5:
        endPoint = PointTemp;
        index = 0;
        myTimer->stop();
        break;
    default:
        break;
    }
    index++;
    update();
    emit MyCarClickedSignal(qint16(endPoint.x()), qint16(endPoint.y()), ui->lineEdit_tragetZ->text().toFloat());
}
















