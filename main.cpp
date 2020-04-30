#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    game = new Game();
    game->show();
    /*QGraphicsScene * scene = new QGraphicsScene();
    displayWelcome();

    // make scene a 700x700 square
    scene->setSceneRect(0,0,700,700);
    //scene->setPos(350,350);

    // make rect focusable
    newSnake->setFlag(QGraphicsItem::ItemIsFocusable);
    newSnake->setFocus();
    // add view to scene
    QGraphicsView * view = new QGraphicsView(scene);
    newSnake->setPos(view->width()/2,view->height() - newSnake->rect().height());
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QPixmap bg(700, 700);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, 700, 700);
    view->setBackgroundBrush(QBrush(bg));

    view->setScene(scene);*/
    //view->show();
    /*QSignalMapper* signalMapper = new QSignalMapper (field) ;
    QTimer * timer = new QTimer();
    QObject::connect (timer, SIGNAL(timeout()), signalMapper, SLOT(map()));
    signalMapper -> setMapping (timer, newSnake->foodEaten) ;
    QObject::connect (signalMapper, SIGNAL(mapped(int)), field, SLOT(updateFood(int))) ;
    timer->start(2000);*/

    return app.exec();
}
