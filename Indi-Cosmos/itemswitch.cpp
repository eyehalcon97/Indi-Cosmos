#include "itemswitch.h"


itemswitch::itemswitch(QWidget *parent) :
    QWidget(parent)

{

}

itemswitch::~itemswitch()
{

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
