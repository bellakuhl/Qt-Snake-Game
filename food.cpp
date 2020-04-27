#include "food.h"
#include "field.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>

food::food(){
  int xpos, ypos;
  xpos = (int)(qrand() % 600);
  ypos = (int)(qrand() % 600);
  setRect(0,0,5,5);
  setPos(xpos,ypos);
}

food::~food() {}
