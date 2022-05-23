#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include "device.h"
#include<QThread>


#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void creardevice(string id,indigo_client *cliente);
    QThread *workerThread;



public slots:
    void nuevodispositivo();
    void nuevapropiedad(indigo_property *propiedad,indigo_client *cliente);
    void cambiarpropiedadnameblob(indigo_property *propiedad,indigo_client *cliente,string nameblob);
    void eliminarpropiedad(indigo_property *propiedad);
    void cambiarpropiedad(indigo_property *propiedad);
    void MostrarPropiedades();


private slots:

    void repintar();
    void on_boolpanelderecho_changed();

    void on_actionSalir_triggered();


    void on_boolpanelsuperior_changed();

    void on_Nobjetos_valueChanged(int arg1);



    void botones_clicked();

    void limpiar();


    void on_checkBox_stateChanged(int arg1);
    //void resizeEvent(QResizeEvent* event);


    void resizeEvent(QResizeEvent*);






    int indexofdevice(string id);


    void on_ButtonConectar_clicked();

    void on_pushButton_clicked();

signals:
    void conectarlib(string nombre,string host,int puerto);

private:
    Ui::MainWindow *ui;
    QPushButton **botones  = new QPushButton*[100];
    QGridLayout *layoutdevice = new QGridLayout;
    QGridLayout *layoutpropiedades;
    device **devices  = new device*[100];
    int *devicesseleccionados = new int[100];
    int nseleccionados=0;
    bool modoseleccion=false;
    int idbotones=0;
    int columnasmaxima =4;



};
#endif // MAINWINDOW_H

