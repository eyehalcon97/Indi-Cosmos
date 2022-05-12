#ifndef itemTEXTO_H
#define itemTEXTO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;


class itemtexto : public QWidget
{
    Q_OBJECT

public:
    explicit itemtexto(QWidget *parent = nullptr);
    ~itemtexto();
    itemtexto(string nombre,string etiqueta,string gui,string value,QWidget *parent = nullptr);
    itemtexto(indigo_item item,QWidget *parent );
    void mostrarpropiedad();
    string getname();
    string getlabel();
    string getvalue();

private slots:
    void on_poner_clicked();

private:

    string name;
    string label;
    string hints;
    QWidget* padre;
    string value;  ///< item value (for text properties)
    QWidget widget;
};

#endif // itemTEXTO_H
