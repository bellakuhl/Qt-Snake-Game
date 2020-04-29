#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QObject>
#include "piece.h"
#include <iostream>
#include <string>
using namespace std;

class snake: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  snake();
  ~snake();
  string direction;
  bool rotated;
  int score;
  int foodEaten;
  void keyPressEvent(QKeyEvent * event);
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
public slots:
  void move();
};

#endif
