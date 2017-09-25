/*******************************************
 * 作者    ：王丕阁
 * 文件名   ：tcpsocket.cpp
 * 函数功能 ：TCP/IP通信
 * 修改日期 ：2017-05-27
  *****************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

bool openCloseFlag = false;
void MainWindow::on_pushButton_linkTCP_clicked()
{
    ui->messageLabel_linkTCPState->clear();
    if(openCloseFlag == false)
    {
        tcpSocket->abort(); //取消已有的连接
        tcpSocket->connectToHost("192.168.10.1",
                                 8082);//连接到主机，这里从界面获取主机地址和端口号
        openCloseFlag = true;
        ui->pushButton_linkTCP->setText("断开服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(255,128,128);");
        ui->messageLabel_linkTCPState->setText(QString("正在连接服务器......"));
    }
    else
    {
        tcpSocket->write("p");
        tcpSocket->disconnectFromHost();
        openCloseFlag = false;
        ui->pushButton_linkTCP->setText("连接服务器");
        ui->pushButton_linkTCP->setStyleSheet("background-color:rgb(145,200,200);");
        ui->messageLabel_linkTCPState->setText(QString("注意：未连接！！！"));
    }
}

void MainWindow::on_pushButton_sendTCP_clicked()
{
    tcpSocket->write(ui->textEdit_TCPSend->toPlainText().toLatin1());
}

void MainWindow::displayTCPError(QAbstractSocket::SocketError)
{
    ui->messageLabel_linkTCPState->setText(QString("<font color=red>Error!!! %1</font>").arg(tcpSocket->errorString()));
}

void MainWindow::connectFinish()
{
    ui->messageLabel_linkTCPState->setText(QString("<font color=green>连接成功！！！</font>"));
}

void MainWindow::on_pushButton_TCPClearCount_clicked()
{
    tcp_number_recive = 0;
    ui->label_tcpReceive->setText(QString("已接受%1帧数据").arg(tcp_number_recive));
}

#define ABS(x) ( (x)>0?(x):-(x) )
void MainWindow::readTCPMessage()
{
    quint8 countFrame;
    static quint8 locationFrq = 0;
    if(tcpSocket->bytesAvailable()>0)
    {
        const QByteArray data = tcpSocket->readAll();
        //ui->textBrowser_acceptTCP->append(data);
        for(quint8 i=0; i<BSSID_raw; i++)
        {
            countFrame=0;
            for(qint16 index=0; (index=data.indexOf(BSSIDList.value(i),index)) != -1; index+=17,countFrame++)
            {
                RSSIValue[i] = data.mid(data.indexOf("signal:",index) + 10 , 3).toFloat();
                if(RSSIValue[i] >= 0)//本次数据无效
                    return;
                if(ABS(lastRSSIValue[i] - RSSIValue[i]) < 30)//TODO
                    RSSIValue[i] = algorithm.LimitingFilter(i, RSSIValue[i], lastRSSIValue[i], 8);
                lastRSSIValue[i] = RSSIValue[i];
                algorithm.Queue_NewValue(RSSIValue[i],i); //队列递推

                //if(ui->comboBox_mode->currentIndex() == 1)
                apInformationTemp.RSSIValueKFFilter[i] = algorithm.KalmanFilterSwitchAPNo(RSSIValue[i], i);//TODO
            }
            apInformationTemp.RSSIValueAvg[i] = algorithm.Queue_getAvg(algorithm.Queue_buffer[i], Algorithm::MOVAVG_SIZE); //计算均值
            apInformationTemp.RSSIValueDev[i] = algorithm.Queue_getStradDev(algorithm.Queue_buffer[i], apInformationTemp.RSSIValueAvg[i], Algorithm::MOVAVG_SIZE);
            apInformationTemp.RSSIValueDev[i] +=1; //TODO

            if(myscope->openFlag == true)
                myscope->showAvgAndStradDev(RSSIValue[i], apInformationTemp.RSSIValueAvg[i], apInformationTemp.RSSIValueDev[i], i);
        }

        if(myscope->openFlag == true)
        {
            //RSSIValue[2] =algorithm.KalmanFilter_1(RSSIValue[1], 0.001, 0.8); //algorithm.KalmanFilter_2(RSSIValue[1]);
            //myscope->showKFFilter(RSSIValue[2]);//algorithm.KalmanFilter_1(RSSIValue[1], 0.00001, 0.8)
            //myscope->showScope(RSSIValue[0] , RSSIValue[1], RSSIValue[2], RSSIValue[3]);
//            RSSIValue[1] = apInformationTemp.RSSIValueKFFilter[0];
//            RSSIValue[3] = apInformationTemp.RSSIValueKFFilter[2];
            myscope->showScope(RSSIValue[0] , RSSIValue[1], RSSIValue[2], RSSIValue[3]);
        }

//        if(ui->comboBox_mode->currentIndex() == 1)
//        {
//            locationFrq++;
//            if(locationFrq == 2) //在线定位阶段
//            {
//                ComputeP_S_Rn(apInformationTemp.RSSIValueKFFilter);
//                locationFrq = 0;
//            }
//        }

        tcp_number_recive +=countFrame;
        ui->label_tcpReceive->setText(QString("已接受%1帧数据").arg(tcp_number_recive));
    }
}

/*******************************************
*函数功能：计算P_S_Rn
  *****************************************/
