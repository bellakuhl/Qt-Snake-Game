#include <QApplication>
#include <QGraphicsScene>
#include <QSignalMapper>
#include "snake.h"
#include "food.h"
#include <QGraphicsView>
#include <QTimer>
#include "field.h"
#include "snake.h"
#include "wall.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    // create rect item to put in scene
    snake * newSnake = new snake();
    Field * field = new Field();
    newSnake->setRect(0,0,5,10);
    scene->addItem(newSnake);
    scene->addItem(field);

    Wall * top = new Wall();
    top->setRect(0,0,700,20); // top part of wall
    scene->addItem(top);
    Wall * left = new Wall();
    left->setRect(0,0,20,700); // left part of wall
    scene->addItem(left);
    Wall * right = new Wall();
    right->setRect(680,0,20,700); // right part of wall
    scene->addItem(right);
    Wall * bottom = new Wall();
    bottom->setRect(0,680,700,20); // bottom part of wall
    scene->addItem(bottom);

    // make scene a 700x700 square
    scene->setSceneRect(0,0,700,700);
    // make rect focusable
    newSnake->setFlag(QGraphicsItem::ItemIsFocusable);
    newSnake->setFocus();
    // add view to scene
    QGraphicsView * view = new QGraphicsView(scene);
    newSnake->setPos(view->width()/2,view->height() - newSnake->rect().height());
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    QSignalMapper* signalMapper = new QSignalMapper (field) ;
    QTimer * timer = new QTimer();
    QObject::connect (timer, SIGNAL(timeout()), signalMapper, SLOT(map()));
    signalMapper -> setMapping (timer, newSnake->foodEaten) ;
    QObject::connect (signalMapper, SIGNAL(mapped(int)), field, SLOT(updateFood(int))) ;
    timer->start(2000);

    return app.exec();
}
