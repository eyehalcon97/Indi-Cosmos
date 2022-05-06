#ifndef itemNUMERO_H
#define itemNUMERO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;

namespace Ui {
class itemnumero;
}

class itemnumero : public QWidget
{
    Q_OBJECT

public:
    explicit itemnumero(QWidget *parent = nullptr);
    ~itemnumero();
    itemnumero(string nombre,string etiqueta,string gui,string format,double min,double max,double step,double value,double target,QWidget *parent =nullptr);
    itemnumero(indigo_item item,QWidget *parent = nullptr);

private:
    Ui::itemnumero *ui;
    string name;
    string label;
    string hints;
    QWidget* padre;
    string format;
    double min;
    double max;
    double step;
    double value;
    double target;
};

#endif // itemNUMERO_H