#define ErroThreshold 200
quint8 maxRiNo = 0;
double maxValue=0, numValue=0, P_Ri_SValue, P_Particle;
void MainWindow::ComputeP_S_Rn(float *rssiValueTemp)
{
    qint16 RiNumTemp;
    float Avg_u[NUMBER_AP];
    quint8 index_u=1;
    float rssiValue[4];
    static bool wifiAvi = false;

    memcpy(rssiValue, rssiValueTemp, sizeof(rssiValue)); //防覆盖
    if(((RiNumTemp = databaseDialog->lookupDatabaseRows()) <= 0)||(RiNumTemp > RiNum))
    {
        qDebug()<<"RiNumTemp="<<RiNumTemp<<"RiNum="<<RiNum;
        return;
    }

    maxRiNo = 0;maxValue = 0;numValue =0;P_Ri_SValue=0;
    for(quint8 i=0; i<RiNumTemp; i++) //RiNum，编号为0~(RiNumTemp-1)
    {
        P_S_RiValue[i] = ComputeP_S_Ri(i, rssiValue);

        if(maxValue < P_S_RiValue[i])
        {
            maxValue = P_S_RiValue[i];
            maxRiNo = i;
        }
        numValue += P_S_RiValue[i];
    }
    P_Ri_SValue = maxValue/numValue;
    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        Avg_u[i] = databaseDialog->lookupFromDatabase(0, maxRiNo, index_u);
        index_u +=2;
    }
    wifiPos.X = databaseDialog->lookupFromDatabase(0, maxRiNo, 9);
    wifiPos.Y = databaseDialog->lookupFromDatabase(0, maxRiNo, 10);
    myForm->MyWiFiComeBack(maxRiNo, maxValue, P_Ri_SValue, rssiValue, Avg_u, wifiPos.X, wifiPos.Y);//P(S|Ri)最值对应的编号，P(S|Ri)最大值，P(Ri|S)最大值，当前采样值，对应数据库中Ri，指纹位置

    if(robotInitFlag == false)
    {
        InitRobotLocat();
        //fusePos.X = fusePos.Y = 0;
        //robotInitFlag = true;
    }
    else
    {
        if(noiseWifiPosX.ProcessNiose_Q < 2)
            noiseWifiPosX.ProcessNiose_Q += (double)ABS(odometer.X - lastOdometer.X)/200.0; //更新预测协方差
        if(noiseWifiPosY.ProcessNiose_Q < 2)
            noiseWifiPosY.ProcessNiose_Q += (double)ABS(odometer.Y - lastOdometer.Y)/200.0;

        errorOdometer.X = odometer.X - lastMatchOdom.X;
        errorOdometer.Y = odometer.Y - lastMatchOdom.Y;

        if((P_Ri_SValue > 0.9) && (maxValue > 0.0001)) //TODO:第一步：判断该匹配点是否合理
        {
/*            for(quint8 j=0; j<algorithm.LinkArraySize ;j++) //第二步：遍历一行中所有的元素“1”-->判断是否跳变
            {
                if((algorithm.LinkArray[ SlipWindow[4] ][j] == 1) && (j == maxRiNo))
                {
                    qDebug()<<"成功预测！";
                    algorithm.AddSlipWinQueue(maxRiNo, SlipWindow); //加入滑窗中，当wifi得到一个新的位置估计时
                    wifiAvi = true;
                }//TODO:加入编码器方向数据，缩小范围
            }*/
            if(((maxRiNo - SlipWindow[4])*(errorOdometer.Y) >= 0) //WiFi定位与编码器定位方向是否相同？
                    &&(ABS(maxRiNo-fusePos.Y/100) <= 2))          //WiFi定位与编码器定位相差太多？
            {
                //qDebug()<<"成功预测！"<<"maxRiNo="<<maxRiNo<<"P_Ri_SValue="<<P_Ri_SValue;
                algorithm.AddSlipWinQueue(maxRiNo, SlipWindow); //加入滑窗中，当wifi得到一个新的位置估计时
                wifiAvi = true;
            }
            else
            {
                //qDebug()<<"kidnipping!!";
            }
        }

           /*WiFi定位与编码器定位完美融合*/
        if((wifiAvi == true) && (odometer.Y == lastOdometer.Y) && (ABS(errorOdometer.Y) > ErroThreshold))
        {
            wifiAvi = false;
//            noiseWifiPosX.MeasureNoise_R = 1 - P_Ri_SValue; //TODO:更新观测协方差
//            noiseWifiPosY.MeasureNoise_R = 1 - P_Ri_SValue;

//            fusePos.X = algorithm.KalmanDataFuseX(wifiPos.X, errorOdometer.X, noiseWifiPosX.ProcessNiose_Q, noiseWifiPosX.MeasureNoise_R);
//            fusePos.Y = algorithm.KalmanDataFuseY(wifiPos.Y, errorOdometer.Y, noiseWifiPosY.ProcessNiose_Q, noiseWifiPosY.MeasureNoise_R);

//            lastMatchOdom.X = odometer.X;
//            lastMatchOdom.Y = odometer.Y;

//            noiseWifiPosX.ProcessNiose_Q = 0.001;
//            noiseWifiPosY.ProcessNiose_Q = 0.001;
            qDebug()<<"融合";
//        } /*累计误差达到一定值，强制使用WKNN更新位置*/
//        else if(((ABS(errorOdometer.X) > ErroThreshold)
//                 || (ABS(errorOdometer.Y) > ErroThreshold))
//                 && (odometer.Y == lastOdometer.Y))
//        {
            //SquareInsertWKNN(rssiValue);//连续化--正方形插值法--WKNN
            LineInsertWKNN(rssiValue);

            noiseWifiPosX.MeasureNoise_R = (1 - P_Particle)*5; //TODO:更新观测协方差->由连续化算得概率幅值
            noiseWifiPosY.MeasureNoise_R = (1 - P_Particle)*5;

            fusePos.X = algorithm.KalmanDataFuseX(WKNNPos.X, errorOdometer.X, noiseWifiPosX.ProcessNiose_Q, noiseWifiPosX.MeasureNoise_R);
            fusePos.Y = algorithm.KalmanDataFuseY(WKNNPos.Y, errorOdometer.Y, noiseWifiPosY.ProcessNiose_Q, noiseWifiPosY.MeasureNoise_R);

            lastMatchOdom.X = odometer.X;
            lastMatchOdom.Y = odometer.Y;

            noiseWifiPosX.ProcessNiose_Q = 0.001;
            noiseWifiPosY.ProcessNiose_Q = 0.001;
        } /*仅使用编码器定位*/
        else
        {
            fusePos.X +=odometer.X - lastOdometer.X; //WiFi不可用，编码器累计误差不太大，仅适用编码器更新位置
            fusePos.Y +=odometer.Y - lastOdometer.Y;
        }

        myForm->FuseLocate(fusePos.X, fusePos.Y);

        lastOdometer.X = odometer.X;
        lastOdometer.Y = odometer.Y;
    }
}

