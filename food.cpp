#include "food.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

food::food(){
  setRect(0,0,5,5);
  setPos(x(),y());
}
