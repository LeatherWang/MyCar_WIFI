#ifndef SCOPE_H
#define SCOPE_H

#include <QWidget>

namespace Ui {
class scope;
}

class scope : public QWidget
{
    Q_OBJECT

public:
    explicit scope(QWidget *parent = 0);
    ~scope();

    void showScope(float para1 , float para2);
private:
    Ui::scope *ui;
};

#endif // SCOPE_H
