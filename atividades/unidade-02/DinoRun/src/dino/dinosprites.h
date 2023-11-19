#ifndef DINOSPRITES_H
#define DINOSPRITES_H

#include <QRect>
#include <QList>
#include <QString>
#include <QPixmap>
#include "./config/game_config.h"

class dinoSprites{
public:
    dinoSprites();
    ~dinoSprites();

    QList <QPixmap> texture;
};

#endif // DINOSPRITES_H
