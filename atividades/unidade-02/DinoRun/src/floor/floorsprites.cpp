#include "floorsprites.h"

floorSprites::floorSprites(){
    for(int f = 0; f < 2; ++f)
        texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint((2 + f * WIDTH_TEX), 54), QSize(WIDTH_TEX, HEIGTH_TEX))));
}

floorSprites::~floorSprites(){
    texture.clear();
}
