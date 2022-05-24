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
    }else{
        this->value=string(item.text.long_value);
    }



}


