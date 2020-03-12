#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QWidget>
#include "widget.h"

class myThread: public QThread
{
    Q_OBJECT

public:
    Widget *w;
    myThread(Widget *w){
        this->w = w;
    }
    void run() override{

        for(int i=0; i < 1000; i++){
           //移动窗口
         //  qDebug()<<"x="<<x;
           msleep(50);
           int x =  w->x();
           int y =  w->y();
           x = x+1;
           y = y+1;
          // w->move_signals(x, y);
            Move(x, y);
        }
    }
    ~myThread(){
        terminate();
    }
signals:
       void Move(int , int);
};

#endif // MYTHREAD_H
