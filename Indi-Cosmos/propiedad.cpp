#include "propiedad.h"
#include "ui_propiedad.h"
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include "cambiarvalor.h"
#include "foto.h"


using namespace std;
propiedad::propiedad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::propiedad)
{
    ui->setupUi(this);
}

propiedad::~propiedad()
{
    indigo_device_disconnect(cliente, (char*)devicename.c_str());
    delete ui;
}

propiedad::propiedad(string devicename,string name,string group,string label,string hints,int state,int type,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent):

    ui(new Ui::propiedad){
    ui->setupUi(this);



    this->padre= parent;
    this->devicename= devicename;
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
        case 5:
            for(int j=0;j<count;j++){
                solucion.push_back(itemsblob[j]->getname());
            }

            break;
    }
    return solucion;
}

vector<QWidget*> propiedad::itemsWidgets(){
    vector<QWidget*> solucion;
    QComboBox *seleccion = new QComboBox();
    QPushButton *boton;
    switch(type){
        case 1:

            for(int j=0;j<itemstexto.size();j++){
                boton= new QPushButton;
                boton->setText(QString::fromStdString(itemstexto[j]->getvalue()));
                boton->setObjectName(QString::fromStdString(itemstexto[j]->getname()));
                solucion.push_back(boton);
                connect(boton,SIGNAL (clicked()),this,SLOT(botontexto()));
            }

        break;
        case 2:
            for(int j=0;j<itemsnumero.size();j++){
                boton= new QPushButton;
                boton->setText(QString::number(itemsnumero[j]->getvalue()));
                boton->setObjectName(QString::fromStdString(itemsnumero[j]->getname()));
                solucion.push_back(boton);
                connect(boton,SIGNAL (clicked()),this,SLOT(botonnumero()));

            }
            break;
        case 3:
            for(int j=0;j<itemsswitch.size();j++){
            seleccion->addItem(QString::fromStdString(itemsswitch[j]->getname()));
                if(itemsswitch[j]->getvalue() == true){
                    seleccion->	setCurrentIndex(j);
                }
            }
            solucion.push_back(seleccion);
            break;
        case 4:
            for(int j=0;j<itemslight.size();j++){
                QPushButton *boton= new QPushButton;
                boton->setText(QString::number(itemslight[j]->getvalue()));
                boton->setObjectName(QString::number(itemslight[j]->getvalue()));
                solucion.push_back(boton);
            }
            break;
        case 5:
            for(int j=0;j<itemsblob.size();j++){

                    QPushButton *boton= new QPushButton;
                    boton->setText(QString::fromStdString(itemsblob[j]->getname()));
                    boton->setObjectName(QString::fromStdString(itemsblob[j]->getname()));
                    solucion.push_back(boton);
                    if(itemsblob[j]->getname() != ""){
                    connect(boton,SIGNAL (clicked()),this,SLOT(botonblob()));
                    }

            }

            break;
    }
    connect(seleccion,SIGNAL (currentIndexChanged(int)),this,SLOT(combobox_cambio(int)));

    return solucion;
}
int propiedad::buscartexto(string id){
    for(int j=0;j<itemstexto.size();j++){
        if(itemstexto[j]->getname() == id){
            return j;
        }
    }
    return -1;
}
int propiedad::buscarnumero(string id){
    for(int j=0;j<itemsnumero.size();j++){
        if(itemsnumero[j]->getname() == id){
            return j;
        }
    }
    return -1;
}


void propiedad::setnameblob(string name){
    itemsblobname.push_back(name);
     for(int j=0;j<itemsblob.size();j++){
         itemsblob[j]->setname(itemsblobname[j]);
     }


}

void propiedad::cambiartexto(string nameitem,string valornuevo){
    const char * items[] = { (char*)nameitem.c_str() };
    const char *values[] = {(char*)valornuevo.c_str()};
    indigo_change_text_property(cliente, (char*)devicename.c_str() , (char*)name.c_str() , 1, items, values);
}
void propiedad::cambiarnumero(string nameitem,double valornuevo){
    const char * items[] = { (char*)nameitem.c_str() };

    const double *values = &valornuevo;
    indigo_change_number_property(cliente, (char*)devicename.c_str() , (char*)name.c_str() , 1, items, values);
}
void propiedad::combobox_cambio(int index){
    string nameitem = itemsswitch[index]->getname();
    if (name == "CONNECTION"){
        if(nameitem == "CONNECTED"){
            indigo_device_connect(cliente, (char*)devicename.c_str());
        }else{
            indigo_device_disconnect(cliente, (char*)devicename.c_str());
        }
    }else{
        static const char * items[] = { (char*)nameitem.c_str()};
        static bool values[] = { true };
        indigo_change_switch_property(cliente, (char*)devicename.c_str(), (char*)name.c_str() , 1, items, values);
    }
}

void propiedad::botontexto(){
    int id = buscartexto(sender()->objectName().toStdString());
    if(id != -1){
        CambiarValor  *menu = new CambiarValor(itemstexto[id],perm,this) ;
        menu->show();
    }


}
void propiedad::botonnumero(){
    int id = buscarnumero(sender()->objectName().toStdString());
    if(id != -1){
        CambiarValor  *menu = new CambiarValor(itemsnumero[id],perm,this) ;
        menu->show();
    }


}

void propiedad::botonblob(){
    foto *nueva = new foto(sender()->objectName().toStdString());
    nueva->setWindowTitle(QString::fromStdString(sender()->objectName().toStdString()));
    nueva->show();
}






propiedad::propiedad(indigo_property *property,indigo_client *cliente,QWidget *parent){
    parent= parent;

    this->cliente=cliente;
    devicename= string(property->device);
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



    indigo_log(name.c_str());
    switch(type){
        case 1:
        indigo_log("crear tipo 1");


            for(int i=0;i<count;i++){
                itemstexto.push_back(new itemtexto(property->items[i],this));
            }
        break;

        case 2:
        indigo_log("crear tipo 2");

            for(int i=0;i<count;i++){
                itemsnumero.push_back( new itemnumero(property->items[i],property->perm,this));
            }
            break;
        case 3:
        indigo_log("crear tipo 3");


            for(int i=0;i<count;i++){
                itemsswitch.push_back( new itemswitch(property->items[i],this));
            }
            break;
        case 4:
       indigo_log("crear tipo 4");

            for(int i=0;i<count;i++){
                itemslight.push_back( new itemlight(property->items[i],this));
            }
            break;
        case 5:
        indigo_log("crear tipo 5");

            for(int i=0;i<count;i++){
                itemsblob.push_back( new itemblob(property->items[i],this));
            }
            break;
    }

}


void propiedad::on_pushButton_3_clicked()
{

}

