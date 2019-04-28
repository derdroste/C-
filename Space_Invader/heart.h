#ifndef HEART_H
#define HEART_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class heart:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    heart(QGraphicsItem * parent=0);
};

#endif // HEART_H
