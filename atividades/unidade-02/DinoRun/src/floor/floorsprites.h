#ifndef FLOORSPRITES_H
#define FLOORSPRITES_H

#include <QRect>
#include <QList>
#include <QString>
#include <QPixmap>
#include "./config/game_config.h"

class floorSprites{
public:
    floorSprites();
    ~floorSprites();

    QList <QPixmap> texture;
};

#endif // FLOORSPRITES_H
