#ifndef FOTO_H
#define FOTO_H

#include <QWidget>
#include <string>

using namespace std;
namespace Ui {
class foto;
}

class foto : public QWidget
{
    Q_OBJECT

public:
    explicit foto(QWidget *parent = nullptr);
    foto(string ruta);
    ~foto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::foto *ui;
    string ruta;
};

#endif // FOTO_H
