#include "openlist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    openList w;
    w.show();

    return a.exec();
}
