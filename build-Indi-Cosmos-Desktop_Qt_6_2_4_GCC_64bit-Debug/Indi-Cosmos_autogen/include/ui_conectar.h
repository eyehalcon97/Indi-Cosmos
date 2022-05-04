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
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_conectar
{
public:

    void setupUi(QFrame *conectar)
    {
        if (conectar->objectName().isEmpty())
            conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->resize(320, 240);

        retranslateUi(conectar);

        QMetaObject::connectSlotsByName(conectar);
    } // setupUi

    void retranslateUi(QFrame *conectar)
    {
        conectar->setWindowTitle(QCoreApplication::translate("conectar", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conectar: public Ui_conectar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONECTAR_H
