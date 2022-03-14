/********************************************************************************
** Form generated from reading UI file 'telescopio.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELESCOPIO_H
#define UI_TELESCOPIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_telescopio
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrolltexto;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *texto;
    QScrollArea *scrollArea_2;
    QWidget *dibujo;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *telescopio)
    {
        if (telescopio->objectName().isEmpty())
            telescopio->setObjectName(QString::fromUtf8("telescopio"));
        telescopio->resize(556, 521);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(telescopio->sizePolicy().hasHeightForWidth());
        telescopio->setSizePolicy(sizePolicy);
        telescopio->setMinimumSize(QSize(200, 200));
        telescopio->setCursor(QCursor(Qt::PointingHandCursor));
        telescopio->setFocusPolicy(Qt::ClickFocus);
        gridLayout = new QGridLayout(telescopio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrolltexto = new QScrollArea(telescopio);
        scrolltexto->setObjectName(QString::fromUtf8("scrolltexto"));
        sizePolicy.setHeightForWidth(scrolltexto->sizePolicy().hasHeightForWidth());
        scrolltexto->setSizePolicy(sizePolicy);
        scrolltexto->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 536, 246));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        texto = new QTextBrowser(scrollAreaWidgetContents);
        texto->setObjectName(QString::fromUtf8("texto"));

        horizontalLayout->addWidget(texto);

        scrolltexto->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrolltexto, 1, 0, 1, 1);

        scrollArea_2 = new QScrollArea(telescopio);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setWidgetResizable(true);
        dibujo = new QWidget();
        dibujo->setObjectName(QString::fromUtf8("dibujo"));
        dibujo->setGeometry(QRect(0, 0, 536, 247));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dibujo->sizePolicy().hasHeightForWidth());
        dibujo->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(dibujo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(dibujo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/Images/lentecuadrada.png);"));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 2, 1);

        pushButton = new QPushButton(dibujo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_2->addWidget(pushButton, 2, 0, 2, 1);

        pushButton_4 = new QPushButton(dibujo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_2->addWidget(pushButton_4, 0, 2, 2, 1);

        pushButton_6 = new QPushButton(dibujo);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/Images/lentecuadrada.png);"));

        gridLayout_2->addWidget(pushButton_6, 2, 2, 2, 1);

        pushButton_7 = new QPushButton(dibujo);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setStyleSheet(QString::fromUtf8("image: url(:/Images/Monturacuadrada.png);"));

        gridLayout_2->addWidget(pushButton_7, 0, 1, 4, 1);

        scrollArea_2->setWidget(dibujo);

        gridLayout->addWidget(scrollArea_2, 0, 0, 1, 1);


        retranslateUi(telescopio);

        QMetaObject::connectSlotsByName(telescopio);
    } // setupUi

    void retranslateUi(QWidget *telescopio)
    {
        telescopio->setWindowTitle(QCoreApplication::translate("telescopio", "Form", nullptr));
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class telescopio: public Ui_telescopio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELESCOPIO_H
