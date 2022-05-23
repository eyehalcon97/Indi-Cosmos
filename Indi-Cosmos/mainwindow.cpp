#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <string>
#include <QThread>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <ctime>
#include "indigolib.h"
#include <QTreeWidget>


#include <iostream>
#include <chrono>
#include <QThread>
#include "conectar.h"

conectar *menuconectar;




using namespace std;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)

{



    devicesseleccionados[1] = 0;

    ui->setupUi(this);
    ui->PanelDerecho->setVisible(false);


    //indigolib *lib = new indigolib(this);



}

MainWindow::~MainWindow()
{
/*
    for (int i=0;i<100 ;i++ ) {
        delete[] botones[i];
        delete[] devices[i];
    }*/
    delete[] devicesseleccionados;
    delete[] botones;
    delete[] devices;
    delete ui;
    workerThread->quit();

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

void MainWindow::resizeEvent(QResizeEvent* event)
{

    if(idbotones !=0){
        repintar();
    }

   // Your code here.
}

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

void MainWindow::creardevice(string id,indigo_client *cliente){
    idbotones++;
    int fila= (idbotones/columnasmaxima);
    int columna = idbotones%columnasmaxima;
    if(columna == 0){
        columna = columnasmaxima;
        fila--;
    }

    devices[idbotones] = new device(id,cliente);
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


 indigo_log("llego");

     layoutpropiedades = new QGridLayout;



    if ( ui->propiedades->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->propiedades->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete ui->propiedades->layout();
    }
 indigo_log("llego2");




    for(int i=1;i<=nseleccionados;i++){
 indigo_log("llego3");



        QWidget *deviceproperty = new QWidget;
        QVBoxLayout *layoutpropiedad = new QVBoxLayout;

        layoutpropiedad = devices[devicesseleccionados[i]]->mostrarpropiedades();
        deviceproperty->setLayout(layoutpropiedad);


        layoutpropiedades->addWidget(deviceproperty);



    }

 indigo_log("llego4");

    ui->propiedades->setLayout(layoutpropiedades);
     indigo_log("llego5");







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

int MainWindow::indexofdevice(string id){
    for(int i=1;i<=idbotones;i++){
        if(devices[i]->getDeviceID() == id){
            return i;
        }
    }

     return (-1);
}



void MainWindow::nuevodispositivo(){

   string nombre = menuconectar->getnombre();

   string host = menuconectar->gethost();
   int puerto =  menuconectar->getpuerto();
    if(!nombre.empty() && !host.empty()){
        menuconectar->hide();
        workerThread = new QThread;
        indigolib *libreria = new indigolib;
        libreria->moveToThread(workerThread);
        connect(this, &MainWindow::conectarlib, libreria, &indigolib::conectar);
        connect(libreria, &indigolib::nuevapropiedad, this, &MainWindow::nuevapropiedad);
        connect(libreria, &indigolib::cambiarpropiedadnameblob, this, &MainWindow::cambiarpropiedadnameblob);
        connect(libreria, &indigolib::eliminarpropiedad, this, &MainWindow::eliminarpropiedad);
        connect(libreria, &indigolib::cambiarpropiedad, this, &MainWindow::cambiarpropiedad);
        workerThread->start();

        conectarlib(nombre,host,puerto);

    }else{
        menuconectar->error();

    }



}


void MainWindow::cambiarpropiedad(indigo_property *propiedad){
    //indigo_log("señal de la libreria cambiar");

    //indigo_log(propiedad->device);

    string id = string(propiedad->device);

    int posicion =indexofdevice(id);
    //indigo_log(to_string(posicion).c_str());

    devices[posicion]->cambiarpropiedad(propiedad);

     MostrarPropiedades();


}

void MainWindow::eliminarpropiedad(indigo_property *propiedad){
    indigo_log("señal de la libreria eliminar");
    indigo_log(propiedad->device);

    string id = string(propiedad->device);

    int posicion =indexofdevice(id);
    indigo_log(to_string(posicion).c_str());
    if(posicion > 0 && posicion <=idbotones ){
        devices[posicion]->eliminarpropiedad(propiedad);
    }

    MostrarPropiedades();

}
void MainWindow::cambiarpropiedadnameblob(indigo_property *propiedad,indigo_client *cliente,string nameblob){
    //indigo_log("señal de la libreria nueva");
//indigo_log(propiedad->device);



    string id = string(propiedad->device);

    int posicion =indexofdevice(id);
    //indigo_log(to_string(posicion).c_str());

    devices[posicion]->cambiarpropiedad(propiedad,nameblob);

     MostrarPropiedades();

}

void MainWindow::nuevapropiedad(indigo_property *propiedad,indigo_client *cliente){
    //indigo_log("señal de la libreria nueva");
//indigo_log(propiedad->device);


    string id = string(propiedad->device);

        int posicion =indexofdevice(id);
        if(posicion > 0){
            devices[posicion]->nuevapropiedad(propiedad);
        }
        else{
            creardevice(id,cliente);
            devices[idbotones]->nuevapropiedad(propiedad);
        }
    MostrarPropiedades();

}


void MainWindow::on_pushButton_clicked()
{
    MostrarPropiedades();
}


void MainWindow::on_ButtonConectar_clicked()
{
    menuconectar = new conectar(this);
    menuconectar->setWindowTitle("Conectar");
    menuconectar->show();
//uevodispositivo();

}

