#include "device.h"
#include "ui_device.h"


device::device(QWidget *parent , char* id) :QWidget(parent),ui(new Ui::device)
{
  deviceid = id ;


  ui->setupUi(this);
}


device::~device()
{
    delete ui;
}
indigo_property* device::getpropiedad(int num){
    return propiedades[num];
}
int device::getnpropiedades(){
    return npropiedades;
}
void device::nuevapropiedad(indigo_property* propiedad){
    npropiedades++;
    propiedades[npropiedades] = propiedad;

}

char* device::getDeviceID(){
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
    ui->texto_3->setText(deviceid);

}



