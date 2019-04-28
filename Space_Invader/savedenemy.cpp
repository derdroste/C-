#include "savedenemy.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"


extern Game * game;
savedenemy::savedenemy(): QObject(), QGraphicsRectItem()
{
    //Ein neuer Gegner, mit den gespeicherten Eigenschaften wird erstellt
    setRect(0,0,60,60);
    connect(game->timer2,SIGNAL(timeout()),this,SLOT(move2()));
    connect(game->timer4,SIGNAL(timeout()),this,SLOT(remove3()));
}

void savedenemy::move2(){

    //Wie bei Enemy
    setPos(x(),y()+10);
    game->a += 10;
    if (pos().y() + rect().height()>640){
        game->score->increase();
        game->a = 0;

        scene()->removeItem(this);
        delete this;
}
}

void savedenemy::remove3()
{
    //Lösche den neuen Gegner erst nach der Laden Funktion, damit nicht unendlich
    //viele Gegner geladen werden können
    if(game->remover==1){
           scene()->removeItem(this);
           delete this;
           game->remover=0;
       }
}

