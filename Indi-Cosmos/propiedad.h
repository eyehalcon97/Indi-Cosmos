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
#include <QTreeWidgetItem>





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
    propiedad(string devicename,string name,string group,string label,string hints,int state,int type,int count,int rule,indigo_token access_token,short version,bool hidden,QWidget *parent = nullptr);
    propiedad(indigo_property *property,indigo_client *cliente,QWidget *parent = nullptr);
    string getname();
    string getgroup();
    QWidget **mostrarpropiedades();
    int getcount();
    int gettype();
    QVBoxLayout *getlayout();
    int getstate();
    vector<string> itemsname();
    vector<QWidget*> itemsWidgets();
    int buscartexto(string id);
    int buscarnumero(string id);
    void cambiartexto(string nameitem,string valornuevo);
    void cambiarnumero(string nameitem,double valornuevo);




private slots:
    void combobox_cambio(int index);
    void botontexto();
    void botonnumero();
    void on_pushButton_3_clicked();




private:
    Ui::propiedad *ui;

    string devicename;
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
    QWidget* padre;
    indigo_client *cliente;

    itemblob** itemsblob;
    itemlight** itemslight;
    itemnumero** itemsnumero;
    itemswitch** itemsswitch;
    itemtexto** itemstexto;
    QWidget **itemswidgets;












};

#endif // PROPIEDAD_H
