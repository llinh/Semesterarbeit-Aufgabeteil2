#include <QMainWindow>
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_gameplay.h"
#include <Qtimer>
#include <QGraphicsItem>
#include <Save.h>
#include <QKeyEvent>
#include <qrandom.h>
#include <item.h>

namespace Ui {
class Gameplay;
}

class Gameplay : public QMainWindow
{
Q_OBJECT
public:
Gameplay(QWidget *parent = Q_NULLPTR);
protected:
void keyPressEvent(QKeyEvent *e);
void keyReleaseEvent(QKeyEvent *e);
private slots:
void on_startButton_clicked();
void on_endButton_clicked();
void on_stopButton_clicked();
void on_saveButton_clicked();
void on_loadButton_clicked();
void iteration();

private:
    Ui::Gameplay *ui;
    QPushButton *startButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *endButton;
    QPushButton *stopButton;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QGraphicsRectItem *player;
    QGraphicsSimpleTextItem * pointLabel;
    QRandomGenerator qRandomGenerator;
    QList<Item> itemList;
    bool left = false;
    bool right = false;
    int speed = 8;
    int points = 0;
    QTimer *timer;
    save save;
    bool paused = true;
};


