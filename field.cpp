#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "wall.h"
#include "snake.h"
#include "field.h"
#include "food.h"

Field::Field() {
  // spawn food randomly
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
  timer->start(2000);
}

Field::~Field() {}

void Field::spawn() {
  //this->food_count = newSnake->food_count;
  if (this->food_count < 3) { // only make new food if there are less than 3 on the screen
    food * newFood = new food();
    scene()->addItem(newFood);
    this->food_count++;
  }
}

void Field::updateFood(int newCount) {
  this->food_count = newCount;
}
