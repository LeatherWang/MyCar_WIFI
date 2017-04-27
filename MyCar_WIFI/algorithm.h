#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QDebug>

class Algorithm
{
public:
    Algorithm();
    float LimitingFilter(float param, float lastparam, float limitingValue);

    const static int MOVAVG_SIZE = 60;//只有这种类型可以初始化并赋值
    // FIFO 队列
    float Queue_buffer[4][MOVAVG_SIZE];
    unsigned char queueIndex[4];
    void Queue_NewValue(float val, unsigned char index);
    float Queue_getAvg(float * buff, unsigned char size); //平均值
    float Queue_getStradDev(float * buff, float avg, unsigned char size); //标准差
    float my_sqrt(float number);//快速平方根

    double KalmanFilter_1(const double ResrcData,double ProcessNiose_Q,double MeasureNoise_R);//卡尔曼滤波
    double KalmanFilter_2(double Now_Measure);
};

#endif // ALGORITHM_H