void MainWindow::InitRobotLocat()
{
    static quint8 initCounter = 0;
    if(((P_Ri_SValue > 0.9) && (maxValue > 0.0001)) || ((P_Ri_SValue > 0.95) && (maxValue > 0.00000001)))
    {
        if(SlipWindow[4] == maxRiNo)    initCounter++;
        else    initCounter = 0;

        if(initCounter == 10)
        {
            qDebug()<<"初始化完成！"<<"maxRiNo="<<maxRiNo;
            robotInitFlag = true;
            myForm->WiFiInitLocation(wifiPos.X, wifiPos.Y);
        }
        algorithm.AddSlipWinQueue(maxRiNo, SlipWindow);
    }
}

void MainWindow::SquareInsertWKNN(float *rssiValue)
{
    quint8 index_u=1, index_o=2;
    float Avg_u[NUMBER_AP], Dev_o[NUMBER_AP];
    quint8 squareArr[4]={0};
    float avgInsertTemp[2], avgInsert[NUMBER_AP], devInsertTemp[2], devInsert[NUMBER_AP], eulerNum[NUMBER_AP]={0};

    if((quint16)(fusePos.X/100) < 2)//TODO:修改fusePos.X/100最大值
    {
        squareArr[0] = ((quint16)(fusePos.Y/100))*3 + (quint16)(fusePos.X/100);//正方形左下角编号
        squareArr[1] = squareArr[0]+1;
        squareArr[2] = squareArr[0]+3;
        squareArr[3] = squareArr[0]+4;
    }

    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        Avg_u[0] = databaseDialog->lookupFromDatabase(0, squareArr[0], index_u);
        Avg_u[1] = databaseDialog->lookupFromDatabase(0, squareArr[1], index_u);
        Avg_u[2] = databaseDialog->lookupFromDatabase(0, squareArr[2], index_u);
        Avg_u[3] = databaseDialog->lookupFromDatabase(0, squareArr[3], index_u);

        avgInsertTemp[0] = ((100 - ((int)(fusePos.X))%100) * Avg_u[0] + (((int)(fusePos.X))%100) * Avg_u[1])/100.0;
        avgInsertTemp[1] = ((100 - ((int)(fusePos.X))%100) * Avg_u[2] + (((int)(fusePos.X))%100) * Avg_u[3])/100.0;
        avgInsert[i] = ((100 - ((int)(fusePos.Y))%100) * avgInsertTemp[0] + (((int)(fusePos.Y))%100) * avgInsertTemp[1])/100;

        Dev_o[0] = databaseDialog->lookupFromDatabase(0, squareArr[0], index_o);
        Dev_o[1] = databaseDialog->lookupFromDatabase(0, squareArr[1], index_o);
        Dev_o[2] = databaseDialog->lookupFromDatabase(0, squareArr[2], index_o);
        Dev_o[3] = databaseDialog->lookupFromDatabase(0, squareArr[3], index_o);

        devInsertTemp[0] = ((100 - ((int)(fusePos.X))%100) * Dev_o[0] + (((int)(fusePos.X))%100) * Dev_o[1])/100.0;
        devInsertTemp[1] = ((100 - ((int)(fusePos.X))%100) * Dev_o[2] + (((int)(fusePos.X))%100) * Dev_o[3])/100.0;
        devInsert[i] = ((100 - ((int)(fusePos.Y))%100) * devInsertTemp[0] + (((int)(fusePos.Y))%100) * devInsertTemp[1])/100;

        eulerNum[0] += (Avg_u[0]-rssiValue[i])*(Avg_u[0]-rssiValue[i]);
        eulerNum[1] += (Avg_u[1]-rssiValue[i])*(Avg_u[1]-rssiValue[i]);
        eulerNum[2] += (Avg_u[2]-rssiValue[i])*(Avg_u[2]-rssiValue[i]);
        eulerNum[3] += (Avg_u[3]-rssiValue[i])*(Avg_u[3]-rssiValue[i]);

        index_u +=2;
        index_o +=2;
    }

    //WKNN，加权K近邻法
    double N_WKNN[2]={0}, D_WKNN=0, coefWKNN;
    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        coefWKNN = 1.0/algorithm.my_sqrt(eulerNum[i]);
        N_WKNN[0] += coefWKNN * databaseDialog->lookupFromDatabase(0, squareArr[i], 9);
        N_WKNN[1] += coefWKNN * databaseDialog->lookupFromDatabase(0, squareArr[i], 10);
        D_WKNN += coefWKNN;
        qDebug()<<i<<":"<<eulerNum[i]<<coefWKNN;
    }
    if((odometer.X-lastMatchOdom.X) > ErroThreshold)
        WKNNPos.X = N_WKNN[0]/D_WKNN;
    else
        WKNNPos.X = fusePos.X;

    if((odometer.Y-lastMatchOdom.Y) > ErroThreshold)
        WKNNPos.Y = N_WKNN[1]/D_WKNN;
    else
        WKNNPos.Y = fusePos.Y;

    qDebug()<<WKNNPos.X<<WKNNPos.Y;
}

