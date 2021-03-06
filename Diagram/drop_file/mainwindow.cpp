#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDragEnterEvent>
#include <QDesktopServices>
#include<QMimeData>
#include <QDropEvent>
#include <QDragLeaveEvent>

#include <QDebug>
#include <QUrl>

#include <QDir>
#include <QFile>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    setAcceptDrops(true);//启用放下操作
ui->setupUi(this);
}

MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    //qDebug()<<"dragEnterEvent:"<<event->mimeData()->urls().first();
    QString file = event->mimeData()->urls().first().path();
    file.replace(QRegExp("^/"), "");
    QDir dir = QDir(file);

  //  const QString namefile = "ssss";
    QFile  *myfile = new QFile(file);
    bool ret = myfile->rename("C:/Users/lc/Documents/work/QtProject/s2");

  //  bool ret = file.remove("");
   // bool ret = dir.rename("C:/Users/lc/Desktop/dabo.zip", "C:/Users/lc/Documents/work/QtProject/sss");
    qDebug()<<"file="<<file<<" ret="<<ret;
    //QDesktopServices::openUrl(event->mimeData()->urls().first());
//    //如果类型是jpg或者png才能接受拖动。
//    //这里的compare字符串比较函数，相等的时候返回0，所以要取反
//    if(!event->mimeData()->urls()[0].fileName().right(3).compare("jpg")
//        ){
//        event->acceptProposedAction();
//     }else{
//        event->ignore();//否则不接受鼠标事件
//     }
  //  QWidget::dragEnterEvent(event);
}

void MainWindow::dropEvent(QDropEvent *event){
    qDebug()<<"dropEvent";
//    constQMimeData *qm=event->mimeData();//获取MIMEData
//    QPixmapqp(qm->urls()[0].toLocalFile());//.toLocalFile()是获取拖动文件的本地路径。
//        ui->label->resize(qp.width(),qp.height());//让label大小契合图片实际大小
//    ui->label->setPixmap(qp);//显示图片
QWidget::dropEvent(event);
}
