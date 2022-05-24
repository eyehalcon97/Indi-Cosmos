#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <QWidget>
#include <string>
#include "itemblob.h"
#include "itemlight.h"
#include "itemnumero.h"
#include "itemswitch.h"
#include "itemtexto.h"
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTreeWidgetItem>





using namespace std;

namespace Ui {
class propiedad;
}
/**
 *
 * @author eyehalcon97
 * Clase propiedad almacena los datos de una propiedad
 */
class propiedad : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit propiedad(QWidget *parent = nullptr);
/**
*
* @brief Destructor por defecto
*/
    ~propiedad();
/**
 *
 * @brief Constructor con una propiedad
 * @param property propiedad
 * @param cliente cliente de la propiedad
 */
    propiedad(indigo_property *property,indigo_client *cliente,QWidget *parent = nullptr);
/**
 *
 * @brief Devuelve el nombre del item
 * @return nombre
 */
    string getname();
/**
 *
 * @brief Devuelve el grupo del item
 * @return group
 */
    string getgroup();
/**
 *
 * @brief Devuelve el Widget de la propiedad
 * @return QWidget
 */
    QWidget **mostrarpropiedades();
/**
 *
 * @brief Devuelve el numero de items
 * @return nitems
 */
    int getcount();
/**
 *
 * @brief Devuelve el tipo de propiedad
 * @return type
 */
    int gettype();
/**
 *
 * @brief Devuelve el layout de la propiedad
 * @return QVBoxLayout
 */
    QVBoxLayout *getlayout();
/**
 *
 * @brief Devuelve el state de la propiedad
 * @return numero
 */
    int getstate();
    vector<string> itemsname();
    vector<QWidget*> itemsWidgets();
/**
 *
 * @brief Devuelve el indice del item texto con el texto
 * @param id nombre del item que buscamos
 * @return numero
 */
    int buscartexto(string id);
/**
 *
 * @brief Devuelve el indice del item numero con el texto
 * @param id nombre del item que buscamos
 * @return numero
 */
    int buscarnumero(string id);
/**
 *
 * @brief Cambiar el valor del item texto
 * @param id nombre del item
 * @param valornuevo nuevo valor del texto
 */
    void cambiartexto(string nameitem,string valornuevo);
/**
 *
 * @brief Cambiar el valor del item numero
 * @param id nombre del item
 * @param valornuevo nuevo valor del numero
 */
    void cambiarnumero(string nameitem,double valornuevo);
/**
 *
 * @brief Cambiar el nombre del item blob
 * @param name nombre del blob
 */
    void setnameblob(string name);




private slots:
/**
 *
 * @brief Cambiar el nombre del item switch
 * @param index numero del item seleccionado
 */
    void combobox_cambio(int index);
/**
 *
 * @brief Muestra informacion sobre un item texto
 */
    void botontexto();
/**
 *
 * @brief Muestra informacion sobre un item numero
 */
    void botonnumero();
/**
 *
 * @brief Muestra informacion sobre un item blob
 */
    void botonblob();


private:
    Ui::propiedad *ui;

    string devicename;
    string name;
    string group;
    string label;
    string hints;
    int state;
    int type;
    int rule;
    indigo_token access_token;
    short version;
    bool hidden;
    int count;
    int perm;
    QWidget* padre;
    indigo_client *cliente;

    vector<itemblob*> itemsblob;
    vector<string> itemsblobname;
    vector<itemlight*> itemslight;
    vector<itemnumero*> itemsnumero;
    vector<itemswitch*> itemsswitch;
    vector<itemtexto*> itemstexto;
    vector<QWidget*>itemswidgets;












};

#endif // PROPIEDAD_H
