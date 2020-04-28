#include "piece.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "food.h"
#include "field.h"
#include "snake.h"
#include <QTimer>
#include <QTransform>
#include <QLabel>
#include <iostream>
#include <string>
#include <typeinfo>
#include <QDebug>

piece::piece() {
  // connect
  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));
  timer->start(50);
}

piece::~piece() {}
