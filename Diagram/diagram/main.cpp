#include <QApplication>

#include "diagramwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug()<<"liucheng good !";
    DiagramWindow view;
    view.show();
    return app.exec();
}
