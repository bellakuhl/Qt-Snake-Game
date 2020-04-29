#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <qmessagebox.h>
#include <QIcon>
#include <QPushButton>
#include <QImage>
#include <QFont>
#include "snake.h"
#include "wall.h"

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    displayWelcome();
    scene->setSceneRect(0,0,1000,725); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/resources/images/world.jpg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,725);

    Wall * top = new Wall();
    top->setRect(0,0,700,20); // top part of wall
    scene->addItem(top);
    Wall * left = new Wall();
    left->setRect(0,0,20,700); // left part of wall
    scene->addItem(left);
    Wall * right = new Wall();
    right->setRect(680,0,20,700); // right part of wall
    scene->addItem(right);
    Wall * bottom = new Wall();
    bottom->setRect(0,680,700,20); // bottom part of wall
    scene->addItem(bottom);

    // create the food
    for (int i = 0; i < 3; i++) {
      food * newFood = new food();
      scene->addItem(newFood);
    }
    // create the snake
    newSnake = new snake();
    newSnake->setPos(350,350); // start in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    newSnake->setFlag(QGraphicsItem::ItemIsFocusable);
    newSnake->setFocus();
    // add the player to the scene
    scene->addItem(newSnake);
    show();
}

void Game::displayWelcome() {
  QMessageBox msgBox;
  msgBox.setText("Welcome to Qt Snake");
  msgBox.setInformativeText("Would you like to play?");
  QPushButton *connectButton = msgBox.addButton("YES!", QMessageBox::ActionRole);
  QPushButton *abortButton = msgBox.addButton("Nah", QMessageBox::ActionRole);

  msgBox.exec();

  if (msgBox.clickedButton() == connectButton) {
      // play
      return;
  } else if (msgBox.clickedButton() == abortButton) {
    QMessageBox msgBox1;
    here:
    msgBox1.setText("Are you sure?");
    msgBox1.setInformativeText("It's really fun!");
    msgBox1.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox1.setDefaultButton(QMessageBox::No);
    int ret = msgBox1.exec();
    switch (ret) {
    case QMessageBox::No:
        break;
    case QMessageBox::Yes:
        goto here;
    }
  }
  return;
}
