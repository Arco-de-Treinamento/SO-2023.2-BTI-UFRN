#ifndef DINOSPRITES_H
#define DINOSPRITES_H

#include <QRect>
#include <QList>
#include <QString>
#include <QPixmap>
#include "./config/game_config.h"
#include "./config/circularlist.h"

class dinoSprites{
public:
    dinoSprites();
    ~dinoSprites();

    CircularList <QPixmap> idle;
    CircularList <QPixmap> walk;
    QPixmap dead;
};

#endif // DINOSPRITES_H
