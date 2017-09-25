#include "apinfo.h"

bool robotInitFlag = false;
double P_S_RiValue[RiNum];
float RSSIValue[BSSID_raw]={0.0};
float lastRSSIValue[BSSID_raw]={0.0};
quint8 SlipWindow[5] = {0}; //定义一个滑窗，防止跳变
QStringList BSSIDList = (QStringList() << "bc:d1:77:25:11:a2" << "ec:88:8f:54:10:dc" << "cc:34:29:89:2f:a0" << "ec:17:2f:51:3c:66");

struct POSITION fusePos, WKNNPos, wifiPos, wifiPosSuc, TempPos;
struct POS_ODOMETER odometer, lastOdometer, errorOdometer, lastMatchOdom;
struct NOISE noiseWifiPosX, noiseWifiPosY;

struct APInformation apInformation, apInformationTemp;


