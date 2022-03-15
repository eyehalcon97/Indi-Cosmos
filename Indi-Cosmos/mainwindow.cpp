#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <iostream>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)

{
    telescopiosseleccionados[1] = 0;

    ui->setupUi(this);
    ui->PanelDerecho->setVisible(false);
}

MainWindow::~MainWindow()
{

    for (int i=0;i<100 ;i++ ) {
        delete[] botones[i];
        delete[] telescopios[i];
    }
    delete[] telescopiosseleccionados;
    delete[] botones;
    delete[] telescopios;
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
            telescopios[i]->cambiartamanio(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMaximumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMinimumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->resize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
        }
    }else{
        for(int i=1;i<=idbotones;i++){
        telescopios[i]->cambiartamanio(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->setMaximumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->setMinimumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[i]->resize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
    }
    }

    layouttelesopio->addWidget(telescopios[idbotones],fila,columna);
    layouttelesopio->addWidget(botones[idbotones],fila,columna);
    ui->PanelPrincipal->widget()->setLayout(layouttelesopio);
}


void MainWindow::on_pushButton_clicked()
{

    idbotones++;
    int fila= (idbotones/columnasmaxima);
    int columna = idbotones%columnasmaxima;
    if(columna == 0){
        columna = columnasmaxima;
        fila--;
    }
    telescopios[idbotones] = new telescopio(this);
    botones[idbotones] = new QPushButton();
    botones[idbotones]->setObjectName(QString::number(idbotones));
    connect(botones[idbotones], SIGNAL (clicked()),this, SLOT (on_botones_clicked()));

    if(idbotones < 5){
        for(int i=1;i<=idbotones;i++){
            telescopios[i]->cambiartamanio(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMaximumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->setMinimumSize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
            botones[i]->resize(ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)),ui->PanelPrincipal->height()/(1 + ((idbotones-1)*0.5)));
        }
    }else{
        telescopios[idbotones]->cambiartamanio(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->setMaximumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->setMinimumSize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
        botones[idbotones]->resize(ui->PanelPrincipal->height()/2.5,ui->PanelPrincipal->height()/2.5);
    }

    layouttelesopio->addWidget(telescopios[idbotones],fila,columna);
    layouttelesopio->addWidget(botones[idbotones],fila,columna);


    ui->PanelPrincipal->widget()->setLayout(layouttelesopio);

}




void MainWindow::on_botones_clicked()
{


    if(modoseleccion){
        nseleccionados++;
        telescopiosseleccionados[nseleccionados] = sender()->objectName().toInt();
        botones[sender()->objectName().toInt()]->hide();
    }
    else{
    nseleccionados=1;
    if(telescopiosseleccionados[nseleccionados] != 0){
        botones[telescopiosseleccionados[nseleccionados]]->setVisible(true);
    }
     telescopiosseleccionados[nseleccionados]=sender()->objectName().toInt();
     botones[sender()->objectName().toInt()]->hide();
    }


    MostrarPropiedades();
    ui->PanelDerecho->setVisible(true);
    ui->boolpanelderecho->setChecked(true);
    repintar();
}

void MainWindow::MostrarPropiedades(){
    QLabel *nombre = new QLabel;
    nombre->setText("Nombre de los telescopios");
    layoutpropiedades = new QGridLayout;

    layoutpropiedades->addWidget(nombre);

    ui->Propiedades->setLayout(layoutpropiedades);

}

void MainWindow::limpiar(){
    for(int i=1;i<nseleccionados+1;i++){
        botones[telescopiosseleccionados[i]]->setVisible(true);
        telescopiosseleccionados[i] = 0;

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

