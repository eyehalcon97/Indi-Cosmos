#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <string>
#include <QThread>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>



#include <iostream>
#include <chrono>
#include <thread>



#if defined(INDIGO_LINUX) || defined(INDIGO_MACOS)
#include <unistd.h>
#endif
#if defined(INDIGO_WINDOWS)
#include <windows.h>
#pragma warning(disable:4996)
#endif
indigo_property *lista_propiedades[100];
int npropiedades=0;
bool cargado=false;


static bool connected = false;
static int count = 5;
using namespace std;


string CCD_SIMULATOR = "CCD Imager Simulator @ localhost";



static indigo_result client_attach(indigo_client *client) {
    indigo_log("attached to INDIGO bus...");
    indigo_enumerate_properties(client, &INDIGO_ALL_PROPERTIES);


    return INDIGO_OK;
}

static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {

        lista_propiedades[npropiedades] = property;
        npropiedades++;

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
static indigo_result client_detach(indigo_client *client) {
    indigo_log("detached from INDIGO bus...");
    return INDIGO_OK;
}

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
    NULL,
    NULL,
    client_detach
};

using namespace std;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)

{




    devicesseleccionados[1] = 0;

    ui->setupUi(this);
    ui->PanelDerecho->setVisible(false);



}

MainWindow::~MainWindow()
{

    for (int i=0;i<100 ;i++ ) {
        delete[] botones[i];
        delete[] devices[i];
    }
    delete[] devicesseleccionados;
    delete[] botones;
    delete[] devices;
    delete ui;

}
void MainWindow::on_boolpanelderecho_changed()
{
    if(ui->boolpanelderecho->isChecked()){
        ui->PanelDerecho->setVisible(true);
    }
    else{
        ui->PanelDerecho->setVisible(false);
    }
    repintar();

}


void MainWindow::on_actionSalir_triggered()
{

    qApp->quit();
}



void MainWindow::on_boolpanelsuperior_changed()
{
    if(ui->boolpanelsuperior->isChecked()){
        ui->PanelSuperior->setVisible(true);
    }
    else{
        ui->PanelSuperior->setVisible(false);

    }
    repintar();
}


void MainWindow::on_Nobjetos_valueChanged(int arg1)
{



}
/*
void MainWindow::resizeEvent(QResizeEvent* event)
{

    if(idbotones !=0){
        repintar();
    }

   // Your code here.
}*/

