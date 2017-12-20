#ifndef CIHMAPPSHT20_H
#define CIHMAPPSHT20_H

#include <QMainWindow>
#include "ccapteur_i2c_sht20_nth.h"

namespace Ui {
class CIhmAppSHT20;
}

class CIhmAppSHT20 : public QMainWindow
{
    Q_OBJECT

public:
    explicit CIhmAppSHT20(QWidget *parent = 0);
    ~CIhmAppSHT20();

private slots:
    void on_pbTemp_clicked();
    void on_pbHum_clicked();
    void onErreur(QString mess);

private:
    Ui::CIhmAppSHT20 *ui;
    CCapteur_I2c_SHT20_NTh *m_sht20;
};

#endif // CIHMAPPSHT20_H
