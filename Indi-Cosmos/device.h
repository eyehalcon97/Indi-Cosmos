#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
#include "propiedad.h"
#include <QVBoxLayout>
#include <iostream>
#include <vector>
#include <QTreeWidget>


using namespace std;
namespace Ui {
class device;
}
/**
 *
 * @author eyehalcon97
 * Clase dispositivo que almacena las distintas propiedades
 */
class device : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 * @param id Nombre del dispositivo
 * @param cliente Cliente al que esta asociado el dispositivo
 *
 *
 */
    explicit device(string id,indigo_client *cliente, QWidget *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~device();
/**
 *
 * @brief Cambiar tamaño visual del dispositivo
 * @param altura altura deseada
 * @param anchura anchura deseada
 *
 *
 */
    void cambiartamanio(int altura,int anchura);
/**
 *
 * @brief Creamos una nueva propiedad del dispositivo
 * @param property propiedad a crear
 *
 *
 */
    void nuevapropiedad(indigo_property* property);
/**
 *
 * @brief Modificamos una propiedad del dispositivo de tipo blob
 * @param property propiedad a modificar
 * @param nameblob nombre del blob
 *
 */
    void cambiarpropiedad(indigo_property* property,string nameblob);
/**
 *
 * @brief Eliminamos una propiedad del dispositivo
 * @param property propiedad a eliminar
 *
 */
    void eliminarpropiedad(indigo_property* property);
/**
 *
 * @brief Modificamos una propiedad del dispositivo
 * @param property propiedad a modificar
 *
 */
    void cambiarpropiedad(indigo_property* property);
/**
 *
 * @brief devuelve la propiedad
 * @param num id de la propiedad que pedimos
 * @return propiedad
 */
    propiedad* getpropiedad(int num);
/**
 *
 * @brief devuelve el nombre del dispositivo
 * @return deviceid
 */
    string getDeviceID();
/**
 *
 * @brief devuelve el numero de propiedades del dispositivo
 * @return npropiedades
 *
 */
    int getnpropiedades();
/**
 *
 * @brief devuelve el layout de todas las propiedades
 * @return QVBoxLayout
 *
 */
    QVBoxLayout* mostrarpropiedades();
    indigo_client *cliente;
/**
 *
 * @brief devuelve si un objeto esta seleccionado
 * @param objeto nombre del objeto
 * @return devuevle true si esta seleccionado, false en caso contrario
 */
    bool estaseleccionado(string objeto);
/**
 *
 * @brief añade el nombre del ultimo nameblob
 * @param nameblob lista de nombres del nameblob
 *
 */
    void setlistanameblob(vector<string> nameblob);



    public slots:
/**
 *
 * @brief Se ejecuta al expandir un elemento del arbol de propiedades
 * @param objeto objeto que se ha expandido
 *
 */
    void expandir( QTreeWidgetItem *objeto);
/**
 *
 * @brief Se ejecuta al contraer un elemento del arbol de propiedades
 * @param objeto objeto que se ha contraido
 *
 */
    void disminuir( QTreeWidgetItem *objeto);
/**
 *
 * @brief Se ejecuta al cambiar la seleccion de un elemento del arbol de propiedades
 * @param objeto objeto que se ha seleccionado
 * @param numero posicion de la columna del objeto
 */
    void cambiarseleccion(QTreeWidgetItem *objeto,int numero);



private:
/**
 *
 * @brief devuelve la posicion de un string en la lista dada
 * @param lista lista en la que buscar
 * @param value valor que buscar en la lista
 * @return numero de la posicion 
 */
    int indexof(vector<string> lista,string value);
/**
 *
 * @brief comprueba si el objeto esta expandido
 * @param objeto nombre del objeto que comprobar
 * @return true si esta expandido, false en caso contrario
 */
    bool estaexpandido(string objeto);
    Ui::device *ui;
    string deviceid;
    vector<propiedad*> propiedades;


    QTreeWidget *arbol= new QTreeWidget;

    vector<string>grupos;
    vector<QTreeWidgetItem*> raices;
    vector<string> namesblob;
    vector<string> expandidos;
    string seleccionado = "-1";
    QScrollBar *nu ;
    int elements=0;




};

#endif // DEVICE_H
