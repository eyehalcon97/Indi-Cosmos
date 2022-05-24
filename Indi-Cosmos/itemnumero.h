#ifndef itemNUMERO_H
#define itemNUMERO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;


/**
 *
 * @author eyehalcon97
 * Clase itemnumero almacena el item de tipo itemnumero
 */
class itemnumero : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit itemnumero(QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~itemnumero();
/**
 *
 * @brief Constructor con un item
 * @param item indigo item
 */
    itemnumero(indigo_item item,int perm,QWidget *parent = nullptr);
/**
 *
 * @brief Devuelve el nombre del item
 * @return name
 */
    string getname();
/**
 *
 * @brief Devuelve el label del item
 * @return label
 */
    string getlabel();
/**
 *
 * @brief Devuelve el valor del item
 * @return value
 */
    double getvalue();
/**
 *
 * @brief Devuelve el formato del item
 * @return format
 */
    string getformat();
/**
 *
 * @brief Devuelve el valor minimo del item
 * @return min
 */
    double getmin();
/**
 *
 * @brief Devuelve el valor maximo del item
 * @return max
 */
    double getmax();
/**
 *
 * @brief Devuelve el valor de step del item
 * @return step
 */
    double getstep();
/**
 *
 * @brief Devuelve el valor objetivo del item
 * @return target
 */
    double gettarget();

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
