#include "conectar.h"
#include "ui_conectar.h"


conectar::conectar(MainWindow *parent) : QDialog(parent), ui(new Ui::conectar)
{
    MainWindow *padre = parent;

    ui->setupUi(this);
    ui->alertanombre->setVisible(false);
    ui->alertahost->setVisible(false);
    connect(ui->aceptarbutton, SIGNAL (clicked()), padre , SLOT (nuevodispositivo()));
}

conectar::~conectar()
{
    delete ui;
}


string conectar::getnombre(){
    return ui->nombretexto->toPlainText().toStdString();
}

string conectar::gethost(){
    return ui->hosttexto->toPlainText().toStdString();
}

void conectar::error(){
    if(ui->nombretexto->toPlainText().toStdString().empty()){
        ui->alertanombre->setVisible(true);
    }else{
        ui->alertanombre->setVisible(false);
    }
    if(ui->hosttexto->toPlainText().toStdString().empty()){
        ui->alertahost->setVisible(true);
    }else{
        ui->alertahost->setVisible(false);
    }
}

int conectar::getpuerto(){
    return ui->puertotexto->toPlainText().toInt();
}

void conectar::on_cancelarbutton_clicked()
{
    this->hide();
}

