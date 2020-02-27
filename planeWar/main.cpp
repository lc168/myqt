#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"
#include <QDebug>

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
//注册外部的二进制资源文件
bool ret = QResource::registerResource(GAME_RES_PATH);
qDebug()<<"QResource:ret"<<ret;
MainScene w;
w.show();

return a.exec();
}
