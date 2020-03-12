#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QPushButton>
#include "mythread.h"
//class myThread: public QThread
//{
//public:
//    Widget *w;
//    myThread(Widget *w){
//        this->w = w;
//    }
//    void run() override{

//        for(int i=0; i < 1000; i++){
//           //移动窗口
//         //  qDebug()<<"x="<<x;
//           msleep(50);
//           int x =  w->x();
//           int y =  w->y();
//           x = x+1;
//           y = y+1;
//           w->move_signals(x, y);
//        }
//    }
//};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    qDebug()<<w.geometry();

   // w.pushButton->setPa

    w.show();
    w.setWindowState(Qt::WindowFullScreen);
    w.setWindowState(Qt::WindowMaximized);
   // w.setGeometry(10, 10, 800, 600);
    myThread s(&w);
    s.start();



    //QObject::connect(&s, SIGNAL(Move(int ,int)), &w, SLOT(move(int , int)));
   // qDebug()<<w.geometry();
    return a.exec();
}
