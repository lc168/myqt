#include "mycoin.h"
#include <QDebug>

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("图片路径加载失败 %1").arg(btnImg);
        qDebug()<<str;
        return ;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    isAnimation = false;
//    connect(this, &QPushButton::clicked, this, [=](){
//        qDebug()<<"anjian";
//    });
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->min > 8){
            this->min = 1;
            timer1->stop();
            isAnimation = false;
        }
    });

    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->max < 1){
            this->max = 8;
            timer2->stop();
            isAnimation = false;
        }
    });
}

void MyCoin::changeFlag(){

    isAnimation = true;
    if(this->flag)
    {
        timer1->start(30);
        this->flag = false;

    } else {
        timer2->start(30);
        this->flag = true;

     }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation)
    {
        return;
    }else {
        QPushButton::mousePressEvent(e);
    }
}
