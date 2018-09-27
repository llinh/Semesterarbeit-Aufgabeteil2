#ifndef ITEM_H
#define ITEM_H
#include <QtWidgets/QMainWindow>

#include <QGraphicsItem>

class Item
{
public:
    Item(QGraphicsRectItem *rectItem);
    double x;
    double y;
    QGraphicsRectItem *rectItem;
};

#endif // ITEM_H
