#include "mainscene.h"
#include <QApplication>
//#include <QtWebView>
//#include <WebView>

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
Mainscene w;
w.show();
//WebView *view = new WebView();

//QtWebView  a;

return a.exec();
}
