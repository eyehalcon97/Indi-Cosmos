/********************************************************************************
** Form generated from reading UI file 'conectar.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONECTAR_H
#define UI_CONECTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conectar
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *cancelarbutton;
    QPushButton *aceptarbutton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *nombretexto;
    QPlainTextEdit *hosttexto;
    QPlainTextEdit *puertotexto;
    QLabel *label_4;
    QWidget *alertanombre;
    QWidget *alertahost;

    void setupUi(QDialog *conectar)
    {
        if (conectar->objectName().isEmpty())
            conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->resize(320, 240);
        verticalLayout = new QVBoxLayout(conectar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(conectar);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 300, 220));
        cancelarbutton = new QPushButton(scrollAreaWidgetContents);
        cancelarbutton->setObjectName(QString::fromUtf8("cancelarbutton"));
        cancelarbutton->setGeometry(QRect(179, 181, 101, 31));
        aceptarbutton = new QPushButton(scrollAreaWidgetContents);
        aceptarbutton->setObjectName(QString::fromUtf8("aceptarbutton"));
        aceptarbutton->setGeometry(QRect(20, 181, 91, 31));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 40, 51, 21));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 51, 21));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 120, 57, 21));
        nombretexto = new QPlainTextEdit(scrollAreaWidgetContents);
        nombretexto->setObjectName(QString::fromUtf8("nombretexto"));
        nombretexto->setGeometry(QRect(60, 40, 201, 21));
        nombretexto->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        nombretexto->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        hosttexto = new QPlainTextEdit(scrollAreaWidgetContents);
        hosttexto->setObjectName(QString::fromUtf8("hosttexto"));
        hosttexto->setGeometry(QRect(60, 80, 201, 21));
        hosttexto->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        hosttexto->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        puertotexto = new QPlainTextEdit(scrollAreaWidgetContents);
        puertotexto->setObjectName(QString::fromUtf8("puertotexto"));
        puertotexto->setGeometry(QRect(160, 120, 111, 21));
        puertotexto->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        puertotexto->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 0, 111, 31));
        alertanombre = new QWidget(scrollAreaWidgetContents);
        alertanombre->setObjectName(QString::fromUtf8("alertanombre"));
        alertanombre->setGeometry(QRect(270, 40, 21, 21));
        alertanombre->setStyleSheet(QString::fromUtf8("image: url(:/Images/alerta.png);"));
        alertahost = new QWidget(scrollAreaWidgetContents);
        alertahost->setObjectName(QString::fromUtf8("alertahost"));
        alertahost->setGeometry(QRect(270, 80, 21, 21));
        alertahost->setStyleSheet(QString::fromUtf8("image: url(:/Images/alerta.png);"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(conectar);

        QMetaObject::connectSlotsByName(conectar);
    } // setupUi

    void retranslateUi(QDialog *conectar)
    {
        conectar->setWindowTitle(QCoreApplication::translate("conectar", "Dialog", nullptr));
        cancelarbutton->setText(QCoreApplication::translate("conectar", "Cancelar", nullptr));
        aceptarbutton->setText(QCoreApplication::translate("conectar", "Aceptar", nullptr));
        label->setText(QCoreApplication::translate("conectar", "Nombre:", nullptr));
        label_2->setText(QCoreApplication::translate("conectar", "Host:", nullptr));
        label_3->setText(QCoreApplication::translate("conectar", "Puerto:", nullptr));
        label_4->setText(QCoreApplication::translate("conectar", "Nuevo Dispositivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conectar: public Ui_conectar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONECTAR_H
