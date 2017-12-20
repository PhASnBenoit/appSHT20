#include "cihmappsht20.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CIhmAppSHT20 w;
    w.show();

    return a.exec();
}
