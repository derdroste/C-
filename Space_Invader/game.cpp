#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QBrush>

extern Game * game;

Game::Game(QWidget *parent){

    //Szene erstellen
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,600);
    setScene(scene);

    //Grösse festlegen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(905,605);

    //Spieler erstellen
    player = new Player();
    player->setRect(0,0,80,80);
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable, false);
    player->setBrush(Qt::FDiagPattern);
    scene->addItem(player);

    //Herzen erstellen
    Heart2 = new heart2();
    Heart2->setRect(850,10,40,40);
    Heart2->setBrush(QBrush(Qt::red));
    scene->addItem(Heart2);

    Heart2 = new heart2();
    Heart2->setRect(800,10,40,40);
    Heart2->setBrush(QBrush(Qt::red));
    scene->addItem(Heart2);

    Heart2 = new heart2();
    Heart2->setRect(750,10,40,40);
    Heart2->setBrush(QBrush(Qt::red));
    scene->addItem(Heart2);

    //Herzen als ausgefüllte Geometrie
    heart1 = new heart();
    heart1->setPos(850,10);
    scene->addItem(heart1);

    heart1 = new heart();
    heart1->setPos(800,10);
    scene->addItem(heart1);

    heart1 = new heart();
    heart1->setPos(750,10);
    scene->addItem(heart1);

    //Punkte Counter erstellen
    score = new Score();
    scene->addItem(score);

    //verschiedene Timer
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer3->start();
    timer4 = new QTimer(this);
    timer4->start(5);

    //Buttons erstellen
    QPushButton* speichern = new QPushButton(tr("Speichern"));
    speichern->setFont(QFont("Times", 18, QFont::Bold));
    connect(speichern, SIGNAL(clicked(bool)), this, SLOT(speichern()));

    QPushButton* load = new QPushButton(tr("Laden"));
    load->setFont(QFont("Times", 18, QFont::Bold));
    connect(load, SIGNAL(clicked()), this, SLOT(load()));
    connect(load, SIGNAL(clicked()), this, SLOT(remove()));

    Start = new QPushButton(tr("Start"));
    Start->setFont(QFont("Times", 18, QFont::Bold));
    connect(Start, SIGNAL(clicked()),  this, SLOT(start()));

    //Layout für die Buttons
    gridLayout = new QGridLayout;
    gridLayout->addWidget(Start, 2, 0);
    gridLayout->addWidget(speichern, 3, 0);
    gridLayout->addWidget(load, 4, 0);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

    show();
}

void Game::start()
{
    //Starte die Timer für Move & Spawn
    timer->start(4000);
    timer2->start(50);

    //Button Slots und Schrift wechseln
    Start->setText("Pause");
    disconnect(Start, SIGNAL(clicked()),  this, SLOT(start()));
    connect(Start, SIGNAL(clicked()),  this, SLOT(stop()));

    //Spieler beweglich machen
    player->setFlag(QGraphicsItem::ItemIsFocusable, true);
    player->setFocus();

    timerhilfe=0;
}

void Game::stop()
{
    //Stoppe die Timer
    timer->stop();
    timer2->stop();

    //Button wechseln
    Start->setText("Start");
    connect(Start, SIGNAL(clicked()),  this, SLOT(start()));
    disconnect(Start, SIGNAL(clicked()),  this, SLOT(stop()));

    //Spieler unbeweglich machen
    player->setFlag(QGraphicsItem::ItemIsFocusable, false);

    timerhilfe=1;
}

void Game::remove(){
    //Setze Hilfs-Integer auf 1
    remover=1;
}

//Savegame erstellen
void Game::speichern(){

    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    //Datei öffnen & Namen angeben
    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
        tr("Speichern als"), ".", tr("Data (*.myz)"));

    if (fileName.isNull() == false) {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Fehler"),
                tr("Die Datei ist ungültig: ") + fileName, QMessageBox::Ok);
        }

        QTextStream out(&file);

        //Zustand der Objekte in die Datei schreiben
        out << player->x() << endl;
        out << score->getScore() << endl;
        out << "Ich bin nur ein Platzhalter" << endl;
        out << "Ich auch" << endl;
        out << a << endl;
        out << b << endl;

        file.close();
        return;
    }
}

//Savegame laden
void Game::load()
{

    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    //Datei öffnen
    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
        tr("Speichern als"), ".", tr("Data (*.myz)"));

    if (fileName.isNull() == false) {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Fehler"),
                tr("Die Datei ist ungültig: ") + fileName, QMessageBox::Ok);
        }
        QTextStream in(&file);

        QString line;
        int zeile = 1;

        do{
            //Nächste Zeile lesen
            line = in.readLine();
            //zu Integer konvertieren
            hilfe = line.toInt();

            //Zeilen werden einzeln eingelesen und den Objekten
            //durch den Integer zugewiesen
            switch (zeile) {
            case 1: player->setPos(hilfe,500); break;
            case 2: game->score->set(); break;
            case 3: addenemy(); break;
            //Timer durch stoppen zurück setzen
            case 4: timer->stop();timer2->stop();
                    if(timerhilfe==0)
                    {
                        timer->start();timer2->start();
                    };break;
            case 5: Savedenemy->setY(hilfe); break;
            case 6: Savedenemy->setX(hilfe);break;
            default: break;
            }
            zeile++;
        } while (!line.isNull());

        update();

        file.close();
        return;
    }
}

void Game::addenemy()
{
    //den gespeicherten Gegner erstellen
    Savedenemy = new savedenemy();
    Savedenemy->setRect(0,0,60,60);
    scene->addItem(Savedenemy);
}

