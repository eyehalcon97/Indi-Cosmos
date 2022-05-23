#include "foto.h"
#include "ui_foto.h"
#include <string>
#include <QPalette>
#include <QtWidgets>
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>
using namespace std;
foto::foto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::foto)
{
    ui->setupUi(this);
}
foto::foto(string ruta):ui(new Ui::foto){
    ui->setupUi(this);

    this->ruta = "./" + ruta;
    indigo_log(this->ruta.c_str());

    QPixmap pixmap(QString::fromStdString(this->ruta));
    ui->label->setPixmap(pixmap);


}

foto::~foto()
{
    delete ui;
}

void foto::on_pushButton_clicked()
{
    this->hide();
}

