#ifndef INDIGOLIB_H
#define INDIGOLIB_H
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include "mainwindow.h"
#include <QObject>
#include <QThread>

class indigolib : public QObject
{
     Q_OBJECT
private:


    MainWindow *padre;
    int puerto;
    string host;
    string nombre;



signals:
void nuevapropiedad();

public:

static indigo_result client_detach(indigo_client *client);
static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message);
static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message);
static indigo_result client_attach(indigo_client *client);

indigolib();
indigo_property* getpropiedad(int id);
indigo_property** getpropiedades();
int getnpropiedades();

int getpuerto();
string gethost();
string getnombre();
void setpuerto(int port);
void sethost(string hosts);
void setnombre(string name);
void conectar(MainWindow *parent,string nombre,string host,int puerto);













};

#endif // INDIGOLIB_H
