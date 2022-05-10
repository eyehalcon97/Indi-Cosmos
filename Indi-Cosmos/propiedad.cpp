#include "propiedad.h"
#include "ui_propiedad.h"
#include <string>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

using namespace std;
propiedad::propiedad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::propiedad)
{
    ui->setupUi(this);
}

propiedad::~propiedad()
{
    delete ui;
}

propiedad::propiedad(string device,string name,string group,string label,string hints,int state,int type,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent){
    this->parent= parent;
    this->device= device;
    this->name= name;
    this->group= group;
    this->label= label;
    this->hints= hints;
    this->state= state;
    this->type= type;
    this->rule= rule;
    this->access_token= access_token;
    this->version= version;
    this->hidden= hidden;


}
string propiedad::getname(){
    return string(name);
}
int propiedad::getcount(){
    return count;
}
int propiedad::gettype(){
    return type;
}
QVBoxLayout *propiedad::getlayout(){
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *nombre;

    nombre = new QLabel;
    nombre->setText(QString::fromStdString(device));
    layout->addWidget(nombre,0);

    nombre = new QLabel;
    nombre->setText(QString::fromStdString(name));
    layout->addWidget(nombre,1);


    nombre = new QLabel;
    nombre->setText(QString::fromStdString(group));
    layout->addWidget(nombre,2);


    nombre = new QLabel;
    nombre->setText(QString::fromStdString(label));
    layout->addWidget(nombre,3);

    nombre = new QLabel;
    nombre->setText("hints " + QString::fromStdString(hints));
    layout->addWidget(nombre,3);



    switch(state){
        case 0:
            nombre->setText("valor luz: INDIGO_IDLE_STATE");
        break;
        case 1:
            nombre->setText("valor luz: INDIGO_OK_STATE");
        break;
        case 2:
            nombre->setText("valor luz: INDIGO_BUSY_STATE");
        break;
        case 3:
            nombre->setText("valor luz: INDIGO_ALERT_STATE");
        break;
    }
        layout->addWidget(nombre,4);
        QComboBox *seleccion = new QComboBox;
switch(type){
    case 1:
        for(int j=0;j<count;j++){
            layout->addWidget(itemstexto[j],j+5);
        }
    break;

    case 2:
        for(int j=0;j<count;j++){
            layout->addWidget(itemsnumero[j],j+5);
         }

        break;
    case 3:

        for(int j=0;j<count;j++){
            seleccion->addItem(QString::fromStdString(itemsswitch[j]->getname()));
            if(itemsswitch[j]->getvalue() == true){
                seleccion->	setCurrentIndex(j);
            }


        }
        layout->addWidget(seleccion,5);

        break;
    case 4:
        for(int j=0;j<count;j++){
            layout->addWidget(itemslight[j],j+5);
        }

        break;
    case 5:
        for(int j=0;j<count;j++){
            layout->addWidget(itemsblob[j],j+5);
        }

        break;
}


    return layout;
}

propiedad::propiedad(indigo_property *property,QWidget *parent){
    parent= parent;


    device= string(property->device);
    name = string(property->name);

    group= string(property->group);
    label= string(property->label);
    hints= string(property->hints);
    state= property->state;
    type= property->type;
    rule= property->rule;
    count = property->count;
    access_token= property->access_token;
    version= property->version;
    hidden= property->hidden;


    indigo_log(name.c_str());
    switch(type){
        case 1:
        indigo_log("crear tipo 1");

            itemstexto = new itemtexto*[count];
            for(int i=0;i<count;i++){
                itemstexto[i] = new itemtexto(property->items[i],property->perm,this);
            }
        break;

        case 2:
        indigo_log("crear tipo 2");

            itemsnumero = new itemnumero*[count];
            for(int i=0;i<count;i++){
                itemsnumero[i] = new itemnumero(property->items[i],property->perm,this);
            }
            break;
        case 3:
        indigo_log("crear tipo 3");

            itemsswitch = new itemswitch*[count];

            for(int i=0;i<count;i++){
                itemsswitch[i] = new itemswitch(property->items[i],this);
            }
            break;
        case 4:
       indigo_log("crear tipo 4");

            itemslight = new itemlight*[count];
            for(int i=0;i<count;i++){
                itemslight[i] = new itemlight(property->items[i],this);
            }
            break;
        case 5:
        indigo_log("crear tipo 5");

            itemsblob = new itemblob*[count];
            for(int i=0;i<count;i++){
                itemsblob[i] = new itemblob(property->items[i],this);
            }
            break;
    }

}

