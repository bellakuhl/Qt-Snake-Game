#include "food.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "Game.h"
#include <time.h> // seed for random number

extern Game * game;

food::food(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
  srand(time(0));
  setPixmap(QPixmap(":/resources/images/covid.png"));
  count = 0;
  int xpos, ypos;
  xpos = (int)(rand() % 1020);
  ypos = (int)(rand() % 735);
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
