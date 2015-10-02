#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   /* QPixmap ikona(":/ikony/mlp300.png");
    ui->label_4->setPixmap(ikona);

    QPixmap ikona1(":/ikony/Fluffy_pony300.png");
    ui->label_5->setPixmap(ikona1);
*/
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),ui->pushButton_2,SLOT(settings()));
    connect(ui->pushButton_2,SIGNAL(daned(QVector<int>)),ui->tableWidget,SLOT(nowedaned(QVector<int>)));
    connect(ui->pushButton_2,SIGNAL(danez(QVector<int>)),ui->tableWidget_2,SLOT(nowedanez(QVector<int>)));

    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),ui->tableWidget,SLOT(startowed(int,int)));
    connect(ui->tableWidget_2,SIGNAL(cellDoubleClicked(int,int)),ui->tableWidget_2,SLOT(startowez(int,int)));

    connect(ui->pushButton_3,SIGNAL(clicked()),ui->tableWidget,SLOT(wyslijdaned()));

    connect(ui->tableWidget,SIGNAL(przeslijd(QVector<QTableWidgetItem>,QVector<int>)),ui->pushButton_3,SLOT(uruchom1(QVector<QTableWidgetItem>,QVector<int>)));
    connect(ui->tableWidget_2,SIGNAL(przeslijz(QVector<QTableWidgetItem>)),ui->pushButton_3,SLOT(uruchom2(QVector<QTableWidgetItem>)));

    connect(ui->pushButton_3,SIGNAL(juz()),ui->tableWidget_2,SLOT(wyslijdanez()));

    connect(ui->pushButton_3,SIGNAL(zmianacelu(double)),ui->lcdNumber,SLOT(display(double)));
    connect(ui->pushButton_3,SIGNAL(zmianaczasu(int)),ui->lcdNumber_2,SLOT(display(int)));
   //connect(ui->pushButton_3,SIGNAL(zmianaxtest(int)),ui->lcdNumber_3,SLOT(display(int)));
   //connect(ui->pushButton_3,SIGNAL(zmianaytest(int)),ui->lcdNumber_4,SLOT(display(int)));

    connect(ui->pushButton_3,SIGNAL(wyslijwynik(QVector<int>)),ui->tableWidget,SLOT(wynikdoszedld(QVector<int>)));
    connect(ui->pushButton_3,SIGNAL(wyslijwynik(QVector<int>)),ui->tableWidget_2,SLOT(wynikdoszedl(QVector<int>)));

    connect(ui->pushButton_2,SIGNAL(daneparam(QVector<int>)),ui->pushButton_3,SLOT(ustalparam(QVector<int>)));

    connect(ui->pushButton_4,SIGNAL(clicked()),ui->pushButton_4,SLOT(tworz()));
    connect(ui->pushButton_3,SIGNAL(plotas(int,double)),ui->pushButton_4,SLOT(przysylka(int,double)));

    connect(ui->pushButton_3,SIGNAL(resetuj()),ui->pushButton_4,SLOT(resetuj1()));

    connect(ui->pushButton_5,SIGNAL(clicked()),ui->pushButton_5,SLOT(czytajzpliku()));
    connect(ui->pushButton_5,SIGNAL(wczytajpocz(QVector<int>)),ui->tableWidget,SLOT(wczytajdanes(QVector<int>)));
    connect(ui->pushButton_5,SIGNAL(wczytajmacierz(QVector<QVector<int> >,QVector<QVector<int> >)),ui->tableWidget,SLOT(wczytajdanem(QVector<QVector<int> >,QVector<QVector<int> >)));
    connect(ui->pushButton_5,SIGNAL(wczytajpocz(QVector<int>)),ui->tableWidget_2,SLOT(wczytajdanesz(QVector<int>)));
    connect(ui->pushButton_5,SIGNAL(wczytajmacierz(QVector<QVector<int> >,QVector<QVector<int> >)),ui->tableWidget_2,SLOT(wczytajdanemz(QVector<QVector<int> >,QVector<QVector<int> >)));
    connect(ui->pushButton_5,SIGNAL(wczytajparam(QVector<int>)),ui->pushButton_2,SLOT(wczytajparam(QVector<int>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MyButton1::uruchom1(QVector<QTableWidgetItem> d,QVector<int> s)
{
    this->d1=d;
    this->s1=s;
    emit juz();
}

void MyButton1::uruchom2(QVector<QTableWidgetItem> d)
{
    emit resetuj();

/*
    Dialog3 *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10,*n11,*n12,*n13,*n14,*n15,*n16,*n17,*n18;

    const QString & gif1=":/ikony/aa.gif";
    n1=new Dialog3(this,gif1,true);
    n1->show();
    const QString & gif2=":/ikony/aaa.gif";
    n2=new Dialog3(this,gif2,true);
    n2->show();
    const QString & gif3=":/ikony/aaaa.gif";
    n3=new Dialog3(this,gif3,true);
    n3->show();
    const QString & gif4=":/ikony/aaaaa.gif";
    n4=new Dialog3(this,gif4,true);
    n4->show();
    const QString & gif5=":/ikony/aaaaaa.gif";
    n5=new Dialog3(this,gif5,true);
    n5->show();

    const QString & zd1=":/ikony/b.png";
    n6=new Dialog3(this,zd1,false);
    n6->show();
    const QString & zd2=":/ikony/ee.png";
    n7=new Dialog3(this,zd2,false);
    n7->show();
    const QString & zd3=":/ikony/e.png";
    n8=new Dialog3(this,zd3,false);
    n8->show();
    const QString & zd4=":/ikony/eeee.png";
    n9=new Dialog3(this,zd4,false);
    n9->show();
    const QString & zd5=":/ikony/c.png";
    n10=new Dialog3(this,zd5,false);
    n10->show();
    const QString & zd6=":/ikony/ff.png";
    n11=new Dialog3(this,zd6,false);
    n11->show();
    const QString & zd7=":/ikony/fff.png";
    n12=new Dialog3(this,zd7,false);
    n12->show();
    const QString & zd8=":/ikony/ffff.png";
    n13=new Dialog3(this,zd8,false);
    n13->show();
    const QString & zd9=":/ikony/ggg.png";
    n14=new Dialog3(this,zd9,false);
    n14->show();
    const QString & zd10=":/ikony/dd.png";
    n15=new Dialog3(this,zd10,false);
    n15->show();
    const QString & zd11=":/ikony/ddd.png";
    n16=new Dialog3(this,zd11,false);
    n16->show();
    const QString & zd12=":/ikony/dddd.png";
    n17=new Dialog3(this,zd12,false);
    n17->show();
    const QString & zd13=":/ikony/gg.png";
    n18=new Dialog3(this,zd13,false);
    n18->show();
*/
    double celuw=0;
    int czasow=0;
    this->d2=d;
    int xa=0;
    int ya=0;
    QVector<int> wynik;

    //dane backup
   /* QVector<int> parametry(5);
    parametry[0]=1;
    parametry[1]=1;
    parametry[2]=1;
    parametry[3]=1;
    parametry[4]=1;*/
    //dane backup

    QVector<int> tmp;
    QVector< QVector<int> >x1,y1;
    int a;

    a=this->d1.size(); //moze byc blad poprawie ale jak bugi to to winowajca
    int a1=sqrt(a);

    x1.resize(a1); //ustawienie dlugosci wektorow pomocniczych
    y1.resize(a1);

    for(int i=0;i<a1;i++)
    {
        x1[i].resize(a1);
        y1[i].resize(a1);
    }

    //konwersja z tablewidgetitem na int

    int k=1;
    int j=0;

    for(int i=0;i<a;i++)
    {
        if(i!=k*sqrt(a))
        {
            x1[k-1][j]=(d1[i].text()).toInt();
            y1[k-1][j]=(d2[i].text()).toInt();
        }
        else
        {
            k++;
            j=0;
            x1[k-1][j]=(d1[i].text()).toInt();
            y1[k-1][j]=(d2[i].text()).toInt();
        }

        j++;
    }

    connect(&(this->alg),SIGNAL(danarysuj(int,double)),this,SLOT(plota(int,double)));

    alg.wypelnij(x1,y1,this->s1,this->param);
    alg.rob();

    xa=alg.zwrocxtest();
    ya=alg.zwrocytest();
    tmp=alg.koniec();
    celuw=alg.zwroccel();
    czasow=alg.zwrocczas();
    wynik=alg.koniec();

    emit zmianacelu(celuw);
    emit zmianaczasu(czasow);
    emit zmianaxtest(s1[0]);
    emit zmianaytest(s1[1]);
    emit wyslijwynik(wynik);
}

void MyButton1::ustalparam(QVector<int> p)
{
    if(~(this->param.isEmpty()))
            this->param.clear();

    this->param.resize(5);

    param[0]=p[4];

    if(p[5]>0)
        param[1]=p[5];
    else
        param[1]=1;

    if(p[6]>0)
        param[2]=p[6];
    else
        param[2]=1;

    if(p[7]>0)
        param[3]=p[7];
    else
        param[3]=1;

    if(p[8]>0)
        param[4]=p[8];
    else
        param[4]=1;
}

void MyButton1::plota(int it, double cel)
{
    emit plotas(it,cel);
}

MyButton1::MyButton1(QWidget *parent) :
    QPushButton(parent)
{};

void MyButton2::settings()
{
    ptr=new Dialog1(this);
    //ptr->show();
    ptr->pamietaj(pamiec);
    ptr->show();
    connect(this->ptr,SIGNAL(paczka(QVector<int>)),this,SLOT(paczkeprzyjmij(QVector<int>)));
}

void MyButton2::paczkeprzyjmij(QVector<int> d)
{
    pamiec=d;
    emit daneparam(d);
    emit daned(d);
    emit danez(d);
}

void MyButton2::wczytajparam(QVector<int> p)
{
    this->pamiec=p;
    ptr=new Dialog1(this);
    //ptr->show();
    ptr->pamietaj(pamiec);
    ptr->show();
    connect(this->ptr,SIGNAL(paczka(QVector<int>)),this,SLOT(paczkeprzyjmij(QVector<int>)));
}

MyButton2::MyButton2(QWidget *parent) :
    QPushButton(parent),pamiec(9)
{
    for(int i=0;i<5;i++)
        pamiec[i]=0;

    for(int j=5;j<9;j++)
        pamiec[j]=1;
};

void Dochod::nowedaned(QVector<int> d)
{
    if(d[2]==1)
        this->clear();

    if(d[1]!=2)
    {
        if(~daned.isEmpty())
            daned.clear();
    }


    if(d[2]==1)
    {
        setColumnCount(d[0]);
        setRowCount(d[0]);

        for(int i=0;i<d[0];i++)
        {
            setColumnWidth(i,500/d[0]);
            setRowHeight(i,500/d[0]);
        }

        for(int i=0;i<d[0];i++)
            for(int j=0;j<d[0];j++)
            {
                int a=rand()%5;
                QString b;
                b.setNum(a,10);

                QTableWidgetItem *newItem= new QTableWidgetItem(b,1);

                this->setItem(i,j,newItem);
            }
    }
    else
    {
        int ax=this->rowCount();
        int by=this->columnCount();


        for(int i=0;i<ax;i++)
        {
            if(i>d[0]-1)
                this->removeRow(i);
        }

        for(int i=0;i<by;i++)
        {
            if(i>d[0]-1)
                this->removeColumn(i);
        }

        setColumnCount(d[0]);
        setRowCount(d[0]);

        for(int i=0;i<d[0];i++)
        {
            setColumnWidth(i,500/d[0]);
            setRowHeight(i,500/d[0]);
        }

        for(int i=0;i<d[0];i++)
            for(int j=0;j<d[0];j++)
            {
                if(i>ax-1 || j>by-1)
                {
                    QTableWidgetItem *newItem= new QTableWidgetItem("0",1);
                    this->setItem(i,j,newItem);
                }
            }
    }

    if(d[1]==0)
    {
        bool celestia=true;

        for(int i=0;i<d[7];i++)
        {
            celestia=true;

            while(celestia==true)
            {
                int tmpx,tmpy,a,b;
                a=d[0];
                b=d[0];
                bool chrysalis=true;

                tmpx=rand()%a;
                tmpy=rand()%b;

                for(int j=0;j<daned.size();j++)
                {
                    if(tmpx==daned[j] && tmpy==daned[j+1])
                        chrysalis=false;

                    j++;
                }

                if(chrysalis==true)
                {
                    daned.append(tmpx);
                    daned.append(tmpy);
                    celestia=false;
                }
            }
        }
    }


    switch(d[1])
    {
    case 0:
        recznied=false;
        break;
    case 1:
        recznied=true;
        break;
    case 2:
        recznied=false;
    }

    //test

    /*for(int i=0;i<daned.size();i++)
    {
        if(i%2==0)
        {
            QTableWidgetItem * newItem= new QTableWidgetItem("",2);
            newItem->setBackgroundColor(QColor(Qt::red));

            this->setItem(this->daned[i],this->daned[i+1],newItem);
        }
    }
*/
    //koniec testu

    this->repaint();
}

void Dochod::startowed(int x,int y)
{
    if(this->recznied==true)
    {
        this->daned.append(x);
        this->daned.append(y);
    }
}

void Dochod::wyslijdaned()
{
    QVector<QTableWidgetItem> d;
    QVector<int> s;

    for(int i=0;i<this->rowCount();i++)
        for(int j=0;j<this->columnCount();j++)
        {
            d.append(*(this->item(i,j)));
        }

    for(int i=0;i<(this->daned).size();i++)
        s.append((this->daned)[i]);

    emit przeslijd(d,s);
}

void Dochod::wynikdoszedld(QVector<int> ile)
{
    for(int i=0;i<this->rowCount();i++)
    {
        for(int j=0;j<this->columnCount();j++)
            (*(this->item(i,j))).setBackgroundColor(QColor(Qt::white));
    }

    for(int i=0;i<ile.size();i++)
    {
        QTableWidgetItem *ptr;
        ptr=this->item(ile[i],ile[i+1]);

        (*ptr).setBackgroundColor(QColor(Qt::green));

        i++;
    }
}

void Dochod::wczytajdanem(QVector<QVector<int> > d, QVector<QVector<int> > z)
{
    this->clear();
    setRowCount(d.size()-1);
    setColumnCount(d.size()-1);

    for(int i=0;i<d.size()-1;i++)
    {
        setColumnWidth(i,500/(d.size()-1));
        setRowHeight(i,500/(d.size()-1));
    }


    for(int i=0;i<d.size()-1;i++)
    {
        for(int j=0;j<d.size()-1;j++)
        {
            QTableWidgetItem *ptr=new QTableWidgetItem(1);
            QString str;
            str=str.number(d[i][j],10);
            (*ptr).setText(str);
            this->setItem(i,j,ptr);
        }
    }
    this->repaint();
}

void Dochod::wczytajdanes(QVector<int> a)
{
    this->daned=a;
}

Dochod::Dochod(QWidget *parent) :
    QTableWidget(parent),recznied(false)
{}

void Zywnosc::nowedanez(QVector<int> d)
{
    if(d[2]==1)
        this->clear();


    if(d[2]!=2)
    {
        if(~danez.isEmpty())
            danez.clear();
    }

    if(d[2]==1)
    {
        setColumnCount(d[0]);
        setRowCount(d[0]);

        for(int i=0;i<d[0];i++)
        {
            setColumnWidth(i,500/d[0]);
            setRowHeight(i,500/d[0]);
        }

        for(int i=0;i<d[0];i++)
            for(int j=0;j<d[0];j++)
            {
                int a=rand()%3;
                QString b;
                b.setNum(a,10);

                QTableWidgetItem *newItem= new QTableWidgetItem(b,1);

                this->setItem(i,j,newItem);
            }
    }
    else
    {
        int ax=this->rowCount();
        int by=this->columnCount();


        for(int i=0;i<ax;i++)
        {
            if(i>d[0]-1)
                this->removeRow(i);
        }

        for(int i=0;i<by;i++)
        {
            if(i>d[0]-1)
                this->removeColumn(i);
        }

        setColumnCount(d[0]);
        setRowCount(d[0]);

        for(int i=0;i<d[0];i++)
        {
            setColumnWidth(i,500/d[0]);
            setRowHeight(i,500/d[0]);
        }

        for(int i=0;i<d[0];i++)
            for(int j=0;j<d[0];j++)
            {
                if(i>ax-1 || j>by-1)
                {
                    QTableWidgetItem *newItem= new QTableWidgetItem("0",1);
                    this->setItem(i,j,newItem);
                }
            }
    }

    switch(d[1])
    {
    case 0:
        reczniez=false;
        break;
    case 1:
        reczniez=true;
        break;
    case 2:
        reczniez=false;
    }

    this->repaint();
}

void Zywnosc::startowez(int x,int y)
{
    if(this->reczniez==true)
    {
        this->danez.append(x);
        this->danez.append(y);
    }
}

void Zywnosc::wyslijdanez()
{
    QVector<QTableWidgetItem> d;

    for(int i=0;i<this->rowCount();i++)
        for(int j=0;j<this->columnCount();j++)
        {
            d.append(*(this->item(i,j)));
        }

    emit przeslijz(d);
}

void Zywnosc::wynikdoszedl(QVector<int> ile)
{
    for(int i=0;i<this->rowCount();i++)
    {
        for(int j=0;j<this->columnCount();j++)
            (*(this->item(i,j))).setBackgroundColor(QColor(Qt::white));
    }

    for(int i=0;i<ile.size();i++)
    {
        QTableWidgetItem *ptr;
        ptr=this->item(ile[i],ile[i+1]);

        (*ptr).setBackgroundColor(QColor(Qt::green));

        i++;
    }
}

void Zywnosc::wczytajdanemz(QVector<QVector<int> > d, QVector<QVector<int> > z)
{
    this->clear();
    setRowCount(z.size()-1);
    setColumnCount(z.size()-1);

    for(int i=0;i<z.size()-1;i++)
    {
        setColumnWidth(i,500/(z.size()-1));
        setRowHeight(i,500/(z.size()-1));
    }


    for(int i=0;i<z.size()-1;i++)
    {
        for(int j=0;j<z.size()-1;j++)
        {
            QTableWidgetItem *ptr=new QTableWidgetItem(1);
            QString str;
            str=str.number(z[i][j],10);
            (*ptr).setText(str);
            this->setItem(i,j,ptr);
        }
    }
    this->repaint();
}

void Zywnosc::wczytajdanesz(QVector<int> a)
{
    this->danez=a;
}

Zywnosc::Zywnosc(QWidget *parent) :
    QTableWidget(parent),reczniez(false)
{}


Algorytm::Algorytm() :
    QObject(), tablicad(),tablicaz(),poczatek()
{}

Algorytm::~Algorytm()
{
    tablicad.~QVector();
    tablicaz.~QVector();
    poczatek.~QVector();
    wynik.~QVector();
}

void Algorytm::rob()
{   /*if(~(this->poczatek.isEmpty()))
    this->poczatek.clear();
    this->krok=2;
    this->poczatek.append(1);
    this->poczatek.append(1);
    this->poczatek.append(2);
    this->poczatek.append(2);//test testow*/
    //this->K=10;
    //this->T=5;
    int k=0; //nr iteracji
    krasp=false;
    QVector<int> x,xTS;
    double Q=0; //fcelu
    double QTS=0;
    double QKLT=0;
    QVector<int> ruchwykonanyDLT(5),ruchwykonanyKLT(5);
    QVector<int> poprzednik;
    bool czywpisac=true;
    double eksport=0; //zmienna do eksportu dla plota

    QVector<int> xDLT,xKLT; // rozwiazania tymczasowe
    QVector< QVector<int> > odbior; //odbior danych od przeszukania obszaru

    if(~DLT.isEmpty())
    {
        for(int i=0;i<DLT.size();i++)
            DLT[i].clear();
        this->DLT.clear();
    }
    if(~KLT.isEmpty())
    {
        for(int i=0;i<KLT.size();i++)
            KLT[i].clear();
        this->KLT.clear();
    }

    iteracje=0;              //koniec zerowania

    QTS=this->fcelu(poczatek);
    x=poczatek;
    xTS=poczatek;

    QTime timer;
    timer.start();


    while(k<K)
    {
        poprzednik=x;
        odbior=this->maxot(x);
        xDLT=odbior[0];
        xKLT=odbior[1];

        x=xDLT;
        Q=this->fcelu(x);
        QKLT=this->fcelu(xKLT);

        if(Q>QTS)
        {
            xTS=x;
            QTS=Q;
        }

        if(QKLT>QTS)
        {
            x=xKLT;
            xTS=xKLT;
            QTS=QKLT;
            krasp=true;
        }

       /* for(int gh=0;gh<5;gh++)
        {
            ruchwykonanyDLT[gh]=0;
            ruchwykonanyKLT[gh]=0;
        }
*/

        for(int i=0;i<xDLT.size();i++)
        {
            if(xDLT[i]!=poprzednik[i] || xDLT[i+1]!=poprzednik[i+1])
            {
                ruchwykonanyDLT[0]=poprzednik[i];
                ruchwykonanyDLT[1]=poprzednik[i+1];
                ruchwykonanyDLT[2]=x[i];
                ruchwykonanyDLT[3]=x[i+1];
                ruchwykonanyDLT[4]=0;
            }

            if(xKLT[i]!=poprzednik[i] || xKLT[i+1]!=poprzednik[i+1])
            {
                ruchwykonanyKLT[0]=poprzednik[i];
                ruchwykonanyKLT[1]=poprzednik[i+1];
                ruchwykonanyKLT[2]=x[i];
                ruchwykonanyKLT[3]=x[i+1];
                ruchwykonanyKLT[4]=0;
            }
            i++;
        }

        for(int i=0;i<KLT.size();i++)
        {
            if(KLT[i][4]-1<=0)
                KLT[i][4]=0;
            else
                KLT[i][4]=KLT[i][4]-1;
        }

        czywpisac=true;

        if(krasp==false)
        {
            for(int i=0;i<KLT.size();i++)
            {
                if(KLT[i][0]==ruchwykonanyDLT[0] && KLT[i][1]==ruchwykonanyDLT[1] && KLT[i][2]==ruchwykonanyDLT[2] && KLT[i][3]==ruchwykonanyDLT[3])
                {
                    KLT[i][4]=T;
                    czywpisac=false;
                }
            }

            if(czywpisac==true)
            {
                ruchwykonanyDLT[4]=T;
                KLT.append(ruchwykonanyDLT);
            }
        }
        else
        {
            for(int i=0;i<KLT.size();i++)
            {
                if(KLT[i][0]==ruchwykonanyKLT[0] && KLT[i][1]==ruchwykonanyKLT[1] && KLT[i][2]==ruchwykonanyKLT[2] && KLT[i][3]==ruchwykonanyKLT[3])
                {
                    KLT[i][4]=T;
                    czywpisac=false;
                }
            }

            if(czywpisac==true)
            {
                ruchwykonanyKLT[4]=T;
                KLT.append(ruchwykonanyKLT);
            }
        }

        czywpisac=true;

        if(krasp==false)
        {
            for(int i=0;i<DLT.size();i++)
            {
                if(DLT[i][0]==ruchwykonanyDLT[0] && DLT[i][1]==ruchwykonanyDLT[1] && DLT[i][2]==ruchwykonanyDLT[2] && DLT[i][3]==ruchwykonanyDLT[3])
                {
                    DLT[i][4]=DLT[i][4]+1;
                    czywpisac=false;
                }
            }

            if(czywpisac==true)
            {
                ruchwykonanyDLT[4]=1;
                DLT.append(ruchwykonanyDLT);
            }
        }
        else
        {
            for(int i=0;i<DLT.size();i++)
            {
                if(DLT[i][0]==ruchwykonanyKLT[0] && DLT[i][1]==ruchwykonanyKLT[1] && DLT[i][2]==ruchwykonanyKLT[2] && DLT[i][3]==ruchwykonanyKLT[3])
                {
                    DLT[i][4]=DLT[i][4]+1;
                    czywpisac=false;
                }
            }

            if(czywpisac==true)
            {
                ruchwykonanyKLT[4]=1;
                DLT.append(ruchwykonanyKLT);
            }

            krasp=false;
        }

        eksport=this->fcelu(x); //potrzeby plota
        emit danarysuj(k,eksport);

        k++;
    }

    //    for(int i=0;i<xDLT.size();i++)   //test bardzo
      //  {

            /*
            if(xDLT[i]!=poczatek[i])
            {
                if(i%2==0)
                    this->xtest=xDLT[i];
                else
                    this->ytest=xDLT[i];
            }*/
        //}

        //this->xtest=xDLT[2];
       // this->ytest=xDLT[3];    //koniec testu bardzo

    this->czas=timer.elapsed();
    Q=/*this->fcelu(poczatek);*/this->fcelu(x);
    this->cel=Q;
    this->wynik=x;

    QFile plik1("DLT.txt");                                 //zapis do plikow tablic Taboo
    plik1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&plik1);
    QString ja;

    for(int i=0;i<DLT.size();i++)
    {
        ja.append(ja.number(DLT[i][0],10));
        ja.append(" ");
        ja.append(ja.number(DLT[i][1],10));
        ja.append(" ");
        ja.append(ja.number(DLT[i][2],10));
        ja.append(" ");
        ja.append(ja.number(DLT[i][3],10));
        ja.append(" ");
        ja.append(ja.number(DLT[i][4],10));
        ja.append("\n");
    }

    if(~ja.isEmpty())
        out<<ja;

    plik1.close();

    QFile plik2("KLT.txt");
    plik2.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out1(&plik2);
    QString ja1;

    for(int i=0;i<DLT.size();i++)
    {
        ja1.append(ja1.number(KLT[i][0],10));
        ja1.append(" ");
        ja1.append(ja1.number(KLT[i][1],10));
        ja1.append(" ");
        ja1.append(ja1.number(KLT[i][2],10));
        ja1.append(" ");
        ja1.append(ja1.number(KLT[i][3],10));
        ja1.append(" ");
        ja1.append(ja1.number(KLT[i][4],10));
        ja1.append("\n");
    }

    if(~ja1.isEmpty())
        out1<<ja1;

    plik2.close();

    QFile plik3("X.txt");
    plik3.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out2(&plik3);
    QString ja2;

    for(int i=0;i<x.size();i++)
    {
        ja2.append(ja2.number(x[i]));
        ja2.append(" ");
        ja2.append(ja2.number(x[i+1]));
        ja2.append("\n");

        i++;
    }

    ja2.append("\n");
    ja2.append("wartosc f celu:");
    ja2.append("\n");
    ja2.append(ja2.number(cel));

    if(~ja2.isEmpty())
        out2<<ja2;

    plik3.close();
}

void Algorytm::wypelnij(QVector<QVector<int> > d, QVector<QVector<int> > z, QVector<int> pocz, QVector<int> par)
{
    this->tablicad=d;
    this->tablicaz=z;
    //this->poczatek=pocz;
    this->alfa=par[0];
    this->K=par[1];
    this->T=par[2];
    this->lmiast=par[3];
    this->krok=par[4];

    //bool celestia=true;

   /* if(pocz.isEmpty())    //jesli nie podano recznie danych startowych to je wylosuj
    {
        if(~poczatek.isEmpty())
            poczatek.clear();

        for(int i=0;i<lmiast;i++)
        {
            celestia=true;

            while(celestia==true)
            {
                int tmpx,tmpy,a,b;
                a=tablicad.size();
                b=tablicad.size();
                bool chrysalis=true;

                tmpx=rand()%a;
                tmpy=rand()%b;

                for(int j=0;j<poczatek.size();j++)
                {
                    if(tmpx==poczatek[j] && tmpy==poczatek[j+1])
                        chrysalis=false;

                    j++;
                }

                if(chrysalis==true)
                {
                    poczatek.append(tmpx);
                    poczatek.append(tmpy);
                    celestia=false;
                }
            }
        }
    }
    else*/
        poczatek=pocz;
}

QVector<int> Algorytm::koniec()
{
    return this->wynik;
}

double Algorytm::zwroccel()
{
    return this->cel;
}

int Algorytm::zwrocczas()
{
    return this->czas;
}

QVector< QVector<int> > Algorytm::maxot(QVector<int> dana)
{
    QVector<int> temp,tempDLT;
    temp=dana;
    tempDLT=dana;
    QVector<int> xkandydat;
    QVector<int> xkandydatDLT;
    double QtempDLT=0,Qtemp=0;
    double QkandydatDLT=0,Qkandydat=0;
    int wartoscDLT=0;
    QVector< QVector<int> > zwroc;
    bool KLTtest=true;
    xkandydat=dana;
    xkandydatDLT=dana;

    QVector< QVector<int> > pomoc; //macierz posiadajaca 1 tam gdzie moge miasto, -1 gdzie brak zasiegu, 0 gdzie inne miasto, 5 gdzie aktualne miasto

   /* pomoc.resize(this->tablicad.size());

    for(int i=0;i<this->tablicad.size();i++)
    {
        pomoc[i].resize(this->tablicad.size());
    }*/

    pomoc.resize(2*krok+1);

    for(int i=0;i<2*krok+1;i++)
    {
        pomoc[i].resize(2*krok+1);
    }

    for(int itglowny=0;itglowny<dana.size();itglowny++)
    {
       /* for(int i=0;i<tablicad.size();i++)
        {
            for(int j=0;j<tablicad.size();j++)
            {
                pomoc[i][j]=(-1);
            }
        }*/
         for(int i=0;i<2*krok+1;i++)
         {
             for(int j=0;j<2*krok+1;j++)
             {
                 pomoc[i][j]=(-1);
             }
         }



        /*for(int i=(dana[itglowny]-krok);i<(dana[itglowny]+krok+1);i++){
            for(int j=(dana[itglowny+1]-krok);j<(dana[itglowny+1]+krok+1);j++)
            {
                for(int it1=0;it1<dana.size();it1++)
                {

                    if(dana[it1]==i && dana[it1+1]==j)
                    {
                        if(i==dana[itglowny] && j==dana[itglowny+1])
                            pomoc[i][j]=5;
                        else
                            pomoc[i][j]=0;
                    }
                    else
                    {
                        if(i<tablicad.size() && j<tablicad.size() && i>(-1) && j>(-1))
                           { if(pomoc[i][j]!=0 && pomoc[i][j]!=5)
                                pomoc[i][j]=1;}
                    }
                    it1++;
                }
            }
        }*/
         for(int i=0;i<2*krok+1;i++){
             for(int j=0;j<2*krok+1;j++)
             {
                 for(int it1=0;it1<dana.size();it1++)
                 {

                     if(dana[it1]==dana[itglowny]-krok+i && dana[it1+1]==dana[itglowny+1]-krok+j)
                     {
                         //if(i==dana[itglowny] && j==dana[itglowny+1])
                            // pomoc[i][j]=5;
                         //else
                             pomoc[i][j]=0;
                     }
                     else
                     {
                         if(dana[itglowny]-krok+i<tablicad.size() && dana[itglowny+1]-krok+j<tablicad.size() && dana[itglowny]-krok+i>(-1) && dana[itglowny+1]-krok+j>(-1))
                            { if(pomoc[i][j]!=0)
                                 pomoc[i][j]=1;}
                     }
                     it1++;
                 }
             }
         }

       /* for(int i=0;i<tablicad.size();i++){
            for(int j=0;j<tablicad.size();j++)
            {
                if(pomoc[i][j]==1)
                {
                   KLTtest=true;

                    for(int it2=0;it2<KLT.size();it2++)
                    {
                        if(KLT[it2][0]==dana[itglowny] && KLT[it2][1]==dana[itglowny+1])
                            if(KLT[it2][2]==i && KLT[it2][3]==j)
                                if(KLT[it2][4]!=0)
                                    KLTtest=false;
                    }

                   if(KLTtest==true)
                    {
                        QtempDLT=0;
                        tempDLT=dana;
                        tempDLT[itglowny]=i;
                        tempDLT[itglowny+1]=j;

                        QtempDLT=this->fcelu(tempDLT);

                        wartoscDLT=0;

                        for(int it2=0;it2<DLT.size();it2++)
                        {
                            if(DLT[it2][0]==dana[itglowny] && DLT[it2][1]==dana[itglowny+1])
                            {
                                if(DLT[it2][2]==i && DLT[it2][3]==j)
                                    wartoscDLT=DLT[it2][4];
                            }
                        }

                        if(wartoscDLT!=0)
                            QtempDLT=QtempDLT+(this->alfa/this->K)*wartoscDLT;

                        if(QtempDLT>QkandydatDLT)
                        {
                            xkandydatDLT=tempDLT;
                            QkandydatDLT=QtempDLT;
                        }
                    }
                    else
                    {
                        Qtemp=0;
                        temp=dana;
                        temp[itglowny]=i;
                        temp[itglowny+1]=j;

                        Qtemp=this->fcelu(temp);

                        if(Qtemp>Qkandydat)
                        {
                            xkandydat=temp;
                            Qkandydat=Qtemp;
                        }
                    }
                 }

        }}*/

         for(int i=0;i<2*krok+1;i++)
         {
             for(int j=0;j<2*krok+1;j++)
             {
                 if(pomoc[i][j]==1)
                 {
                     KLTtest=true;

                     for(int it2=0;it2<KLT.size();it2++)
                     {
                         if(KLT[it2][0]==dana[itglowny] && KLT[it2][1]==dana[itglowny+1])
                             if(KLT[it2][2]==dana[itglowny]-krok+i && KLT[it2][3]==dana[itglowny+1]-krok+j)
                                 if(KLT[it2][4]!=0)
                                     KLTtest=false;
                     }

                   if(KLTtest==true)
                     {
                         QtempDLT=0;
                         tempDLT=dana;
                         tempDLT[itglowny]=dana[itglowny]-krok+i;
                         tempDLT[itglowny+1]=dana[itglowny+1]-krok+j;

                         QtempDLT=this->fcelu(tempDLT);

                         wartoscDLT=0;

                         for(int it2=0;it2<DLT.size();it2++)
                         {
                             if(DLT[it2][0]==dana[itglowny] && DLT[it2][1]==dana[itglowny+1])
                             {
                                 if(DLT[it2][2]==dana[itglowny]-krok+i && DLT[it2][3]==dana[itglowny+1]-krok+j)
                                     wartoscDLT=DLT[it2][4];
                             }
                         }

                         if(wartoscDLT!=0)
                             QtempDLT=QtempDLT+(this->alfa/this->K)*wartoscDLT;

                         if(QtempDLT>QkandydatDLT)
                         {
                             xkandydatDLT=tempDLT;
                             QkandydatDLT=QtempDLT;
                         }
                     }
                     else
                     {
                         Qtemp=0;
                         temp=dana;
                         temp[itglowny]=dana[itglowny]-krok+i;
                         temp[itglowny+1]=dana[itglowny+1]-krok+j;

                         Qtemp=this->fcelu(temp);

                         if(Qtemp>Qkandydat)
                         {
                             xkandydat=temp;
                             Qkandydat=Qtemp;
                         }
                     }
                  }
             }
         }

       itglowny++;
    }

    zwroc.append(xkandydatDLT);
    zwroc.append(xkandydat);

    return zwroc;
}

int Algorytm::zwrocxtest()
{
    return this->xtest;
}

int Algorytm::zwrocytest()
{
    return this->ytest;
}

double Algorytm::fcelu(QVector<int> a)
{
    double tmp=0;
    double podsuma1=0; //dochod
    double podsuma2=0; //kara
    double podsuma3=0; //kara za bliskosc
    double sumka1=0; //pomoc przy karze
    double suma1=0; //pomoc przy karze

    if(a.isEmpty())
        return -1000;

    //suma dochodow

    for(int i=0;i<a.size();i++)
    {
        if(a[i]==0 && a[i+1]==0)
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]);
        else if(a[i]==0 && a[i+1]==(tablicad.size()-1))
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]-1]);
        else if(a[i]==(tablicad.size()-1) && a[i+1]==0)
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]);
        else if(a[i]==(tablicad.size()-1) && a[i+1]==(tablicad.size()-1))
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]-1]);
        else if(a[i]==0)
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]+(this->tablicad)[a[i]][a[i+1]-1]);
        else if(a[i]==(tablicad.size()-1))
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]+(this->tablicad)[a[i]][a[i+1]-1]);
        else if(a[i+1]==0)
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]);
        else if(a[i+1]==(tablicad.size()-1))
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]-1]);
        else
            podsuma1+=(this->tablicad)[a[i]][a[i+1]]+0.33333*((this->tablicad)[a[i]+1][a[i+1]]+(this->tablicad)[a[i]-1][a[i+1]]+(this->tablicad)[a[i]][a[i+1]+1]+(this->tablicad)[a[i]][a[i+1]-1]);

        i++;
    }

    for(int i=0;i<a.size();i++)
    {
        sumka1+=tablicaz[a[i]][a[i+1]];
        i++;
    }

    suma1=10*((a.size())/2-sumka1); //funkcja kary za zbyt mało żywności, dodatnia jak źle

    if(suma1>0)
        podsuma2=suma1;
    else
        podsuma2=0; //sprawdzenie czy brac pod uwage kare

    //ponizej mamy sprawdzanie odleglosci miast i obnizanie dochodow za zbytnia bliskosc:

    for(int i=0;i<a.size()-2;i++)
    {
        for(int j=i;j<a.size()-2;j++)
        {
            double odleglosc=0;

            odleglosc=sqrt((a[i]-a[j+2])*(a[i]-a[j+2])+(a[i+1]-a[j+3])*(a[i+1]-a[j+3]));

            if(odleglosc>1.9 && odleglosc<2.1)
                podsuma3+=1;
            if(odleglosc>0.9 && odleglosc<1.1)
                podsuma3+=3;
            if(odleglosc>1.3 && odleglosc<1.5)
                podsuma3+=2;

            j++;
        }

        i++;
    }

    tmp=podsuma1-podsuma2-podsuma3;

    return tmp;
}


