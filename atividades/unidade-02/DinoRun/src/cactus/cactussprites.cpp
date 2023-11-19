#include "cactussprites.h"

cactusSprites::cactusSprites(){
    for(int c = 0; c < 3; c++)
        texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint(332 + c*25, 2), QSize(24 + c*25, 49))));
}

cactusSprites::~cactusSprites(){
    texture.clear();
}
