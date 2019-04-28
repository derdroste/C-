#include "score.h"
#include "game.h"
#include <QFont>

extern Game * game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    //Integer
    score=0;

    //Eigenschaften des Counters
    setPlainText(QString("Punkte: ") + QString::number(getScore()));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase(){
    //Bei Erhöhung des Counters den neuen Stand anzeigen
    score++;
    setPlainText(QString("Punkte: ") + QString::number(getScore()));
}
void Score::set(){
    //gespeicherten Zustand des Counters laden und anzeigen
    score=game->hilfe;
    setPlainText(QString("Punkte: ") + QString::number(score));
}

int Score::getScore(){
    //Score wiedergeben
    return score;
}
