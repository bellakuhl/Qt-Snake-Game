#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include <QTimer>
#include <QTransform>
#include <iostream>
#include <string>

snake::snake() {
  // connect
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(30);
}

snake::~snake() {

}

void snake::keyPressEvent(QKeyEvent * event) {
  QRectF rect;
  foreach(QGraphicsItem* item, scene()->selectedItems()) {
    rect |= item->mapToScene(item->boundingRect()).boundingRect();
  }
  QPointF center = rect.center();
  QTransform t;
  t.rotate(90); // rotate 90 degrees
  t.translate(-center.x(), -center.y()); // rotate around item center

  if (event->key() == Qt::Key_Left) {
    if (pos().x() > 0)
    //setPos(x()-10, y());
    setRotation(rotation() + 90);
    if (!this->direction.compare("left")) { // if snake is already going left, it is now moving down
      this->direction = "down";
    } else if (!this->direction.compare("down")) {
      this->direction = "right";
    } else if (!this->direction.compare("right")) {
      this->direction = "up";
    }
  } else if (event->key() == Qt::Key_Right) {
      if (pos().x() + 5 < 700) // check that snake is within screen bounds
      setPos(x()+10, y());
      setRotation(rotation() - 90);
      this->direction = "right";
  } else if (event->key() == Qt::Key_Up) {
      if (pos().y() < 700)
      setPos(x(), y()-10);
      this->direction = "up";
  } else if (event->key() == Qt::Key_Down) {
     if (pos().y() > 0)
        setPos(x(), y()+10);
     this->direction = "down";
  } else if (event->key() == Qt::Key_Space) {
    food * newfood = new food();
    scene()->addItem(newfood);
  }
}

void snake::move() {
  if (!this->direction.compare("up")) { // if direction is up
    setPos(x(), y()-1);
  } else if (!this->direction.compare("down")) {
    setPos(x(), y()+1);
  } else if (!this->direction.compare("left")) {
    setPos(x()-1,y());
  } else if (!this->direction.compare("right")) {
    setPos(x()+1,y());
  }
}
