#ifndef SCOPE_H
#define SCOPE_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class scope;
}

class scope : public QWidget
{
    Q_OBJECT

public:
    explicit scope(QWidget *parent = 0);
    ~scope();

    void showScope(float para1 , float para2, float para3, float para4);
    bool openFlag;
    void showAvgAndStradDev(float value, float avg, float stradDev, unsigned char index);
protected:
     void closeEvent(QCloseEvent *event);
private:
    Ui::scope *ui;
};

#endif // SCOPE_H
