#include "itemtexto.h"
#include "ui_itemtexto.h"
#include <string>
#include <QString>
itemtexto::itemtexto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemtexto)
{
    ui->setupUi(this);
}

itemtexto::~itemtexto()
{
    delete ui;
}


itemtexto::itemtexto(string nombre,string etiqueta,string gui,string value,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    this->value=value;

}




itemtexto::itemtexto(indigo_item item,int perm,QWidget *parent):QWidget(parent),ui(new Ui::itemtexto){

    ui->setupUi(this);
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);
    this->perm=perm;

    if(item.text.length < INDIGO_VALUE_SIZE){
        this->value=string(item.text.value);
        indigo_log(item.text.value);
    }else{
        this->value=string(item.text.long_value);
        indigo_log(item.text.long_value);
    }
    indigo_log(this->name.c_str());

    switch(this->perm){
        case 1:
            ui->nuevovalor->hide();
            ui->poner->hide();
            this->setMinimumHeight(100);

        break;
        case 2:

        break;
        case 3:

        break;
    }


    ui->menu->setText(QString::fromStdString(this->name));
    ui->etiqueta->setText(QString::fromStdString(this->label));
    ui->valor->insertPlainText(QString::fromStdString(this->value));


}



void itemtexto::mostrarpropiedad(){

    indigo_log("valor");
    indigo_log(this->name.c_str());
}

void itemtexto::on_poner_clicked()
{

}

