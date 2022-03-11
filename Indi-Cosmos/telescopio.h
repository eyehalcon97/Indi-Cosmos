#ifndef TELESCOPIO_H
#define TELESCOPIO_H

#include <QWidget>

namespace Ui {
class telescopio;
}

class telescopio : public QWidget
{
    Q_OBJECT

public:
    explicit telescopio(QWidget *parent = nullptr);
    ~telescopio();

private:
    Ui::telescopio *ui;
};

#endif // TELESCOPIO_H
