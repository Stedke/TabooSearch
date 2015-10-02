#include "dialog1.h"
#include "ui_dialog1.h"

void Dialog1::zmiana(int co, int jak)
{
    d[co]=jak;
}

void Dialog1::odbior1(int naco)
{
    emit zmianasygnal(0,naco);
}

void Dialog1::odbior2(int naco)
{
    emit zmianasygnal(1,naco);
}

void Dialog1::odbior3(int naco)
{
    emit zmianasygnal(2,naco);
}

void Dialog1::odbior4(int naco)
{
    emit zmianasygnal(3,naco);
}

void Dialog1::odbioralfa(int naco)
{
    emit zmianasygnal(4,naco);
}

void Dialog1::odbiorK(int naco)
{
    emit zmianasygnal(5,naco);
}

void Dialog1::odbiorT(int naco)
{
    emit zmianasygnal(6,naco);
}

void Dialog1::odbiorLM(int naco)
{
    emit zmianasygnal(7,naco);
}

void Dialog1::odbiorkrok(int naco)
{
    emit zmianasygnal(8,naco);
}

void Dialog1::zwrocdane()
{
    emit paczka(this->d);
}

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),d(9),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
/*
    QPixmap ikona(":/ikony/Queen_chrysalis300.png");
    ui->label_10->setPixmap(ikona);
*/
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(zwrocdane()));
    connect(this,SIGNAL(zmianasygnal(int,int)),this,SLOT(zmiana(int,int)));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(odbior1(int)));
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(odbior2(int)));
    connect(ui->comboBox_2,SIGNAL(activated(int)),this,SLOT(odbior3(int)));
    connect(ui->comboBox_3,SIGNAL(activated(int)),this,SLOT(odbior4(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(odbioralfa(int)));
    connect(ui->spinBox_3,SIGNAL(valueChanged(int)),this,SLOT(odbiorK(int)));
    connect(ui->spinBox_4,SIGNAL(valueChanged(int)),this,SLOT(odbiorT(int)));
    connect(ui->spinBox_5,SIGNAL(valueChanged(int)),this,SLOT(odbiorLM(int)));
    connect(ui->spinBox_6,SIGNAL(valueChanged(int)),this,SLOT(odbiorkrok(int)));

    ui->comboBox->addItem("losowo");
    ui->comboBox->addItem("recznie");
    ui->comboBox->addItem("bez zmian");

    ui->comboBox_2->addItem("nie");
    ui->comboBox_2->addItem("tak");

    ui->comboBox_3->addItem("nie");
    ui->comboBox_3->addItem("tak");

    connect(this,SIGNAL(zmiana1(int)),ui->spinBox,SLOT(setValue(int)));
    connect(this,SIGNAL(zmiana2(int)),ui->comboBox,SLOT(setCurrentIndex(int)));
    connect(this,SIGNAL(zmiana3(int)),ui->comboBox_2,SLOT(setCurrentIndex(int)));
    connect(this,SIGNAL(zmiana4(int)),ui->comboBox_3,SLOT(setCurrentIndex(int)));
    connect(this,SIGNAL(zmiana5(int)),ui->spinBox_2,SLOT(setValue(int)));
    connect(this,SIGNAL(zmiana6(int)),ui->spinBox_3,SLOT(setValue(int)));
    connect(this,SIGNAL(zmiana7(int)),ui->spinBox_4,SLOT(setValue(int)));
    connect(this,SIGNAL(zmiana8(int)),ui->spinBox_5,SLOT(setValue(int)));
    connect(this,SIGNAL(zmiana9(int)),ui->spinBox_6,SLOT(setValue(int)));
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::pamietaj(QVector<int> dana)
{
    d=dana;
    emit zmiana1(d[0]);
    emit zmiana2(d[1]);
    emit zmiana3(d[2]);
    emit zmiana4(d[3]);
    emit zmiana5(d[4]);
    emit zmiana6(d[5]);
    emit zmiana7(d[6]);
    emit zmiana8(d[7]);
    emit zmiana9(d[8]);

    emit update();
}



