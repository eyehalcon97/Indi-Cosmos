#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include <device.h>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void creardevice(char* propiedad);


private slots:

    void on_boolpanelderecho_changed();

    void on_actionSalir_triggered();


    void on_boolpanelsuperior_changed();

    void on_Nobjetos_valueChanged(int arg1);



    void botones_clicked();

    void limpiar();


    void on_checkBox_stateChanged(int arg1);
    //void resizeEvent(QResizeEvent* event);
    void repintar();
    void MostrarPropiedades();


    int indexofdevice(char* id);

    void on_Conectar_clicked();

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

