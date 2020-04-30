#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class food: public QObject,public QGraphicsPixmapItem {
  Q_OBJECT // required Qobject macro
public:
  food(QGraphicsItem * parent=0);
  ~food();
  int count;
public slots:
  void spawn();
};

#endif
