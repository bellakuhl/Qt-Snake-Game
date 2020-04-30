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
int size = 30;

snake::snake(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
  setPixmap(QPixmap(":/resources/images/mask.png"));
  this->direction = "up";
  this->score = 1;
  this->speed = 10;
  // connect time to move
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(200);
}

snake::~snake() {}

void snake::keyPressEvent(QKeyEvent * event) {
  //if ((pos().x() + 5 < 700) && (pos().x() > 0) && (pos().x() + 5 < 700) && (pos().x() > 0)) {
	  if (event->key() == Qt::Key_Left && this->direction.compare("right")) {
  		this->direction = "left";
	  } else if (event->key() == Qt::Key_Right && this->direction.compare("left")) {
  		  this->direction = "right";
	  } else if (event->key() == Qt::Key_Up && this->direction.compare("down")) {
  		  this->direction = "up";
	  } else if (event->key() == Qt::Key_Down && this->direction.compare("up")) {
  		 this->direction = "down";
	  }
  //}
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
  /*for (int i = length; i > 0; i--) {
    if (i == 1) {
      // first segment of snake follows the head
      pieces[i]->setPos(x(), y());
    } else {
      // all other segments follow the segment in front
      pieces[i]->setPos(pieces[i - 1]->x(), pieces[i - 1]->y());
    }
  }*/
  if (!this->direction.compare("up")) { // if direction is up
    setPos(x(), y()-speed);
  } else if (!this->direction.compare("down")) {
    setPos(x(), y()+speed);
  } else if (!this->direction.compare("left")) {
    setPos(x()-speed,y());
  } else if (!this->direction.compare("right")) {
    setPos(x()+speed,y());
  }
  /* for (int i = length; i > 2; i--) {
        if (x() == pieces[i]->x() && y() == pieces[i]->y()) {
          QMessageBox msgBox;
          msgBox.setText("Game Over");
          msgBox.exec();
          scene()->clear();
        }
      }*/
  for (int i = length; i > 0; i--) {
    if (i == 1) {
      if (!this->direction.compare("up")) { // if direction is up
        pieces[i]->setPos(x(), y()+40);
      } else if (!this->direction.compare("down")) {
        pieces[i]->setPos(x(), y()-40);
      } else if (!this->direction.compare("left")) {
        pieces[i]->setPos(x()+40, y());
      } else if (!this->direction.compare("right")) {
        pieces[i]->setPos(x()-40, y());
      }
    } else {
      if (!this->direction.compare("up")) { // if direction is up
        pieces[i]->setPos(pieces[i - 1]->x(), pieces[i - 1]->y()+40); // use previous pieces position offset by size of piece (40)
      } else if (!this->direction.compare("down")) {
        pieces[i]->setPos(pieces[i - 1]->x(), pieces[i - 1]->y()-40);
      } else if (!this->direction.compare("left")) {
        pieces[i]->setPos(pieces[i - 1]->x()+40, pieces[i - 1]->y());
      } else if (!this->direction.compare("right")) {
        pieces[i]->setPos(pieces[i - 1]->x()-40, pieces[i - 1]->y());
      }
    }
  }

}
