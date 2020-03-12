#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Widget)
{
    ui->setupUi(this);
   // connect(this,SIGNAL(move_signals(int , int )), this, SLOT(move(int , int)));
    ui->pushButton->setWindowState(Qt::WindowFullScreen);
   // ui->pushButton->setText("good!");

}

Widget::~Widget()
{
    delete ui;
}

