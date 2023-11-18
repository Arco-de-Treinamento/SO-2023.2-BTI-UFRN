#include "sprites.h"

Sprites::Sprites(){

    this->playSprites = QRect(QPoint(254, 68), QSize(35, 31));
    this->gameOverSprites = QRect(QPoint(655, 15), QSize(190, 5));

    // for(int d = 0; d < 5; ++d)
    //     dinoSprites.append(QRect(QPoint((848 + d*43), 2), QSize(43, 46)));

    // for(int c = 0; c < 3; c++)
    //     cactusSprites.append(QRect(QPoint(332 + i*25, 2), QSize(24 + i*25, 49)));

}

Sprites::~Sprites(){
    // cactusSprites.clear();
    // dinoSprites.clear();
}
