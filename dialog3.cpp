#include "dialog3.h"
#include "ui_dialog3.h"
#include <QMovie>
#include <QLabel>

Dialog3::Dialog3(QWidget *parent,const QString & name,bool film) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

    if(film==true)
    {
        QMovie *movie = new QMovie(name);
        QLabel *processLabel = new QLabel(this);
        processLabel->setMovie(movie);
        movie->start();
    }
    else
    {
        QLabel *label = new QLabel(this);
        QPixmap ikona(name);
        label->setPixmap(ikona);
    }
}

Dialog3::~Dialog3()
{
    delete ui;
}
