#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include "enemy.h"

class Player: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER_H
