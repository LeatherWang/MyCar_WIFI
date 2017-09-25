#ifndef APINFO
#define APINFO
#include <QDebug>
#include <QStringList>
#include "math.h"

#define BSSID_raw 4
#define NUMBER_AP BSSID_raw
#define my_pow(x) ((x)*(x))
#define EXP 2.7183
#define TWOPI2 39.4784
#define RiNum 50

extern bool robotInitFlag;
extern double P_S_RiValue[RiNum];
extern float RSSIValue[BSSID_raw];
extern float lastRSSIValue[BSSID_raw];
extern quint8 SlipWindow[5]; //定义一个滑窗，防止跳变
extern QStringList BSSIDList;

struct APInformation
{
    quint16 id;
    float RSSIValueAvg[NUMBER_AP];
    float RSSIValueDev[NUMBER_AP];
    float RSSIValueKFFilter[NUMBER_AP];
    float X;
    float Y;
};

struct POS_ODOMETER
{
    qint16 X;
    qint16 Y;
    qint16 Z;
};

struct POSITION
{
    float X;
    float Y;
    float Z;
};

struct NOISE
{
    double ProcessNiose_Q;
    double MeasureNoise_R;
};

extern struct POSITION fusePos, WKNNPos, wifiPos, wifiPosSuc, TempPos;
extern struct POS_ODOMETER odometer, lastOdometer, errorOdometer, lastMatchOdom;
extern struct NOISE noiseWifiPosX, noiseWifiPosY;

extern struct APInformation apInformation, apInformationTemp;

#endif // APINFO

