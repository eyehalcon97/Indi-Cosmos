#include "device.h"
#include "propiedad.h"
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
           propiedad *nueva = new propiedad(property,cliente,this);
          propiedades[i] = nueva;
       }

    }

}


void device::nuevapropiedad(indigo_property* property){
    propiedad *nueva = new propiedad(property,cliente,this);
    propiedades.push_back(nueva);


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
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel *nombre = new QLabel;

    nombre->setText("Nombre del dispositivo");
    nombre->setMaximumHeight(20);
    nombre->setMinimumHeight(20);

    layout->addWidget(nombre);

    nombre = new QLabel;
    nombre->setText(deviceid.c_str());
    nombre->setMaximumHeight(20);
    nombre->setMinimumHeight(20);


    layout->addWidget(nombre);

    QTreeWidget *arbol= new QTreeWidget;
    arbol->setColumnCount(2);
    QStringList cabecera;
    cabecera << "propiedades" << "value" ;
    arbol->setHeaderLabels(cabecera);


    arbol->setColumnWidth(0,200);
    arbol->setColumnWidth(1,100);


    vector<string>grupos;
    vector<QTreeWidgetItem*> raices;
    elements=2;

    for(int i=0;i<propiedades.size();i++){
        int id = indexof(grupos,string(propiedades[i]->getgroup()));
        if(id == -1){
            grupos.push_back(string(propiedades[i]->getgroup()));
            elements++;
            QTreeWidgetItem *raiz = new QTreeWidgetItem(arbol);

            raiz->setText(0,QString::fromStdString(propiedades[i]->getgroup()));
            raiz->setExpanded(estaexpandido(raiz->text(0).toStdString()));
           // if(estaexpandido(raiz->text(0).toStdString())){
               elements++;
            //}
            arbol->addTopLevelItem(raiz);

            if(estaseleccionado(raiz->text(0).toStdString())){
               arbol->setCurrentItem(raiz);
            }
            raices.push_back(raiz);
            id = raices.size()-1;


        }else{

            //if(estaexpandido(propiedades[i]->getgroup())){
               elements++;
            //}

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
         if(estaseleccionado(child->text(0).toStdString())){
            arbol->setCurrentItem(child);
         }
         vector<string> itemsname = propiedades[i]->itemsname();
         vector<QWidget*> itemsWidget = propiedades[i]->itemsWidgets();
         for(int j=0;j<itemsname.size();j++){
             QTreeWidgetItem *itemname = new QTreeWidgetItem;

             itemname->setText(0,itemsname[j].c_str());
             child->addChild(itemname);
             bool expandido = estaexpandido(child->text(0).toStdString());

             child->setExpanded(expandido);
             //if(expandido){
                elements++;
             //}
             arbol->setItemWidget(itemname,1,itemsWidget[j]);
             if(estaseleccionado(itemname->text(0).toStdString())){
                arbol->setCurrentItem(itemname);
             }
         }





    }

    //+ numitems + 1;
    int minimo = 800;
    if(20*elements > minimo){
        minimo = 20*elements;
    }
    arbol->setMinimumHeight(minimo);
    arbol->setMaximumHeight(minimo);


    connect(arbol,SIGNAL (itemExpanded(QTreeWidgetItem*)),this,SLOT(expandir(QTreeWidgetItem*)));
    connect(arbol,SIGNAL (itemCollapsed(QTreeWidgetItem*)),this,SLOT(disminuir(QTreeWidgetItem*)));
    connect(arbol,SIGNAL (itemClicked(QTreeWidgetItem*,int)),this,SLOT(cambiarseleccion(QTreeWidgetItem*,int)));

    layout->addWidget(arbol);
    return layout;



}

void device::cambiarseleccion(QTreeWidgetItem *objeto,int num){
        if(objeto->text(0).toStdString() != " "){
            seleccionado = objeto->text(0).toStdString();
            indigo_log(seleccionado.c_str());
        }else{
            seleccionado = "-1";
        }

}


void device::disminuir(QTreeWidgetItem *objeto){
    for(int i=0;i<expandidos.size();i++){
        if(expandidos[i] == objeto->text(0).toStdString()){
            expandidos.erase(expandidos.begin()+i);



        }
    }

}

bool device::estaexpandido(string objeto){
    for(int i=0;i<expandidos.size();i++){
        if(expandidos[i] == objeto){
            return true;

        }
    }
    return false;

}

bool device::estaseleccionado(string objeto){
        if(seleccionado == objeto){
            return true;
        }

    return false;

}

void device::expandir(QTreeWidgetItem *objeto){
    expandidos.push_back(objeto->text(0).toStdString());


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



