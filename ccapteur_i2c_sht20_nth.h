#ifndef CCAPTEUR_I2C_SHT20_NTH_H
#define CCAPTEUR_I2C_SHT20_NTH_H

#include <QObject>
#include <QThread>
#include "/home/pi/devQt/biblis/ci2c.h"

#define ADR 0x40 // 0x40 + bit LSB à 0 pour write
#define COM_MES_TEMP 0xf3
#define COM_MES_HUM 0xf5
#define COM_RESET 0xfe
#define COM_READ_REG 0xe7
#define COM_WRITE_REG 0xe6

class CCapteur_I2c_SHT20_NTh : public QObject
{
    Q_OBJECT

public:
    explicit CCapteur_I2c_SHT20_NTh(QObject *parent = 0);
    ~CCapteur_I2c_SHT20_NTh();
    float lireMesureHum();
    float lireMesureTemp();

private:
    CI2c *m_i2c;

signals:
    void sigErreur(QString mess);

private slots:
    void onErreur(QString mess);
};

#endif // CCAPTEURTEMPHUMI2C_H
