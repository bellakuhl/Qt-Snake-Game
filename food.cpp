#include "food.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "Game.h"

extern Game * game;

food::food(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
  setPixmap(QPixmap(":/resources/images/covid.png"));
  count = 0;
  int xpos, ypos;
  xpos = (int)(qrand() % 600);
  ypos = (int)(qrand() % 600);
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
