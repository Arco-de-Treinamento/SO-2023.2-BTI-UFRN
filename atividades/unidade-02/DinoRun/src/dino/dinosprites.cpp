#include "dinosprites.h"

dinoSprites::dinoSprites(){
    for(int d = 0; d < 5; ++d)
        texture.append(QPixmap(SPRITE_PATH).copy(QRect(QPoint((848 + d*43), 2), QSize(43, 46))));
}

dinoSprites::~dinoSprites(){
    texture.clear();
}
