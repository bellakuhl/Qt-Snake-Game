#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "wall.h"
#include "field.h"
#include "food.h"

Field::Field() {
  top->setRect(0,-10,700,10); // top part of wall
  left->setRect(10,0,10,700); // left part of wall
  right->setRect(690,0,10,700); // right part of wall
  bottom->setRect(0,-690,700,10); // bottom part of wall
  food * newFood = new food();
  // spawn food randomly
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),newFood,SLOT(spawn()));
  timer->start(2000);
}

Field::~Field() {}

void Field::spawn() {
  if (this->food_count < 4) { // only make new food it there are less than 4 on the screen
    food * newFood = new food();
    //scene()->addItem(newFood);
    this->food_count++;
  }
}
