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
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QPushButton>

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
    propiedad(string device,string name,string group,string label,string hints,int state,int type,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent =nullptr);
    propiedad(indigo_property *property,indigo_client *cliente,QWidget *parent = nullptr);
    string getname();
    QWidget **mostrarpropiedades();
    int getcount();
    int gettype();
    QVBoxLayout *getlayout();

private slots:

    void combobox_cambio(int index);




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
    int rule;
    indigo_token access_token;
    short version;
    bool hidden;
    int count;
    int perm;
    indigo_client *cliente;

    itemblob** itemsblob;
    itemlight** itemslight;
    itemnumero** itemsnumero;
    itemswitch** itemsswitch;
    itemtexto** itemstexto;
    QWidget **itemswidgets;












};

#endif // PROPIEDAD_H
