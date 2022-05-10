#include "itemswitch.h"
#include "ui_itemswitch.h"

itemswitch::itemswitch(QWidget *parent) :
    QWidget(parent)

{

}

itemswitch::~itemswitch()
{

}

itemswitch::itemswitch(string nombre,string etiqueta,string gui,bool valor,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    value=valor;
}
string itemswitch::getname(){
    return name;
}
bool itemswitch::getvalue(){
    return value;
}

itemswitch::itemswitch(indigo_item item,QWidget *parent):QWidget(parent){
    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);

    this->value=item.sw.value;

}
