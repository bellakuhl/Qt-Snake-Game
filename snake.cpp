#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include "field.h"
#include <QTimer>
#include <QTransform>
#include <QLabel>
#include <iostream>
#include <string>
#include <typeinfo>
#include <QDebug>

string prev_dir;

snake::snake() {
  // connect
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(50);
}

snake::~snake() {}

void snake::keyPressEvent(QKeyEvent * event) {
  QRectF rect;
  foreach(QGraphicsItem* item, scene()->selectedItems()) {
    rect |= item->mapToScene(item->boundingRect()).boundingRect();
  }
  QPointF center = rect.center();
  QTransform t;
  t.rotate(90); // rotate 90 degrees
  t.translate(-center.x(), -center.y()); // rotate around item center
  if ((pos().x() + 5 < 700) && (pos().x() > 0) && (pos().x() + 5 < 700) && (pos().x() > 0)) {
	  if (event->key() == Qt::Key_Left) {

		if (!this->direction.compare("up")) { // if snake is already going left, it is now moving down
		  setRotation(rotation() - 90);
		} else if (!this->direction.compare("down")) {
		  setRotation(rotation() + 90);
		}
		this->direction = "left";
	  } else if (event->key() == Qt::Key_Right) {
		  //setPos(x()+10, y());
		  if (!this->direction.compare("up")) { // if snake is already going left, it is now moving down
		  	setRotation(rotation() + 90);
	   	  } else if (!this->direction.compare("down")) {
		    setRotation(rotation() - 90);
		  }
		  this->direction = "right";
	  } else if (event->key() == Qt::Key_Up) {
		  //setPos(x(), y()-10);

		  if (!this->direction.compare("left")) { // if snake is already going left, it is now moving down
		  	setRotation(rotation() + 90);
	   	  } else if (!this->direction.compare("right")) {
		    setRotation(rotation() - 90);
		  }
		  this->direction = "up";
	  } else if (event->key() == Qt::Key_Down) {
		    //setPos(x(), y()+10);
		 if (!this->direction.compare("left")) { // if snake is already going left, it is now moving down
		  setRotation(rotation() - 90);
	   	 } else if (!this->direction.compare("right")) {
		   setRotation(rotation() + 90);
		 }
		 this->direction = "down";
	  } else if (event->key() == Qt::Key_Space) {
		food * newfood = new food();
		scene()->addItem(newfood);
	  }
  } else {
  	/*QLabel *label = new QLabel(this);
  	label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	label->setText("DEAD");
	label->setAlignment(Qt::AlignBottom | Qt::AlignRight);*/
  }
}

void snake::move() {
  // see if colliding
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i = 0, n = colliding_items.size(); i < n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(food)){
          // remove food
          scene()->removeItem(colliding_items[i]);
          // delete food
          this->score++;
          this->foodEaten++;
          qDebug() << this->foodEaten;
          this->setRect(0,0,5,(this->score)*10);
          delete colliding_items[i];
          return;
      }
  }
  if (pos().y() + rect().height() < 0) {
    scene()->removeItem(this);
    delete this;
  } else if (!this->direction.compare("up")) { // if direction is up
    setPos(x(), y()-this->score);
  } else if (!this->direction.compare("down")) {
    setPos(x(), y()+this->score);
  } else if (!this->direction.compare("left")) {
    setPos(x()-this->score,y());
  } else if (!this->direction.compare("right")) {
    setPos(x()+this->score,y());
  }
}
