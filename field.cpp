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
#include <QDebug>

Field::Field() {
  food_count = 0;
}

Field::~Field() {}

void Field::updateFood(int foodEaten) {
  //this->food_count = newSnake->food_count;
  //qDebug() << foodEaten;
  if (this->food_count - foodEaten < 3) { // only make new food if there are less than 3 on the screen
    food * newFood = new food();
    scene()->addItem(newFood);
    this->food_count++;
  }
}

/*void Field::updateFood(int newCount) {
  if ()
  this->food_count = newCount;
}*/
