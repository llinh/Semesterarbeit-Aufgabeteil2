#include "item.h"

Item::Item(QGraphicsRectItem *rectItem)
{
    this->rectItem = rectItem;
    this->x = rectItem->pos().x();
    this->y = rectItem->pos().y();
}
