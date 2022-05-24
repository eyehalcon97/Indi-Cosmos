#include "itemlight.h"


itemlight::itemlight(QWidget *parent) :
    QWidget(parent)
{

}

itemlight::~itemlight()
{

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
