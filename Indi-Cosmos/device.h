#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
#include <string>
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
    void nuevapropiedad(indigo_property* propiedad);

    indigo_property* getpropiedad(int num);
    string getDeviceID();
    int getnpropiedades();
    QLayout *propiedadgeneral();

    QLayout *propiedadtexto();

    QLayout *propiedadnumero();

    QLayout *propiedadswitch();

    QLayout *propiedadluz();

    QLayout *propiedadblob();

    QLayout *getlayoutpropiedad();


private:
    Ui::device *ui;
    string deviceid;
    indigo_property* propiedades[100];
    int npropiedades=0;

};

#endif // DEVICE_H
