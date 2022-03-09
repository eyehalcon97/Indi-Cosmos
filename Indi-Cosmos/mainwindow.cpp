#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

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
}


void MainWindow::on_Nobjetos_valueChanged(int arg1)
{
    //ui->label->setText(QString::number(arg1));
    QPushButton **boton  = new QPushButton*[arg1];
    for (int i=0;i<arg1;i++){
        boton[i] = new QPushButton;
        boton[i]->setText("Boton numero " + QString::number(i+1) );
        boton[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
        ui->PanelPrincipal->setWidget(boton[i]);
        boton[i]->setVisible(true);
    }

}


void MainWindow::on_pushButton_clicked()
{

}



