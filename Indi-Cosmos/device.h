#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>

namespace Ui {
class device;
}

class device : public QWidget
{
    Q_OBJECT

public:
    explicit device(QWidget *parent = nullptr,char* id = nullptr);

    ~device();
    void cambiartamanio(int altura,int anchura);
    void nuevapropiedad(indigo_property* propiedad);
    indigo_property* getpropiedad(int num);
    char* getDeviceID();
    int getnpropiedades();


private:
    Ui::device *ui;
    char* deviceid;
    indigo_property* propiedades[100];
    int npropiedades=0;

};

#endif // DEVICE_H
