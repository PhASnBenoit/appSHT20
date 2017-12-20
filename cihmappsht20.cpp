#include "cihmappsht20.h"
#include "ui_cihmappsht20.h"

CIhmAppSHT20::CIhmAppSHT20(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmAppSHT20)
{
    ui->setupUi(this);
    m_sht20 = new CCapteur_I2c_SHT20_NTh(this);
    connect(m_sht20, SIGNAL(sigErreur(QString)), this, SLOT(onErreur(QString)));
}

CIhmAppSHT20::~CIhmAppSHT20()
{
    delete m_sht20;
    delete ui;
}

void CIhmAppSHT20::on_pbTemp_clicked()
{
   float mesure;
   mesure = m_sht20->lireMesureTemp();
   onErreur("Température : "+QString::number(mesure, 'f',1)+" °C");
}

void CIhmAppSHT20::on_pbHum_clicked()
{
    float mesure;
    mesure = m_sht20->lireMesureHum();
    onErreur("Humidité : "+QString::number(mesure, 'f',1)+" %RH");

}

void CIhmAppSHT20::onErreur(QString mess)
{
    ui->textEdit->append(mess);
}
