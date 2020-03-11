#include "widget.h"

#include <QApplication>
#include <QThread>
#include <QDebug>

class MyThread: public QThread
{
public:
    Widget *w;
    MyThread(Widget *w){

        this->w = w;
    }
    void run() override{
        msleep(3000);
        qDebug()<<"run Hide()";

        w->Hide();

    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    MyThread *s = new MyThread(&w);
    MyThread s2(&w);
    s->start();
    //s->run();
    w.show();
   // QThread::msleep(3000);
    return a.exec();
}
