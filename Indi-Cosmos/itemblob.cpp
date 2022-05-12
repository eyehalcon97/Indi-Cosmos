#include "itemblob.h"


using namespace std;

itemblob::itemblob(QWidget *parent) : QWidget(parent)
{

}

itemblob::~itemblob()
{

}

itemblob::itemblob(string nombre,string etiqueta,string gui,string format,string urls,long tam,void *valor,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    formato=format;
    url = urls;
    size=tam;
    value=valor;
}


itemblob::itemblob(indigo_item item,QWidget *parent): QWidget(parent){

    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);

    this->formato = string(item.blob.format);
    this->url = string(item.blob.url);
    this->size = item.blob.size;
    this->value = item.blob.value;
}
