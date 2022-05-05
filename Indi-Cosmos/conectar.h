#ifndef CONECTAR_H
#define CONECTAR_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class conectar;
}

class conectar : public QDialog
{
    Q_OBJECT

public:
    explicit conectar(MainWindow *parent = nullptr);
    ~conectar();
    string hola="localhost";
    string getnombre();
    string gethost();
    int getpuerto();
    void error();

private slots:


    void on_cancelarbutton_clicked();

private:
    Ui::conectar *ui;
};

#endif // CONECTAR_H
