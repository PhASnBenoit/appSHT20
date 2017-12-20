#include "ccapteur_i2c_sht20_nth.h"

CCapteur_I2c_SHT20_NTh::CCapteur_I2c_SHT20_NTh(QObject *parent) :
    QObject(parent)
{
    m_i2c = CI2c::getInstance(this, '1');
    connect(m_i2c, SIGNAL(sigErreur(QString)), this, SLOT(onErreur(QString)));
    qDebug() << "Objet CCapteur_I2c_SHT20_NTh créé !";
}

CCapteur_I2c_SHT20_NTh::~CCapteur_I2c_SHT20_NTh()
{
    CI2c::freeInstance();
    qDebug() << "Objet CCapteur_I2c_SHT20_NTh détruit !";
}


void CCapteur_I2c_SHT20_NTh::onErreur(QString mess)
{
    emit sigErreur(mess);
}

float CCapteur_I2c_SHT20_NTh::lireMesureHum()
{
    float hum;
    unsigned char lecture[3];
    unsigned char ecriture[1];
    int res;

    ecriture[0] = COM_MES_HUM;
    m_i2c->ecrire(ADR, ecriture, 1);
    usleep(100000);
    res=m_i2c->lire(ADR, lecture, 2);
    if (res != 2) {
        QString mess="CCapteur_I2c_SHT20_NTh::lireMesureHum ERREUR Lecture";
        emit sigErreur(mess);
        return -1;
    } // if res
    unsigned char MSB = lecture[0];
    unsigned char LSB = lecture[1]&0x03;
    hum=((MSB<<8)+LSB);
    hum = -6+125*hum/65536;
    return hum;
} // lireMesHum

float CCapteur_I2c_SHT20_NTh::lireMesureTemp()
{
    float temp;
    unsigned char lecture[2];
    unsigned char ecriture[1];
    int res;

    ecriture[0] = COM_MES_TEMP;
    m_i2c->ecrire(ADR, ecriture, 1);
    usleep(100000);
    res=m_i2c->lire(ADR, lecture, 2);
    if (res != 2) {
        QString mess="CCapteur_I2c_SHT20_NTh::lireMesureTemp ERREUR Lecture";
        emit sigErreur(mess);
        return -1;
     } // if res
    unsigned char MSB = lecture[0];
    unsigned char LSB = lecture[1]&0x03;
    temp = ((MSB<<8)+LSB);
    temp = -46.85+175.72*temp/65536;
    return temp;
} // lire MesTemp
