#include <QApplication>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    //Spiel ausführen
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    return a.exec();
}

