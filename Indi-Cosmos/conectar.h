#ifndef CONECTAR_H
#define CONECTAR_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class conectar;
}
/**
 *
 * @author eyehalcon97
 * Clase de elemento de nueva ventana en la que ponemos los datos del servidor y del puerto
 */
class conectar : public QDialog
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 */
    explicit conectar(MainWindow *parent = nullptr);
/**
 *
 * @brief Destructor por defecto
 */
    ~conectar();

/**
 *
 * @brief Devuelve el nombre del servidor
 * @return nombre
 */
    string getnombre();
/**
 *
 * @brief Devuelve el host del servidor
 * @return host
 */
    string gethost();
/**
 *
 * @brief Devuelve el numero del puerto del servidor
 * @return puerto
 */
    int getpuerto();
/**
 *
 * @brief Verifica que se han rellenado los campos host y nombre del servidor
 * 
 */
    void error();

private slots:

/**
 *
 * @brief funcion que se ejecuta cuando pulsamos el boton Cancelar
 * 
 */
    void on_cancelarbutton_clicked();

private:
    Ui::conectar *ui;
};

#endif // CONECTAR_H
