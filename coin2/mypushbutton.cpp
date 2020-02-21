#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QPushButton *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片的固定大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则的图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图片大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}

void MyPushButton::zoom1()
{
   //创建的动画对象
   QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
   //设置动画的时间间隔
   animation->setDuration(200);

   animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
   animation->setEndValue(QRect(this->x(), this->y()+30, this->width(), this->height()));
   //设置弹跳曲线
   animation->setEasingCurve(QEasingCurve::OutBounce);

   animation->start();
}

void MyPushButton::zoom2()
{
    //创建的动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);

    animation->setStartValue(QRect(this->x(), this->y()+30, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
   // qDebug()<<"PressEvent";
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret){
            qDebug()<<"图片加载失败:"<< pressImgPath;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
   // qDebug()<<"RelessEvent";
    if(this->normalImgPath != ""){
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret){
            qDebug()<<"图片加载失败:"<< normalImgPath;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

    }
   return QPushButton::mouseReleaseEvent(e);
}
