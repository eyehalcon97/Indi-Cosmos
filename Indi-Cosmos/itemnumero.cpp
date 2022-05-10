#include "itemnumero.h"
#include "ui_itemnumero.h"

itemnumero::itemnumero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemnumero)
{
    ui->setupUi(this);
}

itemnumero::~itemnumero()
{
    delete ui;
}



itemnumero::itemnumero(string nombre,string etiqueta,string gui,string format,double min,double max,double step,double value,double target,QWidget *parent){
    name=nombre;
    label=etiqueta;
    hints=gui;
    padre=parent;
    this->format=format;
    this->min=min;
    this->max=max;
    this->step=step;
    this->value=value;
    this->target=target;

}

itemnumero::itemnumero(indigo_item item,int perm,QWidget *parent):QWidget(parent), ui(new Ui::itemnumero){
    ui->setupUi(this);
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

    switch(this->perm){
        case 1:
            ui->nuevovalor->hide();
            ui->poner->hide();
            this->setMinimumHeight(100);

        break;
        case 2:

        break;
        case 3:

        break;
    }

    ui->menu->setText(QString::fromStdString(this->name));
    ui->etiqueta->setText(QString::fromStdString(this->label));
    ui->valor->insertPlainText(QString::number(value));

}
