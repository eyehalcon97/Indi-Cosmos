#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <QWidget>
#include <string>
#include "itemblob.h"
#include "itemlight.h"
#include "itemnumero.h"
#include "itemswitch.h"
#include "itemtexto.h"
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>

using namespace std;

namespace Ui {
class propiedad;
}

class propiedad : public QWidget
{
    Q_OBJECT

public:
    explicit propiedad(QWidget *parent = nullptr);
    ~propiedad();
    propiedad(string device,string name,string group,string label,string hints,int state,int type,int perm,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent =nullptr);
    propiedad(indigo_property *property,QWidget *parent = nullptr);

private:
    Ui::propiedad *ui;
    QWidget *parent;
    string device;
    string name;
    string group;
    string label;
    string hints;
    int state;
    int type;
    int perm;
    int rule;
    indigo_token access_token;
    short version;
    bool hidden;
    int count;
    itemblob** itemsblob;
    itemlight** itemslight;
    itemnumero** itemsnumero;
    itemswitch** itemsswitch;
    itemtexto** itemstexto;
};

#endif // PROPIEDAD_H

/*
            indigo_property* propiedad = devices[devicesseleccionados[i]]->getpropiedad(j);

            nombre = new QLabel;
            nombre->setText("Nombre de device");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->device);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("Nombre de la propiedad");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->name);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("Nombre del grupo");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->group);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("descripcion");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(propiedad->label);
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText("GUI");
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            nombre->setText(QString(propiedad->hints));
            layoutpropiedades->addWidget(nombre);


            nombre = new QLabel;
            nombre->setText(QString("valor luz"));
            layoutpropiedades->addWidget(nombre);

            nombre = new QLabel;
            if(propiedad->state == 0){
                nombre->setText("INDIGO_IDLE_STATE");
            }
            if(propiedad->state == 1){
                nombre->setText("INDIGO_OK_STATE");
            }
            if(propiedad->state == 2){
                nombre->setText("INDIGO_BUSY_STATE");
            }
            if(propiedad->state == 3){
               nombre->setText("INDIGO_ALERT_STATE");
            }
            layoutpropiedades->addWidget(nombre);
*/
