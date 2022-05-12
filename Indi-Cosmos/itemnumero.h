#ifndef itemNUMERO_H
#define itemNUMERO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;



class itemnumero : public QWidget
{
    Q_OBJECT

public:
    explicit itemnumero(QWidget *parent = nullptr);
    ~itemnumero();
    itemnumero(string nombre,string etiqueta,string gui,string format,double min,double max,double step,double value,double target,QWidget *parent =nullptr);
    itemnumero(indigo_item item,int perm,QWidget *parent = nullptr);
    string getname();
    string getlabel();
    double getvalue();

private:

    string name;
    string label;
    string hints;
    QWidget* padre;
    string format;
    int perm;
    double min;
    double max;
    double step;
    double value;
    double target;
};

#endif // itemNUMERO_H
