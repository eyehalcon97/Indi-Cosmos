#include "telescopio.h"
#include "ui_telescopio.h"


telescopio::telescopio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::telescopio)
{
    ui->setupUi(this);
}


telescopio::~telescopio()
{
    delete ui;
}


void telescopio::cambiartamanio(int anchura,int altura){

    this->setMinimumSize(anchura,altura);
    this->setMaximumSize(anchura,altura);
    ui->paneltelescopio->setMaximumSize(anchura,altura);
    ui->paneltelescopio->setMinimumSize(anchura,altura);
    ui->paneltelescopio->resize(anchura,altura);
    ui->scrolltexto->setMinimumHeight(altura*0.3);
    ui->scrolltexto->setMaximumHeight(altura*0.3);
    ui->texto_3->setText("Esto es una descripcion");

}



