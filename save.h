#ifndef SAVE_H
#define SAVE_H
#include <QtWidgets/QMainWindow>
#include <QGraphicsItem>
#include <item.h>
class save
{
public slots:
    void SaveNow(QPointF playerPos, int points, QList<Item> itemList);
public:
    save();
    QPointF playerPos;
    int points;
    QList<Item> itemList;
};

#endif // SAVE_H
