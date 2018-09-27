#include "save.h"

void save::SaveNow(QPointF playerPos, int points, QList<Item> itemList)
{
    this->playerPos = playerPos;
    this->points = points;
    this->itemList = itemList;
}
save::save(){}
