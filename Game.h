#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "snake.h"
#include "wall.h"
#include "food.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void displayWelcome();
    QGraphicsScene * scene;
    snake * newSnake;

};

#endif // GAME_H
