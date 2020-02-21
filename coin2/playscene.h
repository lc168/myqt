#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
Q_OBJECT
public:
//explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    int levelIndex; //内部的成员函数，记录关卡
    void paintEvent(QPaintEvent *);
    int gameArray[4][4];//二维数组，维持每一个管卡数量
    MyCoin *coinBtn[4][4];
signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
