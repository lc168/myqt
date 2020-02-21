#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
Q_OBJECT
public:
//explicit MyPushButton(QPushButton *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;
    //弹跳特效
    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
