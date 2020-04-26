#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include <QTimer>

snake::snake() {
  // connect
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(50);
}

snake::~snake() {

}

void snake::keyPressEvent(QKeyEvent * event) {
  if (event->key() == Qt::Key_Left) {
    if (pos().x() > 0)
    setPos(x()-10, y());
  } else if (event->key() == Qt::Key_Right) {
      if (pos().x() + 5 < 800)
      setPos(x()+10, y());
  } else if (event->key() == Qt::Key_Up) {
      setPos(x(), y()-10);
  } else if (event->key() == Qt::Key_Down) {
      setPos(x(), y()+10);
  } else if (event->key() == Qt::Key_Space) {
    food * newfood = new food();
    scene()->addItem(newfood);
  }
}

void snake::move() {
  if (pos().y() > 0)
  setPos(x(), y()-5);
}
