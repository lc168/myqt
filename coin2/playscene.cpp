#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QLabel>
#include <QString>
#include <mycoin.h>
#include <dataconfig.h>
#include <QPropertyAnimation>

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex = levelNum;

    //初始化游戏的场景
    //设置固定大小
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("游戏的主要场景");

    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");

    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &QPushButton::clicked, this , [=](){
        qDebug()<<"play is backBtn\n";
        emit this->chooseSceneBack();

    });

    //
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("Level:%1").arg(this->levelIndex));
    label->setGeometry(QRect(30, this->height() - 50, 120, 50));

    dataConfig config;
    for(int i = 0;i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片的显示
    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setPixmap(tmpPix);
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width())*0.5, -tmpPix.height());




    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel *label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i*50, 200 + j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j]){
                str = ":/res/Coin0001.png";
            }else {
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*50, 204 + j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            this->coinBtn[i][j] = coin;
            connect(coin, &MyCoin::clicked, this, [=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0?1:0;
                //翻转周围

                if(coin->posX + 1 <= 3){
                    coinBtn[coin->posX+1][coin->posY]->changeFlag();
                     this->gameArray[coin->posX+1][coin->posY] =
                        this->gameArray[coin->posX+1][coin->posY] == 0?1:0;
                }
                if(coin->posX - 1 >= 0){
                    coinBtn[coin->posX-1][coin->posY]->changeFlag();
                    this->gameArray[coin->posX-1][coin->posY] =
                        this->gameArray[coin->posX-1][coin->posY] == 0?1:0;
                }
                if(coin->posY + 1 <=3 ){
                    coinBtn[coin->posX][coin->posY+1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY+1] =
                        this->gameArray[coin->posX][coin->posY+1] == 0?1:0;
                }
                if(coin->posY - 1 >= 0 ){
                    coinBtn[coin->posX][coin->posY-1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY-1] =
                        this->gameArray[coin->posX][coin->posY-1] == 0?1:0;
                }

                //判断是否胜利
                int Win = 0;
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        Win += this->gameArray[i][j];
                    }
                }
                if(Win == 16){
                    qDebug()<<"Win!";
                     winLabel->move((this->width() - tmpPix.width())*0.5, -tmpPix.height());
                    //讲胜利的图片，调用下来
                    QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
                    //设置间隔时间
                    animation->setDuration(1000);
                    //设置开始位置
                    animation->setStartValue(QRect(winLabel->x(), winLabel->y(),
                                                   winLabel->width(), winLabel->height()));
                    //设置结束位置
                    animation->setEndValue(QRect(winLabel->x(), winLabel->y()+114,
                                                   winLabel->width(), winLabel->height()));
                    //设置曲线
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->start();
                }
            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
