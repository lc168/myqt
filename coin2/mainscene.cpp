#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>
#include <QSound>

Mainscene::Mainscene(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::Mainscene)
{
ui->setupUi(this);
//配置住场景
//配置固定大小
setFixedSize(320,588);
//设置图标
setWindowIcon(QIcon(":/res/Coin0001.png"));
//设置标题
setWindowTitle("翻金币主场景");

//退出
connect(ui->actionquit, &QAction::triggered, [=](){
    this->close();
});

//准备开始按钮的音效
QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);

MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
startBtn->setParent(this);
startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

chooseScene = new ChooseLevelScene;

connect(startBtn, &MyPushButton::clicked, this, [=](){
    startBtn->zoom1();
    startBtn->zoom2();
    startSound->play();
    //进入到选择关卡的
    QTimer::singleShot(600, this, [=](){
        chooseScene->setGeometry(this->geometry());
        chooseScene->show();
        this->hide();

    });

});

connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
    QTimer::singleShot(600, this, [=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();//隐藏
        this->show();
    });

});

}


//重新paintEvent事件 画背景图片
void Mainscene::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画背景图标
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix);
}

Mainscene::~Mainscene()
{
delete ui;
}
