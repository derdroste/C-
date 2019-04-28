#ifndef SAVEDENEMY_H
#define SAVEDENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>

class savedenemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    savedenemy();
public slots:
    void move2();
    void remove3();
};

#endif // SAVEDENEMY_H
