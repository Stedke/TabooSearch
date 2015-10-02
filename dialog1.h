#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public slots:
    void zmiana(int co,int jak);
    void odbior1(int naco);
    void odbior2(int naco);
    void odbior3(int naco);
    void odbior4(int naco);

    void odbioralfa(int naco);
    void odbiorK(int naco);
    void odbiorT(int naco);
    void odbiorLM(int naco);
    void odbiorkrok(int naco);

    void zwrocdane();

signals:
    void zmianasygnal(int co,int jak);
    void paczka(QVector<int> da);

    void zmiana1(int naco);
    void zmiana2(int naco);
    void zmiana3(int naco);
    void zmiana4(int naco);
    void zmiana5(int naco);
    void zmiana6(int naco);
    void zmiana7(int naco);
    void zmiana8(int naco);
    void zmiana9(int naco);
    void update();

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    void pamietaj(QVector<int> dana);

private:
    Ui::Dialog1 *ui;
    QVector<int> d;
};


#endif // DIALOG1_H
