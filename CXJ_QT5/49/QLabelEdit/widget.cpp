#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(tr("Ctrl+x,a"));
    QPushButton *w2 = new QPushButton(this);
    QPushButton *w3 = new QPushButton(this);
    QPushButton *w4 = new QPushButton(this);
    QPushButton *w5 = new QPushButton(this);
    QPushButton *w6 = new QPushButton(this);

    ui->lineEdit->setInputMask("DDD.DDD;_");
    ui->lineEdit2->setInputMask("ddd.ddd;_");
   //w2->move(200, 200);
   // w2->resize(400,400);

   // w2->adjustSize();

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

void Widget::PositChange(int old, int New){
    qDebug()<<"old="<<old<<" new="<<New;
}
