#ifndef itemSWITCH_H
#define itemSWITCH_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;



class itemswitch : public QWidget
{
    Q_OBJECT

public:
    explicit itemswitch(QWidget *parent = nullptr);
    ~itemswitch();
    itemswitch(string nombre,string etiqueta,string gui,bool valor,QWidget *parent =nullptr);
    itemswitch(indigo_item item,QWidget *parent = nullptr);
    string getname();
    bool getvalue();

private:

    string name;
    string label;
    string hints;
    QWidget* padre;
    bool value;
};

#endif // itemSWITCH_H
