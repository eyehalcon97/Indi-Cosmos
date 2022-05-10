#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
#include "propiedad.h"
#include <QVBoxLayout>
using namespace std;
namespace Ui {
class device;
}

class device : public QWidget
{
    Q_OBJECT

public:
    explicit device(QWidget *parent = nullptr,string id = nullptr);

    ~device();
    void cambiartamanio(int altura,int anchura);
    void nuevapropiedad(indigo_property* property);

    propiedad* getpropiedad(int num);
    string getDeviceID();
    int getnpropiedades();
    QVBoxLayout* mostrarpropiedades();



private:
    Ui::device *ui;
    string deviceid;
    propiedad* propiedades[130];
    int npropiedades=0;


};

#endif // DEVICE_H
