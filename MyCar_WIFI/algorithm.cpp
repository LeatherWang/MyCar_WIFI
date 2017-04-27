#include "algorithm.h"
#include "math.h"

#define my_pow(x) ((x)*(x))
#define ABS(x) ( (x)>0?(x):-(x) )

Algorithm::Algorithm()
{
    for(int i=0; i<4; i++)
    {
      queueIndex[i] = 0;
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<MOVAVG_SIZE; j++)
        {
            Queue_buffer[i][j] = 0;
        }
    }
}

/*******************************************
*函数功能：快速平方根
  *****************************************/
float Algorithm::my_sqrt(float number)
{
    long i;
    float x, y;
    const float f = 1.5F;
    x = number * 0.5F;
    y = number;
    i = * ( long * ) &y;
    i = 0x5f3759df - ( i >> 1 );

    y = * ( float * ) &i;
    y = y * ( f - ( x * y * y ) );
    y = y * ( f - ( x * y * y ) );
    return number * y;
}

/*******************************************
*函数功能：队列缓存区
  *****************************************/
void Algorithm::Queue_NewValue(float val, unsigned char index)
{
    Queue_buffer[index][ queueIndex[index] ] = val;
    queueIndex[index] = (queueIndex[index] + 1) % MOVAVG_SIZE;
}

/*******************************************
*函数功能：求平均值
  *****************************************/
float Algorithm::Queue_getAvg(float * buff, unsigned char size)
{
  float sum = 0.0;
  int i;
  for(i=0; i<size; i++)
  {
    sum += buff[i];
  }
  return sum / size;
}

/*******************************************
*函数功能：求标准差
  *****************************************/
float Algorithm::Queue_getStradDev(float * buff, float avg, unsigned char size)
{
    float sum = 0.0;
    int i;
    for(i=0; i<size; i++)
    {
      sum += my_pow(buff[i] - avg);
    }
    return my_sqrt(sum/size);
}

/*******************************************
*函数功能：低通滤波
  *****************************************/
float Algorithm::LimitingFilter(float param, float lastparam, float limitingValue)
{
    if(ABS(param - lastparam) < limitingValue)
        return param; //返回本次值
    else
        return lastparam; //返回上次值
}

/*******************************************
*函数功能：卡尔曼滤波
  *****************************************/
double Algorithm::KalmanFilter_1(const double ResrcData,double ProcessNiose_Q,double MeasureNoise_R)
{
   double R = MeasureNoise_R;
   double Q = ProcessNiose_Q;
   static double x_last;//TODO--Leather
   double x_mid = x_last;
   double x_now;
   static double p_last=1;//TODO--Leather
   double p_mid ;
   double p_now;
   double kg;

   x_mid=x_last; //x_last=x(k-1|k-1),x_mid=x(k|k-1)
   p_mid=p_last+Q; //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q为过程噪声
   kg=p_mid/(p_mid+R); //kg为kalman filter系数，R为观测噪声协方差
   x_now=x_mid+kg*(ResrcData-x_mid);//估计出的最优值

   p_now=(1-kg)*p_mid;//最优值对应的covariance，后验估计协方差
   p_last = p_now; //更新covariance
   x_last = x_now; //更新系统状态值
   return x_now;
}

/*******************************************
*函数功能：卡尔曼滤波
  *****************************************/
#define WR  0.8
#define WQ  0.1
#define square(x)	( (x) * (x) )
double Algorithm::KalmanFilter_2(double Now_Measure)
{
    static double Actual_optimal;
    static double Dev;
    static double Dev_temp;
    static double Kg_temp ;
    static double Kg ;
    static double Dev_best_temp ;
    static double Dev_best;
    double H = 1;

    Dev_temp = square(Dev_best) +WQ;
    Dev = my_sqrt(Dev_temp);
    Kg_temp = square(Dev)/(square(H)*square(Dev)+square(WR));
    Kg = my_sqrt(Kg_temp);
    Actual_optimal =  Actual_optimal + Kg*(Now_Measure - H*Actual_optimal);
    Dev_best_temp = square((1-Kg*H)*square(Dev));
    Dev_best = my_sqrt(Dev_best_temp);

    return Actual_optimal;
}

#define APNumber 4
/*******************************************
*函数功能：计算P_S_Ri
  *****************************************/
double Algorithm::ComputeP_S_Ri(quint16 index)
{
    double Avg_u[APNumber], Dev_o[APNumber];
    for(quint8 i=0; i<APNumber; i++)
    {
        Avg_u[i] =


    }


}
