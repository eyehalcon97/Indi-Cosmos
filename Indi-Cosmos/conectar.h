#ifndef CONECTAR_H
#define CONECTAR_H

#include <QFrame>

namespace Ui {
class conectar;
}

class conectar : public QFrame
{
    Q_OBJECT

public:
    explicit conectar(QWidget *parent = nullptr);
    ~conectar();

private:
    Ui::conectar *ui;
};

#endif // CONECTAR_H
