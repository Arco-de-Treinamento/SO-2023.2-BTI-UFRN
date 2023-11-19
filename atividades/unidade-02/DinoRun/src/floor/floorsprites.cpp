#include "floorsprites.h"

floorSprites::floorSprites(){
    for(int f = 0; f < 2; ++f)
        texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint((2 + f*600), 54), QSize(600, 12))));
}

floorSprites::~floorSprites(){
    texture.clear();
}
