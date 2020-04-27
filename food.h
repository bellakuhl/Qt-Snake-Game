#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsRectItem>
#include <QObject>

class food: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  food();
  ~food();
  int count = 0;
};

#endif
