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
#include <qmessagebox.h>

string prev_dir;
int length = 0;
piece * pieces[900];

snake::snake() {
  this->direction = "up";
  this->rotated = false;
  this->score = 1;
  this->speed = 2;
  // connect time to move
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(50);
}

snake::~snake() {}

void snake::keyPressEvent(QKeyEvent * event) {
  if ((pos().x() + 5 < 700) && (pos().x() > 0) && (pos().x() + 5 < 700) && (pos().x() > 0)) {
	  if (event->key() == Qt::Key_Left && this->direction.compare("right")) {
  		this->direction = "left";
	  } else if (event->key() == Qt::Key_Right && this->direction.compare("left")) {
  		  this->direction = "right";
	  } else if (event->key() == Qt::Key_Up && this->direction.compare("down")) {
  		  this->direction = "up";
	  } else if (event->key() == Qt::Key_Down && this->direction.compare("up")) {
  		 this->direction = "down";
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
          delete colliding_items[i];
          // food spawns when another is eaten
          food * newfood = new food();
    		  scene()->addItem(newfood);
    		  length++;
          speed += this->score%2;
    		  pieces[length] = new piece();
    		  pieces[length]->setRect(0,0,10,10);
          pieces[length]->setPos(x(),y());
    		  scene()->addItem(pieces[length]);
          return;
      } else if (typeid(*(colliding_items[i])) == typeid(Wall)) {
        QMessageBox msgBox;
        msgBox.setText("Game Over");
        msgBox.exec();
        scene()->clear();
      }
  }
  if (!this->direction.compare("up")) { // if direction is up
    setPos(x(), y()-speed);
  } else if (!this->direction.compare("down")) {
    setPos(x(), y()+speed);
  } else if (!this->direction.compare("left")) {
    setPos(x()-speed,y());
  } else if (!this->direction.compare("right")) {
    setPos(x()+speed,y());
  }
  for (int i = length; i > 0; i--) {
    if (i == 1) {
      if (!this->direction.compare("up")) { // if direction is up
        pieces[i]->setPos(x(), y()+10);
      } else if (!this->direction.compare("down")) {
        pieces[i]->setPos(x(), y()-10);
      } else if (!this->direction.compare("left")) {
        pieces[i]->setPos(x()+10, y());
      } else if (!this->direction.compare("right")) {
        pieces[i]->setPos(x()-10, y());
      }
    } else {
      if (!this->direction.compare("up")) { // if direction is up
        pieces[i]->setPos(pieces[i - 1]->x(), pieces[i - 1]->y()+10); // use previous pieces position offset by size of piece (10)
      } else if (!this->direction.compare("down")) {
        pieces[i]->setPos(pieces[i - 1]->x(), pieces[i - 1]->y()-10);
      } else if (!this->direction.compare("left")) {
        pieces[i]->setPos(pieces[i - 1]->x()+10, pieces[i - 1]->y());
      } else if (!this->direction.compare("right")) {
        pieces[i]->setPos(pieces[i - 1]->x()-10, pieces[i - 1]->y());
      }
    }
  }
}
