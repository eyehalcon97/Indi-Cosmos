#ifndef itemLIGHT_H
#define itemLIGHT_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;


/**
 *
 * @author eyehalcon97
 * Clase itemlight almacena el item de tipo itemlight
 */
class itemlight : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit itemlight(QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~itemlight();
/**
 *
 * @brief Constructor con un item
 * @param item indigo item
 */
    itemlight(indigo_item item,QWidget *parent = nullptr);
/**
 *
 * @brief Devuelve el valor del item
 * @return value
 */
    int getvalue();
private:
    string name;
    string label;
    string hints;
    QWidget* padre;
    int value;    ///< item value (for light properties)
};

#endif // itemLIGHT_H
