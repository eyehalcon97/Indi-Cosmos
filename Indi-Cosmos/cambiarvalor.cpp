#include "cambiarvalor.h"
#include "ui_cambiarvalor.h"
#include "itemtexto.h"
#include "itemnumero.h"
#include "propiedad.h"

using namespace std;
CambiarValor::CambiarValor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CambiarValor)
{
    ui->setupUi(this);
}

CambiarValor::~CambiarValor()
{
    delete ui;
}


CambiarValor::CambiarValor(itemtexto *item,int perm,propiedad *parent):QWidget(parent),ui(new Ui::CambiarValor){
    ui->setupUi(this);

    padre = parent;
    tipo=0;
    name=string(item->getname());
    label=string(item->getlabel());
    valuetexto=string(item->getvalue());
    this->perm=perm;

    this->setWindowTitle(QString::fromStdString(name));
    ui->label->setText(QString::fromStdString(label));
    ui->value->setText(QString::fromStdString(valuetexto));




    switch(perm){
        case 1:
            ui->texto->hide();
            ui->nuevovalornumero->hide();
            ui->nuevovalortexto->hide();
        break;
        case 2:
            ui->nuevovalornumero->hide();
        break;
        case 3:

        break;
    }
}



CambiarValor::CambiarValor(itemnumero *item,int perm,propiedad *parent):QWidget(parent),ui(new Ui::CambiarValor){
    ui->setupUi(this);
    padre = parent;
    tipo=1;

    name=string(item->getname());
    label=string(item->getlabel());
    valuenumero=item->getvalue();
    this->perm=perm;

    this->setWindowTitle(QString::fromStdString(name));
    ui->label->setText(QString::fromStdString(label));


    ui->value->setText(QString::number(valuenumero));

    format=item->getformat();
    min=item->getmin();
    max=item->getmax();
    step=item->getstep();
    target=item->gettarget();


    switch(perm){
        case 1:
            ui->texto->hide();
            ui->nuevovalornumero->hide();
            ui->nuevovalortexto->hide();
        break;
        case 2:
            ui->nuevovalortexto->hide();
            ui->target->setText("valor objetivo : " + QString::number(target));
            ui->minimo->setText("Valor minimo : " + QString::number(min));
            ui->maximo->setText("Valor maximo : " + QString::number(max));
            ui->cambiarvalordouble->setValue(valuenumero);
            ui->cambiarvalordouble->setSingleStep(step);
            ui->cambiarvalordouble->setRange(min,max);

        break;
        case 3:

        break;
    }


}

void CambiarValor::on_boton_clicked()
{

    if (perm == 2){
        switch(tipo){
        case 0: // tipo texto
            padre->cambiartexto(name,ui->nuevovalortexto->toPlainText().toStdString());

            break;
        case 1: // tipo numero

            break;
        }
    }



    this->close();
}

