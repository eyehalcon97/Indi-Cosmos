#ifndef INDIGOLIB_H
#define INDIGOLIB_H
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>


#include <QObject>
#include <QThread>

using namespace std;
/**
 *
 * @author eyehalcon97
 * Clase que utiliza la libreria de indigo
 */
class indigolib : public QObject
{
     Q_OBJECT
private:


    int puerto;
    string host;
    string nombre;



signals:
/**
 *
 * @brief funcion que llama a la ventana principal con una propiedad nueva
 * @param propiedad propiedad nueva
 * @param cliente cliente de la propiedad
 *
 */
void nuevapropiedad(indigo_property *propiedad,indigo_client *cliente);
/**
 *
 * @brief funcion que llama a la ventana principal para modificar una propiedad con nombre nameblob
 * @param propiedad propiedad a modificar
 * @param cliente cliente de la propiedad
 * @param nameblob nombre de la propiedad nameblob
 */
void cambiarpropiedadnameblob(indigo_property *propiedad,indigo_client *cliente,string nameblob);
/**
 *
 * @brief funcion que llama a la ventana principal con una propiedad a eliminar
 * @param propiedad propiedad a eliminar
 *
 */
void eliminarpropiedad(indigo_property *propiedad);
/**
 *
 * @brief funcion que llama a la ventana principal para modificar una propiedad
 * @param propiedad propiedad a modificar
 *
 */
void cambiarpropiedad(indigo_property *propiedad);

public:
/**
 *
 * @brief funcion que se llama al desconectar la libreria indigo
 * @param client cliente de indigo
 *
 */
static indigo_result client_detach(indigo_client *client);
/**
 *
 * @brief funcion que se llama al llegar una propiedad a actualizar
 * @param client cliente de indigo
 * @param device dispositivo de indigo
 * @param property propiedad a actualizar
 * @param message mensaje del servidor
 */
static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message);
/**
 *
 * @brief funcion que se llama al llegar una nueva propiedad
 * @param client cliente de indigo
 * @param device dispositivo de indigo
 * @param property propiedad nueva
 * @param message mensaje del servidor
 */
static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
/**
 *
 * @brief funcion que se llama al llegar una propiedad a eliminar
 * @param client cliente de indigo
 * @param device dispositivo de indigo
 * @param property propiedad a eliminar
 * @param message mensaje del servidor
 */
static indigo_result client_delete_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
/**
 *
 * @brief funcion que se llama al conectar la libreria indigo
 * @param client cliente de indigo
 *
 */
static indigo_result client_attach(indigo_client *client);

indigolib();

/**
 *
 * @brief devuelve el numero de puerto
 * @return puerto
 *
 */
int getpuerto();
/**
 *
 * @brief devuelve el nombre de host
 * @return host
 *
 */
string gethost();
/**
 *
 * @brief devuelve el nombre del dispositivo
 * @return nombre
 *
 */
string getnombre();
void setpuerto(int port);
void sethost(string hosts);
void setnombre(string name);
/**
 *
 * @brief funcion que inicializa y escucha la libreria indigo
 * @param nombre nombre del dispositivo
 * @param host nombre del host
 * @param puerto numero de puerto
 *
 */
void conectar(string nombre,string host,int puerto);






};

#endif // INDIGOLIB_H
