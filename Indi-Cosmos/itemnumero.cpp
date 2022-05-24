#include "itemnumero.h"


itemnumero::itemnumero(QWidget *parent) :
    QWidget(parent)
{

}

itemnumero::~itemnumero()
{

}
string itemnumero::getname(){
    return name;
}
string itemnumero::getlabel(){
    return label;
}
double itemnumero::getvalue(){
    return value;
}
string itemnumero::getformat(){
    return format;
}
double itemnumero::getmin(){
    return min;
}
double itemnumero::getmax(){
    return max;
}
double itemnumero::getstep(){
    return step;
}
double itemnumero::gettarget(){
    return target;
}


itemnumero::itemnumero(indigo_item item,int perm,QWidget *parent):QWidget(parent){

    padre=parent;
    this->name=string(item.name);
    this->label=string(item.label);
    this->hints=string(item.hints);
    this->perm=perm;

    this->format=string(item.number.format);
    this->min=item.number.min;
    this->max=item.number.max;
    this->step=item.number.step;
    this->value=item.number.value;
    this->target=item.number.target;


}
