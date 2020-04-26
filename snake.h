#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QObject>

class snake: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  snake();
  ~snake();
  void keyPressEvent(QKeyEvent * event);
public slots:
  void move();
};

#endif
