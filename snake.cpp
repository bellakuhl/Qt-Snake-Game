#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include <QTimer>
#include <QTransform>
#include <QLabel>
#include <iostream>
#include <string>

string prev_dir;

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
