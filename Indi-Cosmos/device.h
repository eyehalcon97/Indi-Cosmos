#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
#include "propiedad.h"
#include <QVBoxLayout>
#include <iostream>
#include <vector>
#include <QTreeWidget>


using namespace std;
namespace Ui {
class device;
}

class device : public QWidget
{
    Q_OBJECT

public:
    explicit device(string id,indigo_client *cliente, QWidget *parent = nullptr);

    ~device();
    void cambiartamanio(int altura,int anchura);
    void nuevapropiedad(indigo_property* property);
    void eliminarpropiedad(indigo_property* property);
    void cambiarpropiedad(indigo_property* property);

    propiedad* getpropiedad(int num);
    string getDeviceID();
    int getnpropiedades();
    QVBoxLayout* mostrarpropiedades();
    indigo_client *cliente;
    void clearLayout(QLayout* layout, bool deleteWidgets);


    public slots:

    void expandir( QTreeWidgetItem *objeto);
    void disminuir( QTreeWidgetItem *objeto);



private:
    int indexof(vector<string> lista,string value);
    bool estaexpandido(QTreeWidgetItem *objeto);
    Ui::device *ui;
    string deviceid;
    vector<propiedad*> propiedades;


    QTreeWidget *arbol= new QTreeWidget;

    vector<string>grupos;
    vector<QTreeWidgetItem*> raices;
    vector<string> expandidos;





};

#endif // DEVICE_H
