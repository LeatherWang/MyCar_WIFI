#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QDebug>

class Algorithm
{
public:
    Algorithm();
    float LimitingFilter(quint8 index, float param, float lastparam, float limitingValue);

    const static int MOVAVG_SIZE = 60;//只有这种类型可以初始化并赋值
    const static int LinkArraySize = 12;
    // FIFO 队列
    float Queue_buffer[4][MOVAVG_SIZE];
    unsigned char queueIndex[4];
    quint8 LinkArray[LinkArraySize][LinkArraySize];

    void Queue_NewValue(float val, unsigned char index);
    float Queue_getAvg(float * buff, unsigned char size); //平均值
    float Queue_getStradDev(float * buff, float avg, unsigned char size); //标准差
    float my_sqrt(float number);//快速平方根

    double KalmanFilter_1(const double ResrcData,double ProcessNiose_Q,double MeasureNoise_R);//卡尔曼滤波
    double KalmanFilter_AP1(double Now_Measure);
    double KalmanFilter_AP2(double Now_Measure);
    double KalmanFilter_AP3(double Now_Measure);
    double KalmanFilter_AP4(double Now_Measure);
    double KalmanFilterSwitchAPNo(double Now_Measure, quint8 index);
    void   AddSlipWinQueue(quint8 val, quint8 *SlipWindow);
    double KalmanDataFuseX(const double zX, double dX, double ProcessNiose_Q, double MeasureNoise_R);
    double KalmanDataFuseY(const double zY, double dY, double ProcessNiose_Q, double MeasureNoise_R);
};

#endif // ALGORITHM_H
