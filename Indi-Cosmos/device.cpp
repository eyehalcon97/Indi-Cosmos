#include "device.h"
#include "ui_device.h"
#include "conectar.h"
#include <string>
#include <QString>
#include <QVBoxLayout>


using namespace std;


device::device(string id,indigo_client *cliente, QWidget *parent) :QWidget(parent),ui(new Ui::device)
{
  deviceid = id ;
  this->cliente=cliente;
  conectar w;
  w.show();


  ui->setupUi(this);
}


device::~device()
{
    delete ui;
}
propiedad* device::getpropiedad(int num){
    return propiedades[num];
}
int device::getnpropiedades(){
    return propiedades.size();
}
void device::eliminarpropiedad(indigo_property* property){


    for(int i=0;i<=propiedades.size();i++){
       if(propiedades[i]->getname() == string(property->name)){
          propiedades.erase (propiedades.begin()+i);

       }

    }


}

void device::cambiarpropiedad(indigo_property* property){
    for(int i=0;i<propiedades.size();i++){
       if(propiedades[i]->getname() == string(property->name)){
          propiedades[i] = new propiedad(property,cliente,this);
       }

    }
}


void device::nuevapropiedad(indigo_property* property){
    propiedades.push_back(new propiedad(property,cliente,this));

}

QVBoxLayout* device::mostrarpropiedades(){
QWidget *widget = new QWidget;

if ( widget->layout() != NULL )
{
    QLayoutItem* item;
    while ( ( item = widget->layout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
    delete widget->layout();
}


QVBoxLayout* layout = new QVBoxLayout;
    for(int i=0;i<propiedades.size();i++){
        widget = new QWidget;
        widget->setLayout(propiedades[i]->getlayout());
        layout->addWidget(widget,i);

    }



    return layout;
}

string device::getDeviceID(){
    return deviceid;
}


void device::cambiartamanio(int anchura,int altura){

    this->setMinimumSize(anchura,altura);
    this->setMaximumSize(anchura,altura);
    ui->paneldevice->setMaximumSize(anchura,altura);
    ui->paneldevice->setMinimumSize(anchura,altura);
    ui->paneldevice->resize(anchura,altura);
    ui->scrolltexto->setMinimumHeight(altura*0.3);
    ui->scrolltexto->setMaximumHeight(altura*0.3);
    ui->texto_3->setText(deviceid.c_str());

}



