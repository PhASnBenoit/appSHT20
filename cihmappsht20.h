#ifndef CIHMAPPSHT20_H
#define CIHMAPPSHT20_H

#include <QMainWindow>

namespace Ui {
class CIhmAppSHT20;
}

class CIhmAppSHT20 : public QMainWindow
{
    Q_OBJECT

public:
    explicit CIhmAppSHT20(QWidget *parent = 0);
    ~CIhmAppSHT20();

private:
    Ui::CIhmAppSHT20 *ui;
};

#endif // CIHMAPPSHT20_H
