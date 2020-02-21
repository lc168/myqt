#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
Q_OBJECT
public:
//explicit MyCoin(QWidget *parent = nullptr);
    //参数表示传入的路径
    MyCoin(QString btnImg);
    int posX;
    int posY;
    bool flag;

    //
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int min = 1;
    int max = 8;

    bool isAnimation;
    //重写按下时间
    void mousePressEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYCOIN_H
