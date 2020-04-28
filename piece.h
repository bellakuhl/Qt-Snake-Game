#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <iostream>
#include <string>

using namespace std;

class piece: public QObject, public QGraphicsRectItem {
  Q_OBJECT // required Qobject macro
public:
  piece();
  ~piece();
};


#endif
