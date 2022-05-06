#ifndef itemLIGHT_H
#define itemLIGHT_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;

namespace Ui {
class itemlight;
}

class itemlight : public QWidget
{
    Q_OBJECT

public:
    explicit itemlight(QWidget *parent = nullptr);
    ~itemlight();
    itemlight(string nombre,string etiqueta,string gui ,int valor,QWidget *parent =nullptr);
    itemlight(indigo_item *item,QWidget *parent = nullptr);

private:
    Ui::itemlight *ui;
    string name;
    string label;
    string hints;
    QWidget* padre;
    int value;    ///< item value (for light properties)
};

#endif // itemLIGHT_H
