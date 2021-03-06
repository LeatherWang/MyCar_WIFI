#ifndef DIALOGDATABASE_H
#define DIALOGDATABASE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QtSql>
#include <QVariant>
#include <QMessageBox>

namespace Ui {
class Dialogdatabase;
}

class Dialogdatabase : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogdatabase(QWidget *parent = 0);
    ~Dialogdatabase();
    void saveToDatabase(quint16 id, float *RSSI_Avg, float *RSSI_Dev, float Value_X, float Value_Y);
    QSqlDatabase Qdb;
    bool openFlag;
    float lookupFromDatabase(quint8 tableNo, quint16 id, quint8 index);
    void updateFromDatabase(quint16 id, quint16 index, float value);
    void deleteFromDatabase(quint16 id);
    QStringList APTable;
    QStringList TableNumber;
    qint16 lookupDatabaseRows(void);
private:
    Ui::Dialogdatabase *ui;
    QSqlTableModel *model;

    QSqlQuery query;

private slots:
    void on_pushButton_dbAddData_clicked();
    void on_pushButton_dbDeleteData_clicked();
    void on_pushButton_dbRefresh_clicked();
    void on_pushButton_dbDeleteAll_clicked();

};

#endif // DIALOGDATABASE_H
