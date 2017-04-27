#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"

Dialogdatabase::Dialogdatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdatabase)
{
    ui->setupUi(this);
    setWindowTitle("数据库");

    APTable = (QStringList() << "id" << "RSSI1_Avg" << "RSSI1_Dev" << "RSSI2_Avg" << "RSSI2_Dev"
                             << "RSSI3_Avg" << "RSSI3_Dev" << " RSSI4_Avg" << "RSSI4_Dev" << "X" << "Y");
    TableNumber = (QStringList() << "RSSIValueTable" << "TransferTable");

    if(QSqlDatabase::contains("xxx.db"))
        Qdb = QSqlDatabase::database("xxx.db");
    else
    {
        Qdb = QSqlDatabase::addDatabase("QSQLITE", "xxx.db");
        Qdb.setDatabaseName("xxx.db");//设置数据库名，这句话不能少
        bool ok = Qdb.open();         //尝试连接数据库
        if(ok)  qDebug()<<"xxxxxx链接数据库成功xxxxxxxxx";
        else    qDebug()<<"xxxxxx链接数据库失败，因为"<<Qdb.lastError().text();

        QSqlQuery query(Qdb);
        bool success=query.exec("create table RSSIValueTable(id integer primary key, RSSI1_Avg float, RSSI1_Dev float, RSSI2_Avg float, RSSI2_Dev float,"
                                "RSSI3_Avg float, RSSI3_Dev float, RSSI4_Avg float, RSSI4_Dev float, X float, Y float)");
        if(success)
            qDebug()<<"数据库表 RSSIValueTable 创建成功！\n";
        else
            qDebug()<<"数据库表 RSSIValueTable 创建失败或者已经存在！\n";

        success=query.exec("create table TransferTable(id integer primary key, DEV_NUM float)");
        if(success)
            qDebug()<<"数据库表 TransferTable 创建成功！\n";
        else
            qDebug()<<"数据库表 TransferTable 创建失败或者已经存在！\n";
    }

    model = new QSqlTableModel(this, Qdb);
    model->setTable("RSSIValueTable"); //TransferTable
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置保存策略为手动提交
    model->select(); //选取整个表的所有行
    // model->removeColumn(1); //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(model);
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
}

Dialogdatabase::~Dialogdatabase()
{
    delete ui;
}

void Dialogdatabase::saveToDatabase(quint16 id, float *RSSI_Avg, float *RSSI_Dev, float Value_X, float Value_Y)//增
{
    QSqlQuery query(Qdb);

/*    query.exec("select *from RSSIValueTable");
    query.last(); //query指向结果集的最后一条记录
    int ID = query.value("id").toInt();*/

    query.prepare("insert into RSSIValueTable values(:id, :RSSI1_Avg, :RSSI1_Dev, :RSSI2_Avg, :RSSI2_Dev,"
                  ":RSSI3_Avg, :RSSI3_Dev, :RSSI4_Avg, :RSSI4_Dev, :X, :Y)");
    query.bindValue(":id", id);
    query.bindValue(":RSSI1_Avg", *RSSI_Avg);
    query.bindValue(":RSSI1_Dev", *(RSSI_Dev));
    query.bindValue(":RSSI2_Avg", *(RSSI_Avg+1));
    query.bindValue(":RSSI2_Dev", *(RSSI_Dev+1));
    query.bindValue(":RSSI3_Avg", *(RSSI_Avg+2));
    query.bindValue(":RSSI3_Dev", *(RSSI_Dev+2));
    query.bindValue(":RSSI4_Avg", *(RSSI_Avg+3));
    query.bindValue(":RSSI4_Dev", *(RSSI_Dev+3));
    query.bindValue(":X", Value_X);
    query.bindValue(":Y", Value_Y);

    if(!query.exec())
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<"插入失败！";
    }

    if(this->openFlag == true)//自动刷新太卡，改为手动
    {
        this->on_pushButton_dbRefresh_clicked();
    }
}

void Dialogdatabase::deleteFromDatabase(quint16 id)//删
{
    QSqlQuery query(Qdb);
    query.prepare(QString("delete from RSSIValueTable where id = 1%").arg(id));

    if(!query.exec())
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<"删除失败！";
    }
}

void Dialogdatabase::updateFromDatabase(quint16 id, quint16 index, float value)//改
{
    QSqlQuery query(Qdb);
    query.exec(QString("update RSSIValueTable set 1% = :1% where id = :id").arg(APTable.value(index)).arg(APTable.value(index)));
    query.bindValue(":id", id);
    query.bindValue(QString(":1%").arg(APTable.value(index)),value);

    if(!query.exec())
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<"修改失败！";
    }
}

float Dialogdatabase::lookupFromDatabase(quint8 tableNo, quint16 id, quint8 index)//查
{
    float dataTemp;
    QSqlQuery query(Qdb);
    query.prepare(QString("select *from %1 where id = %2").arg(TableNumber.value(tableNo)).arg(id));

    if(!query.exec())
    {
        QSqlError lastError=query.lastError();
        qDebug()<<lastError.driverText()<<"查询失败！";
    }
    else
    {
        while(query.next())
        {
            dataTemp = query.value(index).toFloat();
        }
    }
    return dataTemp;
}

void Dialogdatabase::on_pushButton_dbAddData_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
    int id = rowNum+1;
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum,0),id);  //给新行添加id属性值
    int ok = QMessageBox::warning(this,tr("添加当前行!"),tr("你确定""添加当前行吗"),QMessageBox::Yes,QMessageBox::No);

    if(ok == QMessageBox::No)
    {
        model->revertAll();
    }
    else model->submitAll();
}

void Dialogdatabase::on_pushButton_dbDeleteData_clicked()
{
    int curRow = ui->tableView->currentIndex().row();//获取选中的行
    model->removeRow(curRow);   //删除一行//删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定""删除当前行吗"),QMessageBox::Yes,QMessageBox::No);

    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }
    else model->submitAll(); //否则提交，在数据库中删除该行
}

void Dialogdatabase::on_pushButton_dbRefresh_clicked()
{
    model->submitAll();//刷新显示
}

void Dialogdatabase::on_pushButton_dbDeleteAll_clicked()
{
    int ok = QMessageBox::warning(this,tr("删除!"),tr("你确定""清空数据表内容吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        QSqlQuery query(Qdb);
        query.exec("delete from RSSIValueTable");
        model->submitAll();//刷新显示
    }
}
