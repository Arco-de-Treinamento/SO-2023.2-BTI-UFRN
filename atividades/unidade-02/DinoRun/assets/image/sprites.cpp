#include "sprites.h"

Sprites::Sprites(){

    this->playSprites = QRect(QPoint(254, 68), QSize(35, 31));
    this->gameOverSprites = QRect(QPoint(655, 15), QSize(190, 5));

    // for(int d = 0; d < 5; ++d)
    //     dinoSprites.append(QRect(QPoint((848 + d*43), 2), QSize(43, 46)));
}

Sprites::~Sprites(){
    // cactusSprites.clear();
    // dinoSprites.clear();
}
