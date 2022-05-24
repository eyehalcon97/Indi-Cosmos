#ifndef FOTO_H
#define FOTO_H

#include <QWidget>
#include <string>

using namespace std;
namespace Ui {
class foto;
}
/**
 *
 * @author eyehalcon97
 * Clase que muestra una fotografia creada
 */
class foto : public QWidget
{
    Q_OBJECT

public:
/**
 *
 * @brief Constructor por defecto
 *
 *
 */
    explicit foto(QWidget *parent = nullptr);
/**
 *
 * @brief Constructor con ruta de la imagen
 * @param ruta ruta de la imagen a mostrar
 *
 *
 */
    foto(string ruta);
/**
 *
 * @brief Destructor por defecto
 *
 *
 */
    ~foto();

private slots:
/**
 *
 * @brief funcion que se ejecuta para cerrar la ventana
 *
 *
 */
    void on_pushButton_clicked();

private:
    Ui::foto *ui;
    string ruta;
};

#endif // FOTO_H
