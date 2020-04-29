#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include "field.h"
#include "piece.h"
#include <QTimer>
#include <QTransform>
#include <QLabel>
#include <iostream>
#include <string>
#include <typeinfo>
#include <QDebug>

string prev_dir;
int length = 0;
piece * pieces[900];

snake::snake() {
  this->direction = "up";
  this->rotated = false;
  this->score = 1;
  this->foodEaten = 0;
  // connect time to move
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
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
	  } /*else if (event->key() == Qt::Key_Space) { // food spawns when spacebar is pressed
		food * newfood = new food();
		scene()->addItem(newfood);
	  }*/
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
          //this->setRect(0,0,10,(this->score)*10);
          delete colliding_items[i];
          // food spawns when another is eaten
          food * newfood = new food();
    		  scene()->addItem(newfood);
    		  length++;
    		  pieces[length] = new piece();
    		  pieces[length]->setRect(0,0,10,10);
    		  scene()->addItem(pieces[length]);
          return;
      }
  }
  for (int i = length; i > 0; i--) {
  	if (i == 1) {
  	  pieces[length]->setPos(x(), y());
  	} else {
  	  pieces[length]->setPos(pieces[length - 1]->x(), pieces[length - 1]->y());
  	}
  }
  if (!this->direction.compare("up")) { // if direction is up
    setPos(x(), y()-this->score);
  } else if (!this->direction.compare("down")) {
    setPos(x(), y()+this->score);
  } else if (!this->direction.compare("left")) {
    setPos(x()-this->score,y());
  } else if (!this->direction.compare("right")) {
    setPos(x()+this->score,y());
  }
}