void MainWindow::LineInsertWKNN(float *rssiValue)
{
    quint8 index_u=1, index_o=2;
    float Avg_u[2], Dev_o[2];
    quint8 squareArr[2]={0};
    float avgInsert[NUMBER_AP], devInsert[NUMBER_AP], eulerNum[NUMBER_AP]={0};
    double mul_o=1, Exp_pow=0;

    if((quint16)(fusePos.X/100) < 2)//TODO:修改fusePos.X/100最大值
    {
        squareArr[0] = ((quint16)(fusePos.Y/100));//正方形左下角编号
        squareArr[1] = squareArr[0]+1;
    }

    TempPos.X = fusePos.X + odometer.X- lastOdometer.X; //当前估计值
    TempPos.Y = fusePos.Y + odometer.Y- lastOdometer.Y;

    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        Avg_u[0] = databaseDialog->lookupFromDatabase(0, squareArr[0], index_u);
        Avg_u[1] = databaseDialog->lookupFromDatabase(0, squareArr[1], index_u);

        avgInsert[i] = ((100 - ((int)(TempPos.Y))%100) * Avg_u[0] + (((int)(TempPos.Y))%100) * Avg_u[1])/100;

        Dev_o[0] = databaseDialog->lookupFromDatabase(0, squareArr[0], index_o);
        Dev_o[1] = databaseDialog->lookupFromDatabase(0, squareArr[1], index_o);

        devInsert[i] = ((100 - ((int)(TempPos.Y))%100) * Dev_o[0] + (((int)(TempPos.Y))%100) * Dev_o[1])/100;
        qDebug()<<avgInsert[i]<<devInsert[i];

        eulerNum[0] += (Avg_u[0]-rssiValue[i])*(Avg_u[0]-rssiValue[i]); //WKNN
        eulerNum[1] += (Avg_u[1]-rssiValue[i])*(Avg_u[1]-rssiValue[i]);

        index_u +=2;
        index_o +=2;

        Exp_pow += my_pow((rssiValue[i] - avgInsert[i])/devInsert[i]); //粒子概率
        mul_o *=devInsert[i];
    }

    //粒子概率
    P_Particle = pow(EXP, -Exp_pow/2.0)/(TWOPI2*mul_o);

    //WKNN，加权K近邻法
    double N_WKNN[2]={0}, D_WKNN=0, coefWKNN;
    for(quint8 i=0; i < 2; i++)
    {
        coefWKNN = 1.0/algorithm.my_sqrt(eulerNum[i]);
        N_WKNN[0] += coefWKNN * databaseDialog->lookupFromDatabase(0, squareArr[i], 9);
        N_WKNN[1] += coefWKNN * databaseDialog->lookupFromDatabase(0, squareArr[i], 10);
        D_WKNN += coefWKNN;
        qDebug()<<i<<":"<<eulerNum[i]<<coefWKNN;
    }

    if((odometer.X-lastMatchOdom.X) > ErroThreshold)
        WKNNPos.X = N_WKNN[0]/D_WKNN;
    else
        WKNNPos.X = fusePos.X;

    if((odometer.Y-lastMatchOdom.Y) > ErroThreshold)
        WKNNPos.Y = N_WKNN[1]/D_WKNN;
    else
        WKNNPos.Y = fusePos.Y;
}

