#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
     void   move(int x, int y){
         QWidget::move(x, y);
    }

signals:
    void move_signals(int x, int y);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
