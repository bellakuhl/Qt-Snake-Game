#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsRectItem>
#include <QObject>
#include "wall.h"

class Field: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  Field();
  ~Field();
  int food_count = 0;
  Wall * top = new Wall();
  Wall * left = new Wall();
  Wall * right = new Wall();
  Wall * bottom = new Wall();
  public slots:
    void spawn();
};

#endif
