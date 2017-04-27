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
#define RiNum 51

float P_S_RiValue[RiNum];
float RSSIValue[BSSID_raw]={0.0};
float lastRSSIValue[BSSID_raw]={0.0};
QStringList BSSIDList = (QStringList() << "bc:d1:77:25:11:a2" << "ec:88:8f:54:10:dc" << "cc:34:29:89:2f:a0" << "ec:17:2f:51:3c:66");

struct APInformation
{
    quint16 id;
    float RSSIValueAvg[NUMBER_AP];
    float RSSIValueDev[NUMBER_AP];
    float X;
    float Y;
};

struct APInformation apInformation, apInformationTemp;
#endif // APINFO

