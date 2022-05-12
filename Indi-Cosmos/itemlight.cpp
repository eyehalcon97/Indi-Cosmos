#include "itemlight.h"


itemlight::itemlight(QWidget *parent) :
    QWidget(parent)
{

}

itemlight::~itemlight()
{

}

itemlight::itemlight(string nombre,string etiqueta,string gui ,int valor,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    value=valor;
}

itemlight::itemlight(indigo_item item,QWidget *parent):QWidget(parent){
    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);
    value=item.light.value;
}

int itemlight::getvalue(){
    return value;
}
