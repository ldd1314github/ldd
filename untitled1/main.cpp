#include "widget.h"
#include"point.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    MyWidget wi;
    wi.show();
    return a.exec();
}
