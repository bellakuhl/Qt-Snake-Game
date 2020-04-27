#include <QApplication>
#include <QGraphicsScene>
#include "snake.h"
#include "food.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    // create rect item to put in scene
    snake * newSnake = new snake();
    food * newFood = new food();
    newSnake->setRect(0,0,5,10);
    scene->addItem(newSnake);
    scene->setSceneRect(0,0,700,700);
    // make rect focusable
    newSnake->setFlag(QGraphicsItem::ItemIsFocusable);
    newSnake->setFocus();
    // add view to scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    newSnake->setPos(view->width()/2,view->height() - newSnake->rect().height());

    // spawn food randomly
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),newFood,SLOT(spawn()));
    timer->start(2000);
    return app.exec();
}
