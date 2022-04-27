#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include <telescopio.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_boolpanelderecho_changed();

    void on_actionSalir_triggered();


    void on_boolpanelsuperior_changed();

    void on_Nobjetos_valueChanged(int arg1);

    void on_pushButton_clicked();


    void on_botones_clicked();

    void limpiar();


    void on_checkBox_stateChanged(int arg1);
    //void resizeEvent(QResizeEvent* event);
    void repintar();
    void MostrarPropiedades();


private:
    Ui::MainWindow *ui;
    QPushButton **botones  = new QPushButton*[100];
    QGridLayout *layouttelesopio = new QGridLayout;
    QGridLayout *layoutpropiedades;
    telescopio **telescopios  = new telescopio*[100];
    int *telescopiosseleccionados = new int[100];
    int nseleccionados=0;
    bool modoseleccion=false;
    int idbotones=0;
    int columnasmaxima =4;


};
#endif // MAINWINDOW_H