void MainWindow::repintar(){
    int fila= (idbotones/columnasmaxima);
    int columna = idbotones%columnasmaxima;
    if(columna == 0){
        columna = columnasmaxima;
        fila--;
    }

    if(idbotones < 5){
        for(int i=1;i<=idbotones;i++){
            devices[i]->cambiartamanio(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMaximumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMinimumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->resize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
        }
    }else{
        for(int i=1;i<=idbotones;i++){
        devices[i]->cambiartamanio(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->setMaximumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->setMinimumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->resize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
    }
    }
    if(idbotones != 0){
        layoutdevice->addWidget(devices[idbotones],fila,columna);
        layoutdevice->addWidget(botones[idbotones],fila,columna);
    }

    ui->PanelPrincipal->widget()->setLayout(layoutdevice);
}

void MainWindow::creardevice(char* id){
    idbotones++;
    int fila= (idbotones/columnasmaxima);
    int columna = idbotones%columnasmaxima;
    if(columna == 0){
        columna = columnasmaxima;
        fila--;
    }

    devices[idbotones] = new device(this,id);
    botones[idbotones] = new QPushButton();
    botones[idbotones]->setObjectName(QString::number(idbotones));
    connect(botones[idbotones], SIGNAL (clicked()),this, SLOT (botones_clicked()));

    if(idbotones < 5){
        for(int i=1;i<=idbotones;i++){
            devices[i]->cambiartamanio(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMaximumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMinimumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->resize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
        }
    }else{
        devices[idbotones]->cambiartamanio(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->setMaximumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->setMinimumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->resize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
    }

    layoutdevice->addWidget(devices[idbotones],fila,columna);
    layoutdevice->addWidget(botones[idbotones],fila,columna);


    ui->PanelPrincipal->widget()->setLayout(layoutdevice);

}





void MainWindow::botones_clicked()
{


    if(modoseleccion){
        nseleccionados++;
        devicesseleccionados[nseleccionados] = sender()->objectName().toInt();
        botones[sender()->objectName().toInt()]->hide();
    }

    else{
    nseleccionados=1;
    if(devicesseleccionados[nseleccionados] != 0){
        botones[devicesseleccionados[nseleccionados]]->setVisible(true);
    }
     devicesseleccionados[nseleccionados]=sender()->objectName().toInt();
     botones[sender()->objectName().toInt()]->hide();
    }


    MostrarPropiedades();

    ui->PanelDerecho->setVisible(true);
    ui->boolpanelderecho->setChecked(true);
    repintar();
}

void MainWindow::MostrarPropiedades(){


    QLabel *nombre;
    layoutpropiedades = new QGridLayout;

    for(int i=1;i<=nseleccionados;i++){
        char texto[100];
        sprintf(texto, "%d", devicesseleccionados[i]);
        indigo_log(texto);
        int npropiedades = devices[devicesseleccionados[i]]->getnpropiedades();
        nombre = new QLabel;
        nombre->setText("Nombre del dispositivo");
        layoutpropiedades->addWidget(nombre);
        nombre = new QLabel;
        nombre->setText(devices[devicesseleccionados[i]]->getDeviceID());
        indigo_log(devices[devicesseleccionados[i]]->getDeviceID());
        layoutpropiedades->addWidget(nombre);
        for(int j=1;j<=npropiedades;j++){
            indigo_property* propiedad = devices[devicesseleccionados[i]]->getpropiedad(j);
            nombre = new QLabel;
            nombre->setText("Nombre de la propiedad");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->name);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("Nombre del grupo");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->group);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("descripcion");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->label);
            layoutpropiedades->addWidget(nombre);
            /*
            nombre = new QLabel;
            nombre->setText("GUI");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(QString(propiedad->hints));
            layoutpropiedades->addWidget(nombre);
            */

            nombre = new QLabel;
            nombre->setText(QString("valor luz"));
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            if(propiedad->state == 0){
                nombre->setText("INDIGO_IDLE_STATE");
            }
            if(propiedad->state == 1){
                nombre->setText("INDIGO_OK_STATE");
            }
            if(propiedad->state == 2){
                nombre->setText("INDIGO_BUSY_STATE");
            }
            if(propiedad->state == 3){
               nombre->setText("INDIGO_ALERT_STATE");
            }
            layoutpropiedades->addWidget(nombre);


            for(int k=0;k<propiedad->count;k++){
                nombre = new QLabel;
                nombre->setText(QString("nombre del item de la propiedad"));
                layoutpropiedades->addWidget(nombre);

                nombre = new QLabel;
                nombre->setText(propiedad->items[k].name);
                layoutpropiedades->addWidget(nombre);

                nombre = new QLabel;
                nombre->setText(QString("descripcion del item de la propiedad"));
                layoutpropiedades->addWidget(nombre);

                nombre = new QLabel;
                nombre->setText(propiedad->items[k].label);
                layoutpropiedades->addWidget(nombre);

               /* nombre = new QLabel;
                nombre->setText(QString("GUI item propiedad"));
                layoutpropiedades->addWidget(nombre);

                nombre = new QLabel;
                nombre->setText(propiedad->items[k].hints);
                layoutpropiedades->addWidget(nombre);
                */


                if(propiedad->type == 1){
                    nombre = new QLabel;
                    nombre->setText(QString("valor"));
                    layoutpropiedades->addWidget(nombre);

                    nombre = new QLabel;
                    nombre->setText(propiedad->items[k].text.value);
                    layoutpropiedades->addWidget(nombre);
                }
                if(propiedad->type == 2){
                    nombre = new QLabel;
                    nombre->setText(QString("valor"));
                    layoutpropiedades->addWidget(nombre);

                    nombre = new QLabel;
                    char texto[100];
                    sprintf(texto, "%f", propiedad->items[k].number.value);
                    nombre->setText(texto);
                    layoutpropiedades->addWidget(nombre);

                }
                if(propiedad->type == 3){
                    nombre = new QLabel;
                    nombre->setText(QString("valor Switch"));
                    layoutpropiedades->addWidget(nombre);

                    nombre = new QLabel;
                    if(propiedad->items[k].sw.value){
                    nombre->setText("TRUE");
                    }else{
                     nombre->setText("FALSE");
                    }
                    layoutpropiedades->addWidget(nombre);
                }
                if(propiedad->type == 4){
                    //propiedad->items[k].light.value
                    nombre = new QLabel;
                    nombre->setText(QString("valor luz"));
                    layoutpropiedades->addWidget(nombre);

                    nombre = new QLabel;
                    if(propiedad->items[k].light.value == 0){
                        nombre->setText("INDIGO_IDLE_STATE");
                    }
                    if(propiedad->items[k].light.value == 1){
                        nombre->setText("INDIGO_OK_STATE");
                    }
                    if(propiedad->items[k].light.value == 2){
                        nombre->setText("INDIGO_BUSY_STATE");
                    }
                    if(propiedad->items[k].light.value == 3){
                       nombre->setText("INDIGO_ALERT_STATE");
                    }
                    layoutpropiedades->addWidget(nombre);
                }
                if(propiedad->type == 5){

                }
            }
        }
    }

    ui->propiedades->setLayout(layoutpropiedades);
    ui->propiedades->update();

}

void MainWindow::limpiar(){
    for(int i=1;i<nseleccionados+1;i++){
        botones[devicesseleccionados[i]]->setVisible(true);
        devicesseleccionados[i] = 0;

    }
    nseleccionados=0;
}




void MainWindow::on_checkBox_stateChanged(int arg1)
{
    limpiar();
    if(arg1 == 0){
        modoseleccion= false;
    }else{
        modoseleccion=true;
    }
}

int MainWindow::indexofdevice(char* id){
    for(int i=1;i<=idbotones;i++){
        if((string)devices[i]->getDeviceID() == (string)id){
            return i;
        }
    }

     return (-1);
}





void MainWindow::on_Conectar_clicked()
{
    indigo_set_log_level(INDIGO_LOG_DEBUG);
     indigo_start();
     indigo_server_entry *server;
     indigo_attach_client(&client);
     indigo_connect_server("localhost", "localhost", 7624, &server);
     QThread::sleep(1);

     for(int i=0;i<npropiedades;i++){
         int posicion =indexofdevice(lista_propiedades[i]->device);
         if(posicion > 0){
             devices[posicion]->nuevapropiedad(lista_propiedades[i]);

         }
         else{
             creardevice(lista_propiedades[i]->device);
             devices[idbotones]->nuevapropiedad(lista_propiedades[i]);
         }

     }

}

