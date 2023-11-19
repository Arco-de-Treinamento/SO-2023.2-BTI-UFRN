#include "sprites.h"

Sprites::Sprites(){
    this->playSprites = QRect(QPoint(254, 68), QSize(35, 31));
    this->gameOverSprites = QRect(QPoint(655, 15), QSize(190, 5));

}

Sprites::~Sprites(){
    // cactusSprites.clear();
    // dinoSprites.clear();
}
