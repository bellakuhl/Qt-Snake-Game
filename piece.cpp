#include "piece.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <iostream>
#include "Game.h"

extern Game * game;

piece::piece(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
  setPixmap(QPixmap(":/resources/images/mask.png"));
}

piece::~piece() {}
