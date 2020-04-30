#include "food.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>

food::food(){
  count = 0;
  int xpos, ypos;
  xpos = (int)(qrand() % 600);
  ypos = (int)(qrand() % 600);
  setRect(0,0,30,30);
  setPos(xpos,ypos);
}

food::~food() {}

void food::spawn() {
  if (this->count < 4) { // only make new food it there are less than 4 on the screen
    food * newFood = new food();
    scene()->addItem(newFood);
    this->count++;
  }
}