void Rysuj::przysylka(int a, double b)
{
    emit wysylka(a,b);
}

void Rysuj::tworz()
{
    ptr=new Dialog2(this);
    ptr->show();

    connect(this,SIGNAL(wysylka(int,double)),this->ptr,SLOT(dane(int,double)));
    connect(this,SIGNAL(resetuj12()),this->ptr,SLOT(resetuj()));
}

void Rysuj::resetuj1()
{
    emit resetuj12();
}

Rysuj::Rysuj(QWidget *parent) :
    QPushButton(parent)
{}



Wczytaj::Wczytaj(QWidget *parent) :
    QPushButton(parent)
{}

void Wczytaj::czytajzpliku()
{
    QVector< QVector<int> > d;
    QVector< QVector<int> > z;
    QVector<int> b;
    QVector<int> c;

    QVector<int> pomoc;
    QVector<int> wpis;
    int skaler=1;
    int liczba=0;

    QFile plik("Dane.txt");
    plik.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&plik);
    QChar tu='a';

    int k=0,wiersz=0;
    bool w=false;

    while(tu!='\0')
    {
        in>>tu;

        if(tu=='\n')
        {

            if(w==true)
            {
                wiersz=0;
                k++;
                w=false;
            }
            else
            {
                switch(k){
                case 0:
                    d.append(pomoc);                        
                    skaler=1;
                    liczba=0;

                    for(int j=0;j<wpis.size();j++)
                    {
                        if(j!=0)
                            skaler=skaler*10;
                        liczba=liczba+(skaler*wpis[j]);
                    }

                    d[wiersz].append(liczba);
                    wpis.clear();
                    wiersz++;
                    break;
                case 1:
                    z.append(pomoc);                    
                    skaler=1;
                    liczba=0;

                    for(int j=0;j<wpis.size();j++)
                    {
                        if(j!=0)
                            skaler=skaler*10;
                        liczba=liczba+(skaler*wpis[j]);
                    }

                    z[wiersz].append(liczba);
                    wpis.clear();
                    wiersz++;
                    break;
                case 2:
                    skaler=1;
                    liczba=0;

                    for(int j=0;j<wpis.size();j++)
                    {
                        if(j!=0)
                            skaler=skaler*10;
                        liczba=liczba+(skaler*wpis[j]);
                    }
                    b.append(liczba);
                    wpis.clear();
                    break;
                case 3:
                    skaler=1;
                    liczba=0;

                    for(int j=0;j<wpis.size();j++)
                    {
                        if(j!=0)
                            skaler=skaler*10;
                        liczba=liczba+(skaler*wpis[j]);
                    }
                    c.append(liczba);
                    wpis.clear();
                    break;}

                w=true;
            }

        }

        if(tu!='\0' && tu!='\n' && tu!=' ')
        {
            switch(k){
            case 0:
                wpis.prepend(tu.toLatin1()-48);
                break;
            case 1:
                wpis.prepend(tu.toLatin1()-48);
                break;
            case 2:
                wpis.prepend(tu.toLatin1()-48);
                break;
            case 3:
                wpis.prepend(tu.toLatin1()-48);
                break;}

            w=false;
        }

        if(tu==' ')
        {
            switch(k){
            case 0:
                skaler=1;
                liczba=0;

                if(~wpis.isEmpty())
                    if(d.isEmpty())
                        d.append(pomoc);

                for(int j=0;j<wpis.size();j++)
                {
                    if(j!=0)
                        skaler=skaler*10;
                    liczba=liczba+(skaler*wpis[j]);
                }

                if(~wpis.isEmpty())
                    d[wiersz].append(liczba);
                wpis.clear();
                break;
            case 1:
                skaler=1;
                liczba=0;

                if(~wpis.isEmpty())
                    if(z.isEmpty())
                        z.append(pomoc);

                for(int j=0;j<wpis.size();j++)
                {
                    if(j!=0)
                        skaler=skaler*10;
                    liczba=liczba+(skaler*wpis[j]);
                }

                if(~wpis.isEmpty())
                    z[wiersz].append(liczba);
                wpis.clear();
                break;
            case 2:
                skaler=1;
                liczba=0;

                for(int j=0;j<wpis.size();j++)
                {
                    if(j!=0)
                        skaler=skaler*10;
                    liczba=liczba+(skaler*wpis[j]);
                }
                if(~wpis.isEmpty())
                    b.append(liczba);
                wpis.clear();
                break;
            case 3:
                skaler=1;
                liczba=0;

                for(int j=0;j<wpis.size();j++)
                {
                    if(j!=0)
                        skaler=skaler*10;
                    liczba=liczba+(skaler*wpis[j]);
                }
                if(~wpis.isEmpty())
                    c.append(liczba);
                wpis.clear();
                break;}

            w=false;

        }
    }

    skaler=1;
    liczba=0;

    for(int j=0;j<wpis.size();j++)
    {
        if(j!=0)
            skaler=skaler*10;
        liczba=liczba+(skaler*wpis[j]);
    }
    c.append(liczba);
    wpis.clear();

    plik.close();

   /* QVector<int> lol;
    QVector< QVector<int> > lollol;
    lol.append(1);
    lol.append(2);
    lollol.append(lol);
    lollol.append(lol);*/

    emit wczytajmacierz(d/*lollol*/,z);
    emit wczytajpocz(b);
    emit wczytajparam(c);
}
