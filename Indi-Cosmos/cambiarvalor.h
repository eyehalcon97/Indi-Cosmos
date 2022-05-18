#ifndef CAMBIARVALOR_H
#define CAMBIARVALOR_H

#include <QWidget>
#include "itemtexto.h"
#include "itemnumero.h"
#include "propiedad.h"

namespace Ui {
class CambiarValor;
}

class CambiarValor : public QWidget
{
    Q_OBJECT

public:
    explicit CambiarValor(QWidget *parent = nullptr);
    CambiarValor(itemtexto* item,int perm,propiedad *parent = nullptr);
    CambiarValor(itemnumero* item,int perm,propiedad *parent = nullptr);
    ~CambiarValor();

private slots:
    void on_boton_clicked();

private:
    Ui::CambiarValor *ui;
// general
    string name;
    string label;


//texto
    string valuetexto;

//double
    propiedad *padre;
    string format;
    int tipo;
    int perm;
    double min;
    double max;
    double step;
    double valuenumero;
    double target;



};

#endif // CAMBIARVALOR_H
