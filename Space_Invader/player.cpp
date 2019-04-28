#include "player.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
using namespace std;

void Player::keyPressEvent(QKeyEvent *event)
{
    //Spieler durch Key Event nach  Links/Rects bewegen
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-8, y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 80 < 895)
        setPos(x()+8, y());
    }
}

void Player::spawn()
{
    //Gegner spawnen lassen
    enemy * Enemy = new enemy();
    scene()->addItem(Enemy);
}
