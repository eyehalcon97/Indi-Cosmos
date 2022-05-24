#ifndef itemTEXTO_H
#define itemTEXTO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;


/**
 *
 * @author eyehalcon97
 * Clase itemtexto  almacena el item de tipo itemtexto 
 */
class itemtexto : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit itemtexto(QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~itemtexto();
/**
 *
 * @brief Constructor con un item
 * @param item indigo item
 */
    itemtexto(indigo_item item,QWidget *parent );
/**
 *
 * @brief Devuelve el nombre del item
 * @return nombre
 */
    string getname();
/**
 *
 * @brief Devuelve el nombre de la etiqueta del item
 * @return label
 */
    string getlabel();
/**
 *
 * @brief Devuelve el valor del item
 * @return value
 */
    string getvalue();



private:

    string name;
    string label;
    string hints;
    QWidget* padre;
    string value;  ///< item value (for text properties)
    QWidget widget;
};

#endif // itemTEXTO_H
