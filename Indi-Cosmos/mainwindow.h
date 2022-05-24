#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include "device.h"
#include<QThread>


#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 *
 * @author eyehalcon97
 * Clase MainWindow es la clase ventana Principal del programa
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    MainWindow(QWidget *parent = nullptr);
/**
*
* @brief Destructor por defecto
*/
    ~MainWindow();
/**
*
* @brief Crea un nuevo display de dispositivo
* @param id nombre del dispositivo
* @param cliente cliente del dispositivo
*/
    void creardevice(string id,indigo_client *cliente);
    QThread *workerThread;



public slots:
/**
*
* @brief Crea un nuevo dispositivo
*
*
*/
    void nuevodispositivo();
/**
*
* @brief Crea una nueva propiedad
* @param propiedad propiedad nueva
* @param cliente cliente del dispositivo
*/
    void nuevapropiedad(indigo_property *propiedad,indigo_client *cliente);
/**
*
* @brief Modifica una propiedad de tipo blob
* @param propiedad propiedad a modificar
* @param cliente cliente del dispositivo
* @param nameblob nombre del item blob
*/
    void cambiarpropiedadnameblob(indigo_property *propiedad,indigo_client *cliente,string nameblob);
/**
*
* @brief Elimina una propiedad
* @param propiedad propiedad a eliminar
*/
    void eliminarpropiedad(indigo_property *propiedad);
/**
*
* @brief Modifica una propiedad
* @param propiedad propiedad a modificar
*/
    void cambiarpropiedad(indigo_property *propiedad);
/**
*
* @brief Redibuja el panel derecho de la aplicacion
*/
    void MostrarPropiedades();


private slots:
/**
*
* @brief Redibuja el panel izquierdo de la aplicacion
*/
    void repintar();
/**
*
* @brief Se ejecuta cuando el panel derecho cambia
*/

    void on_boolpanelderecho_changed();
/**
*
* @brief Se ejecuta al salir el programa
*/
    void on_actionSalir_triggered();
/**
*
* @brief Se ejecuta cuando el panel superior cambia
*/
    void on_boolpanelsuperior_changed();

/**
*
* @brief Se ejecuta cuando se selecciona un dispositivo
*/
    void botones_clicked();
/**
*
* @brief Elimina la seleccion de dispositivos
*/
    void limpiar();
/**
*
* @brief Cambia entre el modo seleccion multiple y manual
*
*/
    void on_checkBox_stateChanged(int arg1);
/**
*
* @brief Se ejecuta cuando se sobredimensiona la aplicacion
*
*/
    void resizeEvent(QResizeEvent*);
/**
*
* @brief devuelve la posicion de id
* @return id
*/
    int indexofdevice(string id);
/**
*
* @brief muestra el menu de conectar
*
*/

    void on_ButtonConectar_clicked();

signals:
/**
*
* @brief funcion que envia señal a la libreria con los datos para conectarse con indigo
* @param nombre nombre del dispositivo
* @param host nombre del host del dispositivo
* @param puero numero del puerto
*/
    void conectarlib(string nombre,string host,int puerto);

private:
    Ui::MainWindow *ui;
    QPushButton **botones  = new QPushButton*[100];
    QGridLayout *layoutdevice = new QGridLayout;
    QGridLayout *layoutpropiedades;
    device **devices  = new device*[100];
    int *devicesseleccionados = new int[100];
    int nseleccionados=0;
    bool modoseleccion=false;
    int idbotones=0;
    int columnasmaxima =4;



};
#endif // MAINWINDOW_H

