#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "piece.h"
#include <iostream>
#include <string>
using namespace std;

class snake: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT // required Qobject macro
public:
  snake(QGraphicsItem * parent=0);
  ~snake();
  string direction;
  int score;
  int speed;
  void keyPressEvent(QKeyEvent * event);
public slots:
  void move();
};

#endif
