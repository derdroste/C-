#include "savegame.h"
#include "score.h"

#include <QtGui>
#include <QMessageBox>


QPainter painter;

zeichenFeld::zeichenFeld(QWidget* parent)
    : QWidget(parent)
{

    //erstelle Timer-Instanz, verbinde Timer mit bewegeObjekte()-Funktion, starte Timer der alle 50 millisekunden aktualisiert
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}


void zeichenFeld::serialize(QFile& file)
{
    QTextStream out(&file);
    //speichert in text, zeile für zeile, die eigenschaften



