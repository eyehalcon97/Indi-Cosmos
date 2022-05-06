#include "propiedad.h"
#include "ui_propiedad.h"
#include <string>

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

propiedad::propiedad(string device,string name,string group,string label,string hints,int state,int type,int perm,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent){
    this->parent= parent;
    this->device= device;
    this->name= name;
    this->group= group;
    this->label= label;
    this->hints= hints;
    this->state= state;
    this->type= type;
    this->perm= perm;
    this->rule= rule;
    this->access_token= access_token;
    this->version= version;
    this->hidden= hidden;


}
string propiedad::getname(){
    return string(name);
}
propiedad::propiedad(indigo_property *property,QWidget *parent){
    this->parent= parent;


    device= string(property->device);
    name = string(property->name);

    this->group= string(property->group);
    this->label= string(property->label);
    this->hints= string(property->hints);
    this->state= property->state;
    this->type= property->type;
    this->perm= property->perm;
    this->rule= property->rule;
    this->count = property->count;
    this->access_token= property->access_token;
    this->version= property->version;
    this->hidden= property->hidden;



    switch(type){
        case 1:
            itemstexto = new itemtexto*[count];
            for(int i=0;i<count;i++){
                itemstexto[i] = new itemtexto(property->items[i],this);
            }
        break;

        case 2:
            itemsnumero = new itemnumero*[count];
            for(int i=0;i<count;i++){
                itemsnumero[i] = new itemnumero(property->items[i],this);
            }
            break;
        case 3:
            itemsswitch = new itemswitch*[count];
            for(int i=0;i<count;i++){
                itemsswitch[i] = new itemswitch(property->items[i],this);
            }
            break;
        case 4:
            itemslight = new itemlight*[count];
            for(int i=0;i<count;i++){
                itemslight[i] = new itemlight(property->items[i],this);
            }
            break;
        case 5:
            itemsblob = new itemblob*[count];
            for(int i=0;i<count;i++){
                itemsblob[i] = new itemblob(property->items[i],this);
            }
            break;
    }

}

