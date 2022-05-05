#ifndef INDIGOLIB_H
#define INDIGOLIB_H
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include "mainwindow.h"


class indigolib
{
private:

    MainWindow *padre;
    int puerto;
    string host;
    string nombre;
public:

static indigo_result client_detach(indigo_client *client);
static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message);
static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
static indigo_result client_attach(indigo_client *client);




void setpropiedad(indigo_property* propiedad);
indigo_property* getpropiedad(int id);
indigo_property** getpropiedades();
int getnpropiedades();
void setpadre(MainWindow *parent);
int getpuerto();
string gethost();
string getnombre();
void setpuerto(int port);
void sethost(string hosts);
void setnombre(string name);
void conectar(MainWindow *parent,string nombre,string host,int puerto);




    indigolib();

};

#endif // INDIGOLIB_H
