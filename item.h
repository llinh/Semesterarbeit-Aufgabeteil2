#ifndef ITEM_H
#define ITEM_H
#include <QtWidgets/QMainWindow>

#include <QGraphicsItem>

class Item
{
public:
    Item(QGraphicsRectItem *rectItem);
    QPointF pos;
    QGraphicsRectItem *rectItem;
};

#endif // ITEM_H
