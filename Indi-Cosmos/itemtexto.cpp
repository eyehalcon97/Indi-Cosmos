#include "itemtexto.h"
#include "ui_itemtexto.h"
#include <string>
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

itemtexto::itemtexto(indigo_item item,QWidget *parent){

    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);


    if(item.text.length < INDIGO_VALUE_SIZE){
        this->value=string(item.text.value);
    }else{
        this->value=string(item.text.long_value);
    }

}
