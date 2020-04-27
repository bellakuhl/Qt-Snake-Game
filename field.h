#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsRectItem>
#include <QObject>
#include "wall.h"
#include "snake.h"

class Field: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  Field();
  ~Field();
  int food_count = 0;
  //snake * newSnake;
  /*Wall * top;
  Wall * left;
  Wall * right;
  Wall * bottom;*/
public slots:
    void spawn();
    void updateFood(int newCount);
};

#endif
