#include "telescopio.h"
#include "ui_telescopio.h"

telescopio::telescopio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::telescopio)
{
    ui->setupUi(this);
}

telescopio::~telescopio()
{
    delete ui;
}
