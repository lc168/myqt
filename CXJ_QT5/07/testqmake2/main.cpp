#include <iostream>
#include <QWidget>
#include <QApplication>
#include <opencv2/highgui.hpp>

#include "form2.h"

using namespace std;
using namespace cv;
int main(int argc,char *argv[])
{

    namedWindow("opencv");

    QApplication a(argc,argv);
    QWidget w;
    Form2 f;
    f.show();
    w.show();

    cout<<"test for qmake"<<endl;
    a.exec();

    //getchar();
	return 0;
}
