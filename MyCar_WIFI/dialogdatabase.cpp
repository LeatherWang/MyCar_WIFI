#include "dialogdatabase.h"
#include "ui_dialogdatabase.h"

Dialogdatabase::Dialogdatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdatabase)
{
    ui->setupUi(this);
    setWindowTitle("数据库");

    if(QSqlDatabase::contains("xxx.db"))
        Qdb = QSqlDatabase::database("xxx.db");
    else
    {
        Qdb = QSqlDatabase::addDatabase("QSQLITE", "xxx.db");
        Qdb.setDatabaseName("xxx.db");//设置数据库名，这句话不能少
        bool ok = Qdb.open();         //尝试连接数据库
        if(ok)  qDebug()<<"xxxxxx链接数据库成功xxxxxxxxx";
        else    qDebug()<<"xxxxxx链接数据库失败，因为"<<Qdb.lastError().text();
    }

    model = new QSqlTableModel(this,Qdb);
    model->setTable("RSSIValueTable");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置保存策略为手动提交
    model->select(); //选取整个表的所有行
    // model->removeColumn(1); //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(model);
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //使其不可编辑
}

Dialogdatabase::~Dialogdatabase()
{
    delete ui;
}

void Dialogdatabase::on_refreshpushButton_clicked()
{
    model->submitAll();//刷新显示
}

void Dialogdatabase::on_deletepushButton_clicked()
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

void Dialogdatabase::on_pushButton_clicked()
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












