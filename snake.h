#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>

class snake: public QGraphicsRectItem{
public:
  void keyPressEvent(QKeyEvent * event);
};

#endif
