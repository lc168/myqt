#include "chooselevelscene.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡场景");
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");

    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav", this);
    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &QPushButton::clicked, this , [=](){
        qDebug()<<"backBtn\n";
        emit this->chooseSceneBack();

    });



    //选择关卡的按钮
    for(int i = 0; i < 20; i++){

        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70, 130 + i/4 * 70);
        //menuBtn->setText(QString::number(i+1));
        connect(menuBtn, &MyPushButton::clicked, [=](){
            //播放音效
            chooseSound->play();

            qDebug()<<i;
            this->hide();
            play = new PlayScene(i+1);
            play->show();
            play->setGeometry(this->geometry());

            connect(play, &PlayScene::chooseSceneBack, this, [=](){
                this->show();
                play->hide();
                this->setGeometry(play->geometry());
                delete play;
                play = NULL;

            });
        });
        QLabel * label = new QLabel;
        label->setParent(this);
        //label->setParent(menuBtn);
        label->setFixedSize(menuBtn->width(), menuBtn->width());
        label->setText(QString::number(i+1));
        label->move(25 + i%4 * 70, 130 + i/4 * 70);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5 ,
                       30, pix.width(), pix.height(), pix);
}
