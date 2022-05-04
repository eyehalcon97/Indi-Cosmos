#include "conectar.h"
#include "ui_conectar.h"

conectar::conectar(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::conectar)
{
    ui->setupUi(this);
}

conectar::~conectar()
{
    delete ui;
}
