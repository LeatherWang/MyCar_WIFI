#include "algorithm.h"

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

float Algorithm::LimitingFilter(float param, float lastparam, float limitingValue)
{
    if(ABS(param - lastparam) < limitingValue)
        return param; //返回本次值
    else
        return lastparam; //返回上次值
}

void Algorithm::Queue_NewValue(float val, unsigned char index)
{
    Queue_buffer[index][ queueIndex[index] ] = val;
    queueIndex[index] = (queueIndex[index] + 1) % MOVAVG_SIZE;
}

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
