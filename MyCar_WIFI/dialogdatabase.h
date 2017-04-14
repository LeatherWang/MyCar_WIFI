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

private slots:
    void on_refreshpushButton_clicked();

    void on_deletepushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialogdatabase *ui;
    QSqlTableModel *model;
    QSqlDatabase Qdb;
};

#endif // DIALOGDATABASE_H
