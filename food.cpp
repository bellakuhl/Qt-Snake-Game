#include "food.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <iostream>

food::food(){
  int xpos, ypos;
  xpos = (int)(qrand() % 500);
  ypos = (int)(qrand() % 700);
  setRect(0,0,5,5);
  setPos(xpos,ypos);
}

food::~food() {

}
