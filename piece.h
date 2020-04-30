#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class piece: public QObject,public QGraphicsPixmapItem {
  Q_OBJECT // required Qobject macro
public:
  piece(QGraphicsItem * parent=0);
  ~piece();
};


#endif
