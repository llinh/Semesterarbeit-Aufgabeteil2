#include "gameplay.h"
#include "ui_gameplay.h"
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>
#include <QGraphicsItem>
Gameplay::Gameplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gameplay){

    ui->setupUi(this);
    // Setup UI Elemente
        endButton = new QPushButton("Ende", this);
        endButton->setGeometry(QRect(QPoint(20, 40), QSize(55, 25)));
        connect(endButton, SIGNAL(released()), this, SLOT(on_endButton_clicked()));

        startButton = new QPushButton("Start", this);
        startButton->setGeometry(QRect(QPoint(20, 80),QSize(55, 25)));
        connect(startButton, SIGNAL(released()), this, SLOT(on_startButton_clicked()));

        stopButton = new QPushButton("Stop", this);
        stopButton->setGeometry(QRect(QPoint(20, 120), QSize(55, 25)));
        connect(stopButton, SIGNAL(released()), this, SLOT(on_stopButton_clicked()));

        saveButton = new QPushButton("Speicher", this);
        saveButton->setGeometry(QRect(QPoint(20, 200), QSize(55, 25)));
        connect(saveButton, SIGNAL(released()), this, SLOT(on_saveButton_clicked()));

        loadButton = new QPushButton("Laden", this);
        loadButton->setGeometry(QRect(QPoint(20, 240), QSize(55, 25)));
        connect(loadButton, SIGNAL(released()), this, SLOT(on_loadButton_clicked()));

        graphicsView = new QGraphicsView(this);
        graphicsView->sizePolicy();

        graphicsView->setGeometry(QRect(QPoint(110, 60), QSize(800,600)));
        graphicsView->setFixedSize(QSize(800,600));
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scene = new QGraphicsScene(this);
        graphicsView->setScene(scene);

        QBrush greenBrush(Qt::green);
        greenBrush.setStyle(Qt::BrushStyle::BDiagPattern);
        QBrush redBrush(Qt::red);
            QPen outlinePen(Qt::black);
        outlinePen.setWidth(2);

        player = scene->addRect(graphicsView->width() / 2 - 25, graphicsView->height()-50, 50, 50, outlinePen, greenBrush);
        pointLabel = scene->addSimpleText("0");
        scene->addEllipse(graphicsView->width()-100, 50, 30, 30, outlinePen, redBrush);
        scene->addEllipse(graphicsView->width()-150, 50, 30, 30, outlinePen, redBrush);
        scene->addEllipse(graphicsView->width()-200, 50, 30, 30, outlinePen, redBrush);

        //ball->setPos(currentPos.rx() + 16, currentPos.ry());
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(iteration()));
        timer->start(25);

}


void Gameplay::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_A)
    {
        left = true;
    }

    if(e->key() == Qt::Key_D)
    {
        right = true;
    }
}

void Gameplay::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_A)
    {
        left = false;
    }

    if(e->key() == Qt::Key_D)
    {
        right = false;
    }
}


void Gameplay::on_startButton_clicked()
{
    paused = false;
}

void Gameplay::on_endButton_clicked()
{
}

void Gameplay::on_stopButton_clicked()
{
    paused = true;
}

void Gameplay::on_saveButton_clicked()
{
    save.SaveNow(player->pos(), points, itemList);
}

void Gameplay::on_loadButton_clicked()
{

    player->setPos(save.playerPos);
    points = save.points;



    itemList.clear();

    for( int i = 0; i < save.itemList.length(); i = i + 1 ) {
        if(save.itemList[i].rectItem != NULL)
        {
            QBrush blueBrush(Qt::blue);
            QPen outlinePen(Qt::black);
            QGraphicsRectItem * item = scene->addRect(save.itemList[i].x, save.itemList[i].y, 30, 30, outlinePen, blueBrush);
        }

    }

    for( int i = 0; i < itemList.length(); i = i + 1 ) {
        scene->removeItem(itemList[i].rectItem);
    }

    itemList = save.itemList;
}

void Gameplay::iteration()
{
    if (!timer->isActive()) { return;}

    if (!paused)
    {
        if(points % 25 == 0)
        {
            QBrush blueBrush(Qt::blue);
            QPen outlinePen(Qt::black);
            int pos = qRandomGenerator.bounded(1,9);
            QGraphicsRectItem * item = scene->addRect(100 * pos - 50, 0, 30, 30, outlinePen, blueBrush);
            itemList.append(item);
        }

        points++;
        pointLabel->setText(QString::number(points));
        int direction = 0;

        if(right)
        {
            direction += speed;
        }

        if(left)
        {
            direction -= speed;
        }

        QPointF currentPos = player->pos();

       player->setPos(currentPos.rx() + direction, currentPos.ry());


       for( int i = 0; i < itemList.length(); i = i + 1 ) {

           if(!itemList[i].rectItem == NULL)
           {
               currentPos = QPointF(itemList[i].x,itemList[i].y);
               itemList[i].rectItem->setPos(currentPos.rx(), currentPos.ry() + 5);
               itemList[i].x = itemList[i].rectItem->pos().x();
               itemList[i].y = itemList[i].rectItem->pos().y();
           }
       }

    }
}


