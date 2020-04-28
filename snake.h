#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <iostream>
#include <string>
using namespace std;

class snake: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  snake();
  ~snake();
  string direction = "up";
  bool rotated = false;
  int score = 1;
  int foodEaten = 0;
  void keyPressEvent(QKeyEvent * event);
public slots:
  void move();
};

#endif
