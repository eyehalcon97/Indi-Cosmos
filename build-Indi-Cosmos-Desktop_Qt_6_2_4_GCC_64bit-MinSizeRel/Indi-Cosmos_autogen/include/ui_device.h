/********************************************************************************
** Form generated from reading UI file 'device.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_H
#define UI_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_device
{
public:
    QWidget *paneldevice;
    QGridLayout *gridLayout;
    QScrollArea *scrolltexto;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *texto_3;
    QScrollArea *scrollArea_2;
    QWidget *dibujo_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_16;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;

    void setupUi(QWidget *device)
    {
        if (device->objectName().isEmpty())
            device->setObjectName(QString::fromUtf8("device"));
        device->resize(560, 519);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(device->sizePolicy().hasHeightForWidth());
        device->setSizePolicy(sizePolicy);
        device->setMinimumSize(QSize(200, 200));
        device->setCursor(QCursor(Qt::ArrowCursor));
        device->setFocusPolicy(Qt::ClickFocus);
        paneldevice = new QWidget(device);
        paneldevice->setObjectName(QString::fromUtf8("paneldevice"));
        paneldevice->setGeometry(QRect(0, 0, 561, 521));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(paneldevice->sizePolicy().hasHeightForWidth());
        paneldevice->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(paneldevice);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrolltexto = new QScrollArea(paneldevice);
        scrolltexto->setObjectName(QString::fromUtf8("scrolltexto"));
        sizePolicy.setHeightForWidth(scrolltexto->sizePolicy().hasHeightForWidth());
        scrolltexto->setSizePolicy(sizePolicy);
        scrolltexto->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 541, 246));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents_3->setCursor(QCursor(Qt::IBeamCursor));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        texto_3 = new QTextBrowser(scrollAreaWidgetContents_3);
        texto_3->setObjectName(QString::fromUtf8("texto_3"));
        texto_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        horizontalLayout_3->addWidget(texto_3);

        scrolltexto->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(scrolltexto, 1, 1, 1, 1);

        scrollArea_2 = new QScrollArea(paneldevice);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setWidgetResizable(true);
        dibujo_3 = new QWidget();
        dibujo_3->setObjectName(QString::fromUtf8("dibujo_3"));
        dibujo_3->setGeometry(QRect(0, 0, 541, 247));
        sizePolicy.setHeightForWidth(dibujo_3->sizePolicy().hasHeightForWidth());
        dibujo_3->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(dibujo_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_12 = new QPushButton(dibujo_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/Images/lentecuadrada.png);"));

        gridLayout_4->addWidget(pushButton_12, 1, 0, 2, 1);

        pushButton_13 = new QPushButton(dibujo_3);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_4->addWidget(pushButton_13, 3, 0, 2, 1);

        pushButton_16 = new QPushButton(dibujo_3);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_4->addWidget(pushButton_16, 1, 2, 2, 1);

        pushButton_14 = new QPushButton(dibujo_3);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_14->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_4->addWidget(pushButton_14, 3, 2, 2, 1);

        pushButton_15 = new QPushButton(dibujo_3);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_15->setStyleSheet(QString::fromUtf8("image: url(:/Images/Monturacuadrada.png);"));

        gridLayout_4->addWidget(pushButton_15, 1, 1, 4, 1);

        scrollArea_2->setWidget(dibujo_3);

        gridLayout->addWidget(scrollArea_2, 0, 1, 1, 1);


        retranslateUi(device);

        QMetaObject::connectSlotsByName(device);
    } // setupUi

    void retranslateUi(QWidget *device)
    {
        device->setWindowTitle(QCoreApplication::translate("device", "Form", nullptr));
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_16->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class device: public Ui_device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_H
