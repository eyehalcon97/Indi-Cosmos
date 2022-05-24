#ifndef CAMBIARVALOR_H
#define CAMBIARVALOR_H

#include <QWidget>
#include "itemtexto.h"
#include "itemnumero.h"
#include "propiedad.h"

namespace Ui {
class CambiarValor;
}
/**
 *
 * @author eyehalcon97
 * Clase de elemento de nueva ventana en la que cambiamos el valor de un item
 */
class CambiarValor : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit CambiarValor(propiedad *parent = nullptr);
/**
 *
 * @brief Constructor con item de tipo texto
 * @param item elemento de tipo itemtexto  
 * @param perm indica el nivel de permisos de modificacion
 */
    CambiarValor(itemtexto* item,int perm,propiedad *parent = nullptr);
/**
 *
 * @brief Constructor con item de tipo numero
 * @param item elemento de tipo itemnumero  
 * @param perm indica el nivel de permisos de modificacion
 */
    CambiarValor(itemnumero* item,int perm,propiedad *parent = nullptr);
/**
 *
 * Destructor por defecto
 */
    ~CambiarValor();

private slots:
/**
 * @brief funcion que se ejecuta cuando pulsamos el boton Aceptar
 * 
 */
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
