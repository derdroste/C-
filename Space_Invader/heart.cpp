#include "heart.h"
#include <QGraphicsScene>


heart::heart(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //Bild als Herz
    setPixmap(QPixmap(":image/herz.png"));
}

