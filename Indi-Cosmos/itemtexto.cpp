#include "itemtexto.h"

#include <string>
#include <QString>
itemtexto::itemtexto(QWidget *parent) :
    QWidget(parent)
{

}

itemtexto::~itemtexto()
{

}


itemtexto::itemtexto(string nombre,string etiqueta,string gui,string value,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    this->value=value;

}

string itemtexto::getname(){
    return name;
}
string itemtexto::getlabel(){
    return label;
}
string itemtexto::getvalue(){
    return value;
}


itemtexto::itemtexto(indigo_item item,QWidget *parent):QWidget(parent){


    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);

    if(item.text.length < INDIGO_VALUE_SIZE){
        this->value=string(item.text.value);
        indigo_log(item.text.value);
    }else{
        this->value=string(item.text.long_value);
        indigo_log(item.text.long_value);
    }
    indigo_log(this->name.c_str());





}



void itemtexto::mostrarpropiedad(){

    indigo_log("valor");
    indigo_log(this->name.c_str());
}

void itemtexto::on_poner_clicked()
{

}

