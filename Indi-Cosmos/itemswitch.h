#ifndef itemSWITCH_H
#define itemSWITCH_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;


/**
 *
 * @author eyehalcon97
 * Clase itemswitch almacena el item de tipo itemswitch
 */
class itemswitch : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit itemswitch(QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~itemswitch();
/**
 *
 * @brief Constructor con un item
 * @param item indigo item
 */
    itemswitch(indigo_item item,QWidget *parent = nullptr);
/**
 *
 * @brief Devuelve el nombre del item
 * @return name
 */
    string getname();
/**
 *
 * @brief Devuelve el valor del item
 * @return value
 */
    bool getvalue();

private:

    string name;
    string label;
    string hints;
    QWidget* padre;
    bool value;
};

#endif // itemSWITCH_H
