#include <QtWidgets>

#include "link.h"
#include "node.h"
#include <QDebug>
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Link::Link(Node *fromNode, Node *toNode)
{
    myFromNode = fromNode;
    myToNode = toNode;

    myFromNode->addLink(this);
    myToNode->addLink(this);

    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkRed);
    trackNodes();

  //  setFlags(ItemIsMovable | ItemIsSelectable| ItemSendsGeometryChanges);
     setFlags(ItemIsSelectable);
}

Link::~Link()
{
    myFromNode->removeLink(this);
    myToNode->removeLink(this);
}

Node *Link::fromNode() const
{
    return myFromNode;
}

Node *Link::toNode() const
{
    return myToNode;
}

void Link::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

QColor Link::color() const
{
    return pen().color();
}

void Link::trackNodes()
{
   // qDebug()<<"trackNodes";

    setLine(QLineF(myFromNode->pos(), myToNode->pos()));

    update();
}

void Link::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug()<<"paint ";
    //QPointF sourcePoint = myFromNode->pos() ;
   // QPointF destPoint = myToNode->pos();
    qreal arrowSize = 16.0;

    //QLineF line(sourcePoint,destPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line());

    // Draw the arrows
    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0)
        angle = TwoPi - angle;


    QPointF sourceArrowP1 = (line().p1()+line().p2())/2 + QPointF(sin(angle + Pi / 3) * arrowSize,
                                                  cos(angle + Pi / 3) * arrowSize);
    QPointF sourceArrowP2 = (line().p1()+line().p2())/2 + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                                  cos(angle + Pi - Pi / 3) * arrowSize);

    painter->setBrush(Qt::black);
    // painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
 //   QPolygonF arrowPolygon;
    arrowPolygon.clear();
    arrowPolygon << ((line().p1()+line().p2())/2) << sourceArrowP1 << sourceArrowP2;
    painter->drawPolygon(arrowPolygon);
    //painter->drawText(QPoint(0, 0), myFromNode->text());
    //painter->drawRoundedRect(boundingRect(), 0.1, 0.3, Qt::RelativeSize);
    //qDebug()<<boundingRect();
//    if (isSelected()) {
//        qDebug()<<"isSelected is good!";
//    } else {
//        qDebug()<<"no isSelected is good!";
//    }
}

QRectF Link::boundingRect() const
{
    qreal extra = 3;
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

void Link::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mousedouble";
    Node * temp =  myToNode;
    myToNode = myFromNode;
    myFromNode = temp;
    update();
    myFromNode->update();
    myToNode->update();
}


QPainterPath Link::shape() const
{
    QPainterPath path  = QGraphicsLineItem::shape();
//    QRectF rect = QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
//                               line().p2().y() - line().p1().y())).normalized();
    path.addPolygon(arrowPolygon);
    return path;
}


