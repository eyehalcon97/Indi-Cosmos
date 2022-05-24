#ifndef itemBLOB_H
#define itemBLOB_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;

/**
 *
 * @author eyehalcon97
 * Clase itemblob almacena el item de tipo blob
 */
class itemblob : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit itemblob(QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~itemblob();
/**
 *
 * @brief Constructor con un item
 * @param item indigo item
 */
    itemblob(indigo_item item,QWidget *parent = nullptr);
/**
 *
 * @brief Insertar nombre del item blob
 * @param name nombre del item
 */
    void setname(string name);
/**
 *
 * @brief Devuelve el nombre del item blob
 * @return name
 */
    string getname();

private:
    string name;
    string label;
    string hints;
    QWidget* padre;
    string formato;
    string url;
    long size;
    void *value;
};

#endif // itemBLOB_H
