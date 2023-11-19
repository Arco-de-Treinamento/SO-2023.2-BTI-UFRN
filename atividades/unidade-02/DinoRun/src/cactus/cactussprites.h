#ifndef CACTUSSPRITES_H
#define CACTUSSPRITES_H

#include <QRect>
#include <QList>
#include <QString>
#include <QPixmap>
#include "./config/game_config.h"

class cactusSprites{
public:
    cactusSprites();
    ~cactusSprites();

    QList <QPixmap> texture;
};

#endif // CACTUSSPRITES_H
