#ifndef SPRITES_H
#define SPRITES_H

#include <QRect>
#include <QList>
#include <QString>
#include "./config/game_config.h"

class Sprites{
public:
    Sprites();
    ~Sprites();

    // QList <QRect> cactusSprites;
    // QList <QRect> dinoSprites;

    QRect playSprites;
    QRect gameOverSprites;

};

#endif // SPRITES_H
