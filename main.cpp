#include <QApplication>
#include <QGraphicsScene>
#include "snake.h"
#include "food.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    // create rect item to put in scene
    snake * rect = new snake();
    food * startFood = new food();
    rect->setRect(0,0,5,10);
    scene->addItem(rect);
    scene->addItem(startFood);
    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // add view to scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    return app.exec();
}