void MainWindow::TimerUpdateSlot()
{
    if(ui->comboBox_mode->currentIndex() == 1)
        ComputeP_S_Rn(apInformationTemp.RSSIValueKFFilter);
}

/*******************************************
*函数功能：计算P_S_Ri
  *****************************************/
double MainWindow::ComputeP_S_Ri(quint16 id, float *rssiValue)
{
    float Avg_u[NUMBER_AP], Dev_o[NUMBER_AP];
    quint8 index_u=1, index_o=2;
    double mul_o=1, Exp_pow=0;
    for(quint8 i=0; i<NUMBER_AP; i++)
    {
        Avg_u[i] = databaseDialog->lookupFromDatabase(0, id, index_u);
        Dev_o[i] = databaseDialog->lookupFromDatabase(0, id, index_o);

        Exp_pow += my_pow((rssiValue[i] - Avg_u[i])/Dev_o[i]);
        mul_o *=Dev_o[i];
        index_u +=2;
        index_o +=2;
        //qDebug()<<rssiValue[i] << Avg_u[i] <<Dev_o[i];
    }
    return pow(EXP, -Exp_pow/2.0)/(TWOPI2*mul_o);
}

void MainWindow::RSSISaveSlot(quint8 index)
{
    if(index < 4)
    {
        apInformation.RSSIValueAvg[index] = apInformationTemp.RSSIValueAvg[index];
        apInformation.RSSIValueDev[index] = apInformationTemp.RSSIValueDev[index];
    }
    else if(index == 4)
    {
        apInformation.id = myscope->apInformation.id;
        apInformation.X = myscope->apInformation.X;
        apInformation.Y = myscope->apInformation.Y;

        if(databaseDialog->Qdb.isOpen() == true)
            databaseDialog->saveToDatabase(apInformation.id, apInformation.RSSIValueAvg, apInformation.RSSIValueDev, apInformation.X, apInformation.Y);
    }
    else if(index == 5)
    {
        ComputeP_S_Rn(apInformationTemp.RSSIValueAvg);
    }
}

