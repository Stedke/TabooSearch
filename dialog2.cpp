#include "dialog2.h"
#include "ui_dialog2.h"

void Dialog2::dane(int a, double b)
{
    double a1=a;

    ui->widget->graph(0)->addData(a1,b);
    ui->widget->xAxis->rescale();
    ui->widget->yAxis->rescale();
    ui->widget->replot();
}

void Dialog2::resetuj()
{
    ui->widget->graph(0)->clearData();
    ui->widget->replot();
}

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
   // x.append(0);
   // y.append(0);

    ui->setupUi(this);

    /*QPixmap ikona(":/ikony/Nightmare_Moon300.png");
    ui->label->setPixmap(ikona);

    QPixmap ikona1(":/ikony/Princess_Celestia300.png");
    ui->label_2->setPixmap(ikona1);
*/
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));

    ui->widget->addGraph();
   // ui->widget->graph(0)->addData(x,y);

    ui->widget->xAxis->setLabel("iteracja");
    ui->widget->yAxis->setLabel("f celu");
    ui->widget->setUpdatesEnabled(true);

   // ui->widget->xAxis->rescale();
   // ui->widget->yAxis->rescale();
   // ui->widget->replot();
}

Dialog2::~Dialog2()
{
    delete ui;
}
