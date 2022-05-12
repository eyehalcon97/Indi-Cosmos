#ifndef INDIGOLIB_H
#define INDIGOLIB_H
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>


#include <QObject>
#include <QThread>

using namespace std;

class indigolib : public QObject
{
     Q_OBJECT
private:


    int puerto;
    string host;
    string nombre;



signals:
void nuevapropiedad(indigo_property *propiedad,indigo_client *cliente);
void eliminarpropiedad(indigo_property *propiedad);
void cambiarpropiedad(indigo_property *propiedad);

public:

static indigo_result client_detach(indigo_client *client);
static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message);
static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
static indigo_result client_delete_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
static indigo_result client_attach(indigo_client *client);

indigolib();


int getpuerto();
string gethost();
string getnombre();
void setpuerto(int port);
void sethost(string hosts);
void setnombre(string name);
void conectar(string nombre,string host,int puerto);






};

#endif // INDIGOLIB_H
