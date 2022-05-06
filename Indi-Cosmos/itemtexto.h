#ifndef itemTEXTO_H
#define itemTEXTO_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;

namespace Ui {
class itemtexto;
}

class itemtexto : public QWidget
{
    Q_OBJECT

public:
    explicit itemtexto(QWidget *parent = nullptr);
    ~itemtexto();
    itemtexto(string nombre,string etiqueta,string gui,string value,string long_value,long length,QWidget *parent = nullptr);
    itemtexto(indigo_item *item,QWidget *parent = nullptr);
private:
    Ui::itemtexto *ui;
    string name;
    string label;
    string hints;
    QWidget* padre;
    string value;  ///< item value (for text properties)
    string long_value;	///< item value, set if text is longer than NDIGO_VALUE_SIZE
    long length;
};

#endif // itemTEXTO_H
