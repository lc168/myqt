#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>

QT_BEGIN_NAMESPACE
class Node;
QT_END_NAMESPACE

class Link : public QGraphicsLineItem
{
public:
    Link(Node *fromNode, Node *toNode);
    ~Link();

    Node *fromNode() const;
    Node *toNode() const;
    Node *myFromNode;
    Node *myToNode;

    void setColor(const QColor &color);
    QColor color() const;

    void trackNodes();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QPainterPath shape() const;
    QRectF boundingRect() const override;

    QPolygonF arrowPolygon;
private:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;


    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif
