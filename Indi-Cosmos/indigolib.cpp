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



#if defined(INDIGO_LINUX) || defined(INDIGO_MACOS)
#include <unistd.h>
#endif
#if defined(INDIGO_WINDOWS)
#include <windows.h>
#pragma warning(disable:4996)
#endif



bool utilizado=false;
bool utilizadocambiar=false;
bool utilizadoborrar=false;
indigo_property* propiedad;
indigo_property* propiedadeliminar;
indigo_property* propiedadcambiar;


static indigo_result client_attach(indigo_client *client) {
    indigo_log("attached to INDIGO bus...");
    indigo_enumerate_properties(client, &INDIGO_ALL_PROPERTIES);



    return INDIGO_OK;
}

static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {


        while(utilizado==false){
            propiedad=property;
            utilizado=true;
        }





        //indigo_log(property->items[0].number.value);
    /*else
        mipropiedad = property;
    }

    if(!strcmp(property->name,CCD_EXPOSURE_PROPERTY_NAME)){

    }
    if (!strcmp(property->name, CONNECTION_PROPERTY_NAME)) {
        if (indigo_get_switch(property, CONNECTION_CONNECTED_ITEM_NAME)) {
            connected = true;
            indigo_log("already connected...");
            static const char * items[] = { CCD_EXPOSURE_ITEM_NAME };
            static double values[] = { 3.0 };
            indigo_change_number_property(client, CCD_SIMULATOR, CCD_EXPOSURE_PROPERTY_NAME, 1, items, values);

        } else {
            indigo_device_connect(client, CCD_SIMULATOR);
            return INDIGO_OK;
        }
    }
    if (!strcmp(property->name, "FILE_NAME")) {
        char value[1024] = { 0 };
        static const char * items[] = { "PATH" };
        static const char *values[1];
        values[0] = value;
        for (int i = 0 ; i < 1023; i++)
            value[i] = '0' + i % 10;
        indigo_change_text_property(client, CCD_SIMULATOR, "FILE_NAME" , 1, items, values);
    }
    if (!strcmp(property->name, CCD_IMAGE_PROPERTY_NAME)) {
        if (device->version >= INDIGO_VERSION_2_0)
            indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_URL);
        else
            indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_ALSO);
    }
    if (!strcmp(property->name, CCD_IMAGE_FORMAT_PROPERTY_NAME)) {
        static const char * items[] = { CCD_IMAGE_FORMAT_FITS_ITEM_NAME };
        static bool values[] = { true };
        indigo_change_switch_property(client, CCD_SIMULATOR, CCD_IMAGE_FORMAT_PROPERTY_NAME, 1, items, values);
    }*/
    return INDIGO_OK;
}

static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message)
{


    while(utilizadocambiar==false){
        propiedadcambiar=property;
        utilizadocambiar=true;

    }

/*
    if(property == mipropiedad){
        cout << "ES LA MISMA" << endl;
    }
    cout << "xxx" <<  mipropiedad->name << endl;
    if (!strcmp(property->name, CCD_EXPOSURE_PROPERTY_NAME)) {
        if (property->state == INDIGO_BUSY_STATE) {

            indigo_log("exposure %gs...", property->items[0].number.value);
        } else if (property->state == INDIGO_OK_STATE) {
            indigo_log("exposure done...");
        }
        return INDIGO_OK;
    }*/
    return INDIGO_OK;

}


static	indigo_result client_delete_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message){

    while(utilizadoborrar==false){
        propiedadeliminar=property;
        utilizadoborrar=true;
    }

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
        if(utilizado){
            nuevapropiedad(propiedad,&client);
            utilizado=false;
        }

        if(utilizadocambiar){
            cambiarpropiedad(propiedadcambiar);
            utilizadocambiar=false;
        }

        if(utilizadoborrar){
            indigo_log("borrar");
            indigo_log(propiedadeliminar->device);
            eliminarpropiedad(propiedadeliminar);
            utilizadoborrar=false;

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
