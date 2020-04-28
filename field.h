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

public slots:
    //void spawn(int foodEaten);
    void updateFood(int newCount);
};

#endif
