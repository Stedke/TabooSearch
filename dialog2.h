#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public slots:
    void dane(int a,double b);
    void resetuj();

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;
    QVector<double> x;
    QVector<double> y;
};

#endif // DIALOG2_H
