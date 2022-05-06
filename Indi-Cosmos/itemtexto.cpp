#include "itemtexto.h"
#include "ui_itemtexto.h"

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


itemtexto::itemtexto(string nombre,string etiqueta,string gui,string value,string long_value,long length,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    this->value=value;
    this->long_value=long_value;
    this->length=length;

}

itemtexto::itemtexto(indigo_item *item,QWidget *parent){
    padre=parent;
    this->name=string(item->name);
    this->label=string(item->label);
    this->hints=string(item->hints);

    this->value=string(item->text.value);
    this->long_value=string(item->text.long_value);
    this->length=item->text.length;

}
