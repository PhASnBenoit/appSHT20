#include "cihmappsht20.h"
#include "ui_cihmappsht20.h"

CIhmAppSHT20::CIhmAppSHT20(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmAppSHT20)
{
    ui->setupUi(this);
}

CIhmAppSHT20::~CIhmAppSHT20()
{
    delete ui;
}
