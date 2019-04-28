#ifndef GAME_H
#define GAME_H
#include <QGridLayout>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QPushButton>
#include "player.h"
#include "score.h"
#include "enemy.h"
#include "heart.h"
#include "heart2.h"
#include "savedenemy.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    //Zeiger erstellen
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    QPushButton * Start;
    QGridLayout * gridLayout;
    QTimer * timer;
    QTimer * timer2;
    QTimer * timer3;
    QTimer * timer4;
    Player * player;
    Score * score;
    enemy * Enemy;
    heart * heart1;
    heart2 * Heart2;
    savedenemy * Savedenemy;
    int timerhilfe=2;
    int hilfe = 0;
    int a =0;
    int b = 0;
    int remover=0;
    void addenemy();

private slots:
   void start();
   void speichern();
   void load();
   void stop();
   void remove();
};

#endif // GAME_H
