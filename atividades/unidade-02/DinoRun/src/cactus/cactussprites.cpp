#include "cactussprites.h"

cactusSprites::cactusSprites(){
    // Cacto I
    texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint(332, 2), QSize(24, 49))));
    // Cacto II
    texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint(357, 2), QSize(49, 49))));
    // Cacto III
    texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint(407, 2), QSize(74, 49))));

}

cactusSprites::~cactusSprites(){
    texture.clear();
}
