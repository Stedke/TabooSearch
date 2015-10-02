#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QString>
#include "dialog1.h"
#include "dialog2.h"
#include "math.h"
#include "QTime"
#include "QFile"
#include "QTextStream"
#include "qcustomplot.h"
#include "dialog3.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class Rysuj : public QPushButton
{
    Q_OBJECT

public slots:
    void przysylka(int a,double b);
    void tworz();
    void resetuj1();

signals:
    void wysylka(int a,double b);
    void resetuj12();

public:
    Rysuj(QWidget* parent);

private:
    Dialog2 *ptr;
};

class Wczytaj : public QPushButton
{
    Q_OBJECT

signals:
    void wczytajmacierz(QVector< QVector<int> > d,QVector< QVector<int> > z);
    void wczytajpocz(QVector<int> b);
    void wczytajparam(QVector<int> c); //wymiar,startowe,losujd,losujz,alfa,K,T,liczba miast,krok

public slots:
    void czytajzpliku();

public:
    Wczytaj(QWidget* parent);
};




class Algorytm : public QObject
{
    Q_OBJECT
signals:
    void danarysuj(int a,double b);

public:
    Algorytm();
    ~Algorytm();
    void rob(); // wlasciwy algorytm
    void wypelnij(QVector<QVector<int> > d,QVector<QVector<int> > z,QVector<int> pocz,QVector<int> par);//wypelnienie tablic klasy danymi z zewnatrz
    QVector<int> koniec(); //zwrocenie koncowych parametrow
    double zwroccel(); //zwrocenie wartosci fcelu
    int zwrocczas(); //zwrocenie czasu
    QVector< QVector<int> > maxot(QVector<int> dana); // znajdywanie max w sasiedztwie, 0 to xDLT,1 to x
    int zwrocxtest(); //zwrocenie testu dzialania przeszukania
    int zwrocytest();


    double fcelu(QVector<int> a); // do funkcji celu wyslac caly wektor aktualnych miast - problem z kara

private:
    QVector<QVector<int> > tablicad;
    QVector<QVector<int> > tablicaz;
    QVector<int> poczatek;  //wejsciowe parametry miast

    QVector<int> wynik; //koncowe parametry miast

    QVector< QVector<int> >KLT;  //listy taboo
    QVector< QVector<int> >DLT;

    int K;    //parametry Taboosearch;
    int alfa;
    int krok;
    int T;
    int lmiast;
    bool krasp;
    double cel;
    int iteracje;
    int czas; //czas pracy algorytmu
    int xtest; //test dzialania przeszukania
    int ytest;
};





class MyButton1 : public QPushButton
{
    Q_OBJECT

public slots:
    void uruchom1(QVector<QTableWidgetItem> d,QVector<int> s);
    void uruchom2(QVector<QTableWidgetItem> d);
    void ustalparam(QVector<int> p);
    void plota(int it,double cel);

signals:
    void juz();
    void zmianacelu(double ile); //sygnal do testow czy dziala cel
    void zmianaczasu(int ile); //zmiana czasu
    void zmianaxtest(int ile);//zmiany dla testow dzialania przeszukania
    void zmianaytest(int ile);
    void wyslijwynik(QVector<int> ile);
    void plotas(int a,double b);
    void resetuj();

public:
    MyButton1(QWidget* parent);

private:
    Algorytm alg;
    QVector<QTableWidgetItem> d1;
    QVector<QTableWidgetItem> d2;
    QVector<int> s1;
    QVector<int> param;
};

class MyButton2 : public QPushButton
{
    Q_OBJECT

public slots:
    void settings();
    void paczkeprzyjmij(QVector<int> d);
    void wczytajparam(QVector<int> p);

signals:
    void daned(QVector<int> d);
    void danez(QVector<int> d);
    void daneparam(QVector<int> d);

public:
    MyButton2(QWidget* parent);

private:
    Dialog1* ptr;
    QVector<int> pamiec;
};

class Dochod : public QTableWidget
{
    Q_OBJECT

public slots:
    void nowedaned(QVector<int> d);
    void startowed(int x,int y);
    void wyslijdaned();
    void wynikdoszedld(QVector<int> ile);
    void wczytajdanem(QVector< QVector<int> >d,QVector< QVector<int> >z);
    void wczytajdanes(QVector<int> a);

signals:
    void przeslijd(QVector<QTableWidgetItem> d,QVector<int> s);

public:
    Dochod(QWidget* parent);

private:
    bool recznied;//czy uzytkownik moze wprowadzac zmiany recznie
    QVector<int> daned;//wektor z poczatkowymi miastami przez uzytkownika
};

class Zywnosc : public QTableWidget
{
    Q_OBJECT

public slots:
    void nowedanez(QVector<int> d);
    void startowez(int x, int y);
    void wyslijdanez();
    void wynikdoszedl(QVector<int> ile);
    void wczytajdanemz(QVector< QVector<int> >d,QVector< QVector<int> >z);
    void wczytajdanesz(QVector<int> a);

signals:
    void przeslijz(QVector<QTableWidgetItem> d);

public:
    Zywnosc(QWidget* parent);

private:
    bool reczniez;
    QVector<int> danez;
};


#endif // MAINWINDOW_H

/*
 *przycisk MyButton1 ma po nacisnieciu walnac do slotow z maciery
 * i odebrac od nich (z sygnalow) dane poczatkowe i wektory z widgetItems
 *nastepnie ma wywolac klase algorytmu z otrzymanymi warunkami.
 *Algorytm przerabia dane w konstruktorze na tablice int na ktorych pracuje.
 *Wynik w postaci wspolrzednych miast zwraca do MyButton1 (bedzie polem tej klasy).
 *Teraz My button 1 wywola sygnalem sloty z macierzy,
 *ktore wyswietla wynik wstawiajac odpowiednie table widget items.
*/


