#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ViewSig();
    connect(this, SIGNAL(Hide()), this, SLOT(hide()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ViewSlot()
{
    qDebug()<<"run ViewSlot";
}

