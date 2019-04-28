#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>

class enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemy();
public slots:
    void move();
    void remove2();
};

#endif // ENEMY_H
