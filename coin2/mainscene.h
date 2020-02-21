#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"

namespace Ui {
class Mainscene;
}

class Mainscene : public QMainWindow
{
Q_OBJECT

public:
explicit Mainscene(QWidget *parent = nullptr);
~Mainscene();

//重新paintEvent事件 画背景图片
void paintEvent(QPaintEvent *);
ChooseLevelScene *chooseScene = NULL;
private:
Ui::Mainscene *ui;
};

#endif // MAINSCENE_H
