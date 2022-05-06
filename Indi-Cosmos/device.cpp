#include "device.h"
#include "ui_device.h"
#include "conectar.h"
#include <string>
#include <QString>

using namespace std;


device::device(QWidget *parent , string id) :QWidget(parent),ui(new Ui::device)
{
  deviceid = id ;
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
    return npropiedades;
}
void device::nuevapropiedad(indigo_property* property){
    npropiedades++;
    propiedades[npropiedades] = new propiedad(property,this);

}

string device::getDeviceID(){
    return deviceid;
}
QLayout* device::getlayoutpropiedad(){
    QLayout *layout = new QGridLayout;
    return layout;
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



