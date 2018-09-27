#include "item.h"

Item::Item(QGraphicsRectItem *rectItem)
{
    this->rectItem = rectItem;
    this->pos = rectItem->pos();
}
