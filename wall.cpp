#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "wall.h"

Wall::Wall(){
  setRect(0,0,700,5);
}

Wall::~Wall() {}
