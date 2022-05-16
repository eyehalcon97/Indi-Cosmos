#include "device.h"
#include "ui_device.h"
#include "conectar.h"
#include <string>
#include <QString>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>


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
int device::indexof(vector<string> lista,string value){
    for(int i=0;i<lista.size();i++){
        if(lista[i] == value){
            return i;
        }
    }
    return -1;
}

QVBoxLayout* device::mostrarpropiedades(){
    QTreeWidget *arbol= new QTreeWidget;
    arbol->setColumnCount(2);
    QStringList cabecera;
    cabecera << "propiedades" << "value" ;
    arbol->setHeaderLabels(cabecera);
    arbol->setColumnWidth(0,200);
    arbol->setColumnWidth(1,100);

    QVBoxLayout* layout = new QVBoxLayout;
    vector<string>grupos;
    vector<QTreeWidgetItem*> raices;

    for(int i=0;i<propiedades.size();i++){
        int id = indexof(grupos,string(propiedades[i]->getgroup()));
        if(id == -1){
            grupos.push_back(string(propiedades[i]->getgroup()));
            QTreeWidgetItem *raiz = new QTreeWidgetItem(arbol);

            raiz->setText(0,QString::fromStdString(propiedades[i]->getgroup()));
            raiz->setExpanded(true);
            arbol->addTopLevelItem(raiz);



            raices.push_back(raiz);
            id = raices.size()-1;


        }
        QTreeWidgetItem *child = new QTreeWidgetItem;

        child->setText(0,propiedades[i]->getname().c_str());

        switch(propiedades[i]->getstate()){
            case 0:

            child->setBackground(1, QColor( 0, 0, 255) );

            break;
            case 1:
            child->setBackground(1, QColor( 0, 255, 0 ) );

            break;
            case 2:
            child->setBackground(1, QColor( 255, 130, 0 ) );
            break;
            case 3:
            child->setBackground(1, QColor( 255, 0, 0 ) );
            break;
        }

         raices[id]->addChild(child);
         vector<string> itemsname = propiedades[i]->itemsname();
         vector<QWidget*> itemsWidget = propiedades[i]->itemsWidgets();
         for(int j=0;j<itemsname.size();j++){
             QTreeWidgetItem *itemname = new QTreeWidgetItem;

             itemname->setText(0,itemsname[j].c_str());
             child->addChild(itemname);
             child->setExpanded(true);
             arbol->setItemWidget(itemname,1,itemsWidget[j]);
         }





    }



    layout->addWidget(arbol);
    return layout;



}



void device::expandir(){
    //string hola = raiz->text(0).toStdString();
    indigo_log("hola.c_str()");
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



