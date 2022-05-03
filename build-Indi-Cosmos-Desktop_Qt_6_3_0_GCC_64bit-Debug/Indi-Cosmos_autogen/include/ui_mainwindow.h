/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *boolpanelderecho;
    QAction *actionSalir;
    QAction *boolpanelsuperior;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *PanelSuperior;
    QSpinBox *Nobjetos;
    QLabel *label;
    QCheckBox *checkBox;
    QPushButton *Conectar;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *PanelPrincipal;
    QWidget *ScrollPanelPrincipal;
    QScrollArea *PanelDerecho;
    QWidget *propiedades;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuVer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setWindowTitle(QString::fromUtf8("Indi-Cosmos"));
        boolpanelderecho = new QAction(MainWindow);
        boolpanelderecho->setObjectName(QString::fromUtf8("boolpanelderecho"));
        boolpanelderecho->setCheckable(true);
        boolpanelderecho->setChecked(false);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        boolpanelsuperior = new QAction(MainWindow);
        boolpanelsuperior->setObjectName(QString::fromUtf8("boolpanelsuperior"));
        boolpanelsuperior->setCheckable(true);
        boolpanelsuperior->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        PanelSuperior = new QWidget(centralwidget);
        PanelSuperior->setObjectName(QString::fromUtf8("PanelSuperior"));
        PanelSuperior->setMinimumSize(QSize(80, 40));
        PanelSuperior->setMaximumSize(QSize(16777215, 40));
        Nobjetos = new QSpinBox(PanelSuperior);
        Nobjetos->setObjectName(QString::fromUtf8("Nobjetos"));
        Nobjetos->setGeometry(QRect(330, 19, 42, 21));
        label = new QLabel(PanelSuperior);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 0, 49, 16));
        checkBox = new QCheckBox(PanelSuperior);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(477, 10, 181, 22));
        Conectar = new QPushButton(PanelSuperior);
        Conectar->setObjectName(QString::fromUtf8("Conectar"));
        Conectar->setGeometry(QRect(40, 10, 80, 22));

        verticalLayout_2->addWidget(PanelSuperior);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PanelPrincipal = new QScrollArea(widget_2);
        PanelPrincipal->setObjectName(QString::fromUtf8("PanelPrincipal"));
        PanelPrincipal->setMouseTracking(false);
        PanelPrincipal->setWidgetResizable(true);
        PanelPrincipal->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        ScrollPanelPrincipal = new QWidget();
        ScrollPanelPrincipal->setObjectName(QString::fromUtf8("ScrollPanelPrincipal"));
        ScrollPanelPrincipal->setGeometry(QRect(0, 0, 556, 497));
        sizePolicy1.setHeightForWidth(ScrollPanelPrincipal->sizePolicy().hasHeightForWidth());
        ScrollPanelPrincipal->setSizePolicy(sizePolicy1);
        PanelPrincipal->setWidget(ScrollPanelPrincipal);

        horizontalLayout_2->addWidget(PanelPrincipal);

        PanelDerecho = new QScrollArea(widget_2);
        PanelDerecho->setObjectName(QString::fromUtf8("PanelDerecho"));
        PanelDerecho->setMinimumSize(QSize(0, 200));
        PanelDerecho->setMaximumSize(QSize(200, 16777215));
        PanelDerecho->setWidgetResizable(true);
        propiedades = new QWidget();
        propiedades->setObjectName(QString::fromUtf8("propiedades"));
        propiedades->setGeometry(QRect(0, 0, 198, 497));
        PanelDerecho->setWidget(propiedades);

        horizontalLayout_2->addWidget(PanelDerecho);


        verticalLayout_2->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuVer = new QMenu(menubar);
        menuVer->setObjectName(QString::fromUtf8("menuVer"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuVer->menuAction());
        menuMenu->addAction(actionSalir);
        menuVer->addAction(boolpanelderecho);
        menuVer->addAction(boolpanelsuperior);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        boolpanelderecho->setText(QCoreApplication::translate("MainWindow", "Panel derecho", nullptr));
#if QT_CONFIG(shortcut)
        boolpanelderecho->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
#if QT_CONFIG(shortcut)
        actionSalir->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        boolpanelsuperior->setText(QCoreApplication::translate("MainWindow", "Panel Superior", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Objetos", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Modo Seleccion Multiple", nullptr));
        Conectar->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuVer->setTitle(QCoreApplication::translate("MainWindow", "Ver", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
