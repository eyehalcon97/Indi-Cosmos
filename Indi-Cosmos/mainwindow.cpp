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


#include <iostream>
#include <chrono>
#include <QThread>
#include "conectar.h"

conectar *menuconectar;
indigolib *libreria = new indigolib;



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

    for (int i=0;i<100 ;i++ ) {
        delete[] botones[i];
        delete[] devices[i];
    }
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

void MainWindow::creardevice(string id){
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



    QLabel *nombre = new QLabel;
    layoutpropiedades = new QGridLayout;
    QWidget *device = new QWidget;
    device->setStyleSheet("background-color:red");
    QLayout *layoutdevice = new QGridLayout;

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




    for(int i=1;i<=nseleccionados;i++){

        int npropiedades = devices[devicesseleccionados[i]]->getnpropiedades();

        nombre = new QLabel;
        nombre->setText("Nombre del Grupo");
        layoutpropiedades->addWidget(nombre);

        nombre = new QLabel;
        nombre->setText(devices[devicesseleccionados[i]]->getDeviceID().c_str());
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
            layoutpropiedades->addWidget(nombre);*/


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
/*
                nombre = new QLabel;
                nombre->setText(QString("GUI item propiedad"));
                layoutpropiedades->addWidget(nombre);

                nombre = new QLabel;
                nombre->setText(propiedad->items[k].hints);
                layoutpropiedades->addWidget(nombre);*/



                if(propiedad->type == 1){
                    nombre = new QLabel;
                    nombre->setText(QString("valor"));
                    layoutpropiedades->addWidget(nombre);
                    if(propiedad->items[k].text.length < INDIGO_VALUE_SIZE){
                        nombre = new QLabel;
                        nombre->setText(propiedad->items[k].text.value);
                        layoutpropiedades->addWidget(nombre);
                    }else{
                        nombre = new QLabel;
                        nombre->setText(propiedad->items[k].text.long_value);
                        layoutpropiedades->addWidget(nombre);
                    }



                }
                if(propiedad->type == 2){
                    nombre = new QLabel;
                    nombre->setText(QString("formato"));
                    layoutpropiedades->addWidget(nombre);

                    nombre = new QLabel;
                    nombre->setText(propiedad->items[k].number.format);
                    layoutpropiedades->addWidget(nombre);


                    nombre = new QLabel;
                    nombre->setText(QString("valor"));
                    layoutpropiedades->addWidget(nombre);

                    if(string(propiedad->items[k].number.format) == "%g"){
                        char texto[100];
                        sprintf(texto, "%g", propiedad->items[k].number.value);
                        indigo_log(texto);
                        nombre->setText(texto);
                    }else{
                        char textohora[2];
                        char texto[100];

                        sprintf(texto,    "%1-%2-%3T%4:%5:%6", propiedad->items[k].number.format);

                        indigo_log(texto);
                        nombre->setText(texto);
                    }




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
    device->setLayout(layoutpropiedades);

    layoutdevice->addWidget(device);
    ui->propiedades->setLayout(layoutdevice);


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

    workerThread = new QThread;
    libreria->moveToThread(workerThread);
    connect(libreria, &indigolib::nuevapropiedad, this, &MainWindow::nuevapropiedad);
    workerThread->start();

    string nombre = menuconectar->getnombre();
    string host = menuconectar->gethost();
    int puerto = menuconectar->getpuerto();
    if(!nombre.empty() && !host.empty() ){
        menuconectar->hide();
        libreria->conectar(this,nombre,host,puerto);

    }else{
        menuconectar->error();
    }


}

void MainWindow::nuevapropiedad(){
    indigo_log("señal de la libreria");

    contador++;

    indigo_property** propiedades = libreria->getpropiedades();
    string id = libreria->getnombre() + " - " + libreria->gethost() + " - " + to_string(libreria->getpuerto());
    int npropiedades = libreria->getnpropiedades();

    for(int i=1;i<npropiedades;i++){
        int posicion =indexofdevice(id);
        if(posicion > 0){
            devices[posicion]->nuevapropiedad(propiedades[i]);
        }
        else{
            creardevice(id);
            devices[idbotones]->nuevapropiedad(propiedades[i]);
        }

    }
}

void MainWindow::on_Conectar_clicked()
{

    menuconectar = new conectar(this);
    menuconectar->show();


}

