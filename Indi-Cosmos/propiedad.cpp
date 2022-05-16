#include "propiedad.h"
#include "ui_propiedad.h"
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>


using namespace std;
propiedad::propiedad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::propiedad)
{
    ui->setupUi(this);
}

propiedad::~propiedad()
{
    indigo_device_disconnect(cliente, (char*)device.c_str());
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

string propiedad::getgroup(){
    return string(group);
}

int propiedad::getcount(){
    return count;
}
int propiedad::gettype(){
    return type;
}
int propiedad::getstate(){
    return state;
}
bool propiedad::getexpandido(){
    return expandido;
}
void propiedad::setexpandido(bool expandido){
    this->expandido = expandido;
}

vector<string> propiedad::itemsname(){
    vector<string> solucion;
    switch(type){
        case 1:
            for(int j=0;j<count;j++){
                solucion.push_back(itemstexto[j]->getname());
            }
        break;
        case 2:
        for(int j=0;j<count;j++){
            solucion.push_back(itemsnumero[j]->getname());
        }
            break;
        case 3:
                solucion.push_back(" ");
            break;
        case 4:
            for(int j=0;j<count;j++){
                solucion.push_back("luz");
            }
            break;
        /*case 5:
            for(int j=0;j<count;j++){
                layout->addWidget(itemsblob[j]);
            }

            break;*/
    }
    return solucion;
}

vector<QWidget*> propiedad::itemsWidgets(){
    vector<QWidget*> solucion;
    QComboBox *seleccion = new QComboBox();

    switch(type){
        case 1:
            for(int j=0;j<count;j++){
                QPushButton *boton= new QPushButton;
                boton->setText(QString::fromStdString(itemstexto[j]->getvalue()));
                solucion.push_back(boton);
            }
        break;
        case 2:
        for(int j=0;j<count;j++){
            QPushButton *boton= new QPushButton;
            boton->setText(QString::number(itemsnumero[j]->getvalue()));
            solucion.push_back(boton);

        }
            break;
        case 3:
            for(int j=0;j<count;j++){
            seleccion->addItem(QString::fromStdString(itemsswitch[j]->getname()));
                if(itemsswitch[j]->getvalue() == true){
                    seleccion->	setCurrentIndex(j);
                }
            }
            solucion.push_back(seleccion);
            break;
        case 4:
            for(int j=0;j<count;j++){
                QPushButton *boton= new QPushButton;
                boton->setText(QString::number(itemslight[j]->getvalue()));
                solucion.push_back(boton);
            }
            break;
        /*case 5:
            for(int j=0;j<count;j++){
                layout->addWidget(itemsblob[j]);
            }

            break;*/
    }
    connect(seleccion,SIGNAL (currentIndexChanged(int)),this,SLOT(combobox_cambio(int)));
    return solucion;
}

void propiedad::combobox_cambio(int index){

    indigo_log("cambiado");
    int numero = sender()->objectName().toInt();
    if (name == "CONNECTION"){
        if(itemsswitch[index]->getname() == "CONNECTED"){
            indigo_device_connect(cliente, (char*)device.c_str());
        }else{
            indigo_device_disconnect(cliente, (char*)device.c_str());
        }
    }
}



propiedad::propiedad(indigo_property *property,indigo_client *cliente,QWidget *parent){
    parent= parent;

    this->cliente=cliente;
    device= string(property->device);
    name = string(property->name);
    perm = property->perm;
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
    expandido=false;



    indigo_log(name.c_str());
    switch(type){
        case 1:
        indigo_log("crear tipo 1");

            itemstexto = new itemtexto*[count];
            for(int i=0;i<count;i++){
                itemstexto[i] = new itemtexto(property->items[i],this);
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

