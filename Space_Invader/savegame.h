#ifndef SAVEGAME_H
#define SAVEGAME_H


#include <QWidget>
#include <QTimer>
#include <QFile>

class zeichenFeld : public QWidget
{
    Q_OBJECT //Makro
    //

    public:
    zeichenFeld(QWidget *parent = 0);
    void serialize(QFile &file);

    //damit timer über die Knöpe nutzbar ist
    //timer mit 20 millisekunden schritten
    void start(void) {timer->start(20);};
    void stop(void) {timer->stop();};


    private:
    QTimer *timer = new QTimer(this);

};

#endif // SAVEGAME_H
