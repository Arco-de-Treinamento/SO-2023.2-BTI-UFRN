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

    int WIDTH_TEX = 600;
    int HEIGTH_TEX = 12;
};

#endif // FLOORSPRITES_H
