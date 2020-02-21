#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
Q_OBJECT
public:
explicit ChooseLevelScene(QWidget *parent = nullptr);
PlayScene *play = NULL;
//
void paintEvent(QPaintEvent *);
signals:
    //定义一个信号，告诉主场景,点击了返回
    void chooseSceneBack();
    //游戏场景对象的指针

public slots:
};

#endif // CHOOSELEVELSCENE_H
