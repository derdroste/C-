#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <game.h>

//Auf game zugreifen können
extern Game * game;

enemy::enemy(): QObject(), QGraphicsRectItem()
{
    //Dem Gegner eine zufällige Position auf der X-Achse geben
    int random_number = rand() % 680;
    setPos(random_number,0);
    game->b = random_number;

    //Gegner erstellen und Timer mit den Move & Remove Funtkionen verknüpfen
    setRect(0,0,60,60);
    connect(game->timer2,SIGNAL(timeout()),this,SLOT(move()));
    connect(game->timer3,SIGNAL(timeout()),this,SLOT(remove2()));



}

void enemy::move(){

    //Y-Position und Hilfs-Integer werden periodisch erhöht
    setPos(x(),y()+10);
    game->a += 10;

    //Übertritt der Gegner die Grenze des Spielfelds wird er gelöscht
    //und der Counter erhöht sich um 1
    if (pos().y() + rect().height()>690){
        game->score->increase();
        game->a = 0;
        scene()->removeItem(this);
        delete this;
    }
}

void enemy::remove2()
{
    //Wurde die Laden-Funktion benutzt, wird der aktuelle Gegner gelöscht
    if(game->remover==1){
           scene()->removeItem(this);
           delete this;
           game->remover=0;
       }
}





