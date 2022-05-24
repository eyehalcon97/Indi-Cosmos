#include "indigolib.h"
#include <string>
#include <QThread>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <ctime>
#include "conectar.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <queue>
#include <string>
#include <time.h>

using namespace std;


#if defined(INDIGO_LINUX) || defined(INDIGO_MACOS)
#include <unistd.h>
#endif
#if defined(INDIGO_WINDOWS)
#include <windows.h>
#pragma warning(disable:4996)
#endif




queue<indigo_property*> propiedad;
queue<indigo_property*> propiedadeliminar;
queue<indigo_property*> propiedadcambiar;
queue<indigo_property*> propiedadblob;
queue<string> nameblob;

string tipofoto;


static indigo_result client_attach(indigo_client *client) {
    indigo_log("attached to INDIGO bus...");
    indigo_enumerate_properties(client, &INDIGO_ALL_PROPERTIES);



    return INDIGO_OK;
}

static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {

    if (string(property->name) == "CCD_IMAGE_FORMAT")  {
        for(int i=0;i<property->count;i++){
            if(property->items[i].sw.value){
            tipofoto = string(property->items[i].name);
            }
        }

    }

    if (!strcmp(property->name, CCD_IMAGE_PROPERTY_NAME)) {
        if (device->version >= INDIGO_VERSION_2_0)
            indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_URL);
        else
            indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_ALSO);
    }

            propiedad.push(property);



    return INDIGO_OK;
}

static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message)
{
    if (string(property->name) == "CCD_IMAGE_FORMAT")  {
        for(int i=0;i<property->count;i++){
            if(property->items[i].sw.value){
            tipofoto = string(property->items[i].name);
            }
        }

    }

    if (!strcmp(property->name, CCD_IMAGE_PROPERTY_NAME) && property->state == INDIGO_OK_STATE) {


        if (*property->items[0].blob.url && indigo_populate_http_blob_item(&property->items[0]))
            indigo_log("image URL received (%s, %d bytes)...", property->items[0].blob.url, property->items[0].blob.size);

        if (property->items[0].blob.value) {

            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];

            time (&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer,sizeof(buffer),"%d-%m-%Y %H-%M-%S",timeinfo);
            string fecha(buffer);



            string nombre= "images/img" + fecha  + "." + tipofoto;

            FILE *f = fopen(nombre.c_str(), "wb");
            fwrite(property->items[0].blob.value, property->items[0].blob.size, 1, f);
            fclose(f);
            indigo_log("image saved to %s...", nombre.c_str());

            nameblob.push(nombre);
            propiedadblob.push(property);


        }
    }else{

        propiedadcambiar.push(property);
    }



    return INDIGO_OK;

}


static	indigo_result client_delete_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message){
        indigo_property* propiedad = new indigo_property(*property);
        propiedadeliminar.push(propiedad);




        return INDIGO_OK;






}
static indigo_result client_detach(indigo_client *client) {
    indigo_log("detached from INDIGO bus...");
    return INDIGO_OK;
}


using namespace std;

static indigo_client client = {
        "Remote server client",
        false,
        NULL,
        INDIGO_OK,
        INDIGO_VERSION_CURRENT,
        NULL,
        client_attach,
        client_define_property,
        client_update_property,
        client_delete_property,
        NULL,
        client_detach
};






indigolib::indigolib(){

}


void indigolib::conectar(string name,string hosts,int port){
    host = hosts;
    nombre = name;
    puerto = port;
    indigo_set_log_level(INDIGO_LOG_DEBUG);
    indigo_start();
    indigo_server_entry *server;
    indigo_attach_client(&client);
    indigo_connect_server(nombre.c_str(), host.c_str() , puerto , &server);

    while(true){
        if(!propiedad.empty()){
            nuevapropiedad(propiedad.front(),&client);
            propiedad.pop();

        }
        if(!propiedadblob.empty()){
            cambiarpropiedadnameblob(propiedadblob.front(),&client,nameblob.front());
            nameblob.pop();
            propiedadblob.pop();

        }


        if(!propiedadcambiar.empty()){
            cambiarpropiedad(propiedadcambiar.front());
            propiedadcambiar.pop();

        }

        if(!propiedadeliminar.empty()){
            eliminarpropiedad(propiedadeliminar.front());
            propiedadeliminar.pop();


        }


    }


}


int indigolib::getpuerto(){
    return puerto;
}
string indigolib::gethost(){
    return host;
}
string indigolib::getnombre(){
    return nombre;
}
void indigolib::setpuerto(int port){
    puerto = port;
}
void indigolib::sethost(string hosts){
    host = hosts;
}
void indigolib::setnombre(string name){
    nombre = name;
}
