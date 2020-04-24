#include <QApplication>
#include <QGraphicsScene>
#include "snake.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    // create rect item to put in scene
    snake * rect = new snake();
    rect->setRect(0,0,50,50);
    // add item to scene
    scene->addItem(rect);
    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // add view to scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    return app.exec();
}
