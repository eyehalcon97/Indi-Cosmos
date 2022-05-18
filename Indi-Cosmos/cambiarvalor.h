#ifndef CAMBIARVALOR_H
#define CAMBIARVALOR_H

#include <QWidget>
#include "itemtexto.h"
#include "itemnumero.h"

namespace Ui {
class CambiarValor;
}

class CambiarValor : public QWidget
{
    Q_OBJECT

public:
    explicit CambiarValor(QWidget *parent = nullptr);
    CambiarValor(itemtexto* item,int perm,QWidget *parent = nullptr);
    CambiarValor(itemnumero* item,int perm,QWidget *parent = nullptr);
    ~CambiarValor();

private:
    Ui::CambiarValor *ui;
// general
    string name;
    string label;


//texto
    string valuetexto;

//double

    string format;
    int perm;
    double min;
    double max;
    double step;
    double valuenumero;
    double target;



};

#endif // CAMBIARVALOR_H
