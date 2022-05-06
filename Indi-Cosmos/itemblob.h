#ifndef itemBLOB_H
#define itemBLOB_H

#include <QWidget>
#include <string>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;
namespace Ui {
class itemblob;
}

class itemblob : public QWidget
{
    Q_OBJECT

public:
    explicit itemblob(QWidget *parent = nullptr);
    ~itemblob();
    itemblob(string nombre,string etiqueta,string gui,string formato,string url,long size,void *value,QWidget *parent =nullptr);
    itemblob(indigo_item item,QWidget *parent = nullptr);

private:
    Ui::itemblob *ui;
    string name;
    string label;
    string hints;
    QWidget* padre;
    string formato;
    string url;
    long size;
    void *value;
};

#endif // itemBLOB_H
