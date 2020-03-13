#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(tr("Ctrl+x,a"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::A(QString s){
    static int a = 0;
    a++;
    qDebug()<<QString("a=%1").arg(a)<<s<<endl;
    qDebug()<<ui->label->text()<<endl;
    qDebug()<<ui->label->text()<<endl;
}

void Widget::H(QString s){
    static int a = 0;
    a++;
   // qDebug()<<QString("a=%1").arg(a)<<s<<endl;
   // qDebug()<<ui->label->text()<<endl;
    qDebug()<<ui->label->selectedText()<<endl;
}

void Widget::P(){
    static int a = 0;
    a++;
    qDebug()<<QString("a=%1").arg(a)<<endl;

}
