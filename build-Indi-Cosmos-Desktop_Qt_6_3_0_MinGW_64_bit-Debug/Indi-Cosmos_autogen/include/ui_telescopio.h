/********************************************************************************
** Form generated from reading UI file 'telescopio.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELESCOPIO_H
#define UI_TELESCOPIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_telescopio
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *telescopio)
    {
        if (telescopio->objectName().isEmpty())
            telescopio->setObjectName(QString::fromUtf8("telescopio"));
        telescopio->resize(474, 328);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(telescopio->sizePolicy().hasHeightForWidth());
        telescopio->setSizePolicy(sizePolicy);
        telescopio->setMinimumSize(QSize(0, 200));
        gridLayout = new QGridLayout(telescopio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(telescopio);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(telescopio);

        QMetaObject::connectSlotsByName(telescopio);
    } // setupUi

    void retranslateUi(QWidget *telescopio)
    {
        telescopio->setWindowTitle(QCoreApplication::translate("telescopio", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("telescopio", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class telescopio: public Ui_telescopio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELESCOPIO_H
