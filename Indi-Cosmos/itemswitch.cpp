#include "itemswitch.h"
#include "ui_itemswitch.h"

itemswitch::itemswitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemswitch)
{
    ui->setupUi(this);
}

itemswitch::~itemswitch()
{
    delete ui;
}

itemswitch::itemswitch(string nombre,string etiqueta,string gui,bool valor,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    value=valor;
}

itemswitch::itemswitch(indigo_item item,QWidget *parent){
    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);

    this->value=item.sw.value;

}
