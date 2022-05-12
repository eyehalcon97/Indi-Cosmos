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
int propiedad::getcount(){
    return count;
}
int propiedad::gettype(){
    return type;
}
QVBoxLayout *propiedad::getlayout(){
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layouthorizontal = new QHBoxLayout;
    QWidget *nombreluz = new QWidget;
    QLabel *nombre= new QLabel;
    QPushButton *conexion = new QPushButton;


    nombre = new QLabel;
    nombre->setText(QString::fromStdString(group));
    layout->addWidget(nombre);


    nombre = new QLabel;/*
    if(conectado){

        nombre->setText("Conexion: conectado");
        conexion->setText("Desconectar");

    }else{
        nombre->setText("Conexion: desconectado");
        conexion->setText("Conectar");
    }
    layout->addWidget(nombre);
    layout->addWidget(conexion);*/


    nombre = new QLabel;
    switch(state){
        case 0:

        nombre->setStyleSheet("background-color:blue;");

        break;
        case 1:

        nombre->setStyleSheet("background-color:green;");
        break;
        case 2:

        nombre->setStyleSheet("background-color:orange;");
        break;
        case 3:

        nombre->setStyleSheet("background-color:red;");
        break;
    }

    layouthorizontal->addWidget(nombre);
    nombre = new QLabel;
    nombre->setText(QString::fromStdString(name));
    layouthorizontal->addWidget(nombre);

    nombreluz->setLayout(layouthorizontal);

    layout->addWidget(nombreluz);





    nombre = new QLabel;
    nombre->setText(QString::fromStdString(label));
    layout->addWidget(nombre);

    nombre = new QLabel;
    nombre->setText("hints " + QString::fromStdString(hints));
    layout->addWidget(nombre);

    nombre = new QLabel;

        layout->addWidget(nombre,4);

        QComboBox *seleccion = new QComboBox;
        QLabel *menu = new QLabel;
        QLabel *etiqueta = new QLabel;
        QPlainTextEdit *valor = new QPlainTextEdit;
        QPlainTextEdit *nuevovalor = new QPlainTextEdit;
        QVBoxLayout *layoutitems = new QVBoxLayout;
        QWidget *item = new QWidget;
        QPushButton *boton = new QPushButton;


        boton->setText("Poner");
        //connect(seleccion, SIGNAL (&QComboBox::currentIndexChanged(int)),this, SLOT (combobox_cambio(int)));



switch(type){
    case 1:
        for(int j=0;j<count;j++){
            menu->setText(QString::fromStdString(itemstexto[j]->getname()));
            etiqueta->setText(QString::fromStdString(itemstexto[j]->getlabel()));
            valor->insertPlainText(QString::fromStdString(itemstexto[j]->getvalue()));
            valor->setReadOnly(true);

            layoutitems->addWidget(menu);
            layoutitems->addWidget(etiqueta);
            layoutitems->addWidget(valor);
            if(perm != 1){
                layoutitems->addWidget(nuevovalor);
                layoutitems->addWidget(boton);
            }

            item->setLayout(layoutitems);

        }
        layout->addWidget(item);

    break;

    case 2:
    for(int j=0;j<count;j++){
        menu->setText(QString::fromStdString(itemsnumero[j]->getname()));
        etiqueta->setText(QString::fromStdString(itemsnumero[j]->getlabel()));
        valor->insertPlainText(QString::number(itemsnumero[j]->getvalue()));
        valor->setReadOnly(true);

        layoutitems->addWidget(menu);
        layoutitems->addWidget(etiqueta);
        layoutitems->addWidget(valor);
        if(perm != 1){
            layoutitems->addWidget(nuevovalor);
            layoutitems->addWidget(boton);
        }

        item->setLayout(layoutitems);

    }
    layout->addWidget(item);

        break;
    case 3:

        for(int j=0;j<count;j++){
            seleccion->addItem(QString::fromStdString(itemsswitch[j]->getname()));
            if(itemsswitch[j]->getvalue() == true){
                seleccion->	setCurrentIndex(j);
            }



        }
        layoutitems->addWidget(seleccion);
        item->setLayout(layoutitems);

        layout->addWidget(item);

        break;
    case 4:
        for(int j=0;j<count;j++){
            switch(itemslight[j]->getvalue()){
                case 0:
                item->setStyleSheet("background-color:blue;");
                break;
                case 1:
                item->setStyleSheet("background-color:green;");
                break;
                case 2:
                item->setStyleSheet("background-color:orange;");
                break;
                case 3:
                item->setStyleSheet("background-color:red;");
                break;
            }
        }

        break;
    /*case 5:
        for(int j=0;j<count;j++){
            layout->addWidget(itemsblob[j]);
        }

        break;*/
}
    connect(seleccion,SIGNAL (currentIndexChanged(int)),this,SLOT(combobox_cambio(int)));


    return layout;
}
/*
void propiedad::conectar(){
    if(conectado){
        indigo_device_disconnect(cliente, (char*)device.c_str());
        conectado=false;
    }else{
        indigo_device_connect(cliente, (char*)device.c_str());
        conectado=true;
    }
}*/

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
    indigo_log(itemsswitch[index]->getname().c_str());


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

