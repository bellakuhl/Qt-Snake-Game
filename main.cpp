#include <QApplication>
#include <QGraphicsScene>
#include "snake.h"
#include "food.h"
#include <QGraphicsView>
#include <QTimer>
#include "field.h"
#include "wall.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    // create rect item to put in scene
    snake * newSnake = new snake();
    //food * newFood = new food();
    Field * field = new Field();
    newSnake->setRect(0,0,5,10);
    scene->addItem(newSnake);
    //scene->addItem(newFood);
    scene->addItem(field);

    /*Wall * top = new Wall();
    top->setRect(0,0,700,10); // top part of wall
    scene->addItem(top);
    Wall * left = new Wall();
    left->setRect(0,0,10,700); // left part of wall
    scene->addItem(left);
    Wall * right = new Wall();
    right->setRect(700,0,10,700); // right part of wall
    scene()->addItem(right);
    Wall * bottom = new Wall();
    bottom->setRect(0,-700,700,10); // bottom part of wall
    scene()->addItem(bottom);*/

    // make scene a 700x700 square
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

    return app.exec();
}
