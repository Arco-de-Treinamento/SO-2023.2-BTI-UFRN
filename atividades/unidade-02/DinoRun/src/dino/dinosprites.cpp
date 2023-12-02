#include "dinosprites.h"

dinoSprites::dinoSprites(){
    // Animacao Idle
    idle.add(QPixmap(SPRITE_PATH).copy(QRect(QPoint((848), 2), QSize(43, 46))));
    idle.add(QPixmap(SPRITE_PATH).copy(QRect(QPoint((892), 2), QSize(43, 46))));

    // Animacao Andar
    walk.add(QPixmap(SPRITE_PATH).copy(QRect(QPoint((936), 2), QSize(43, 46))));
    walk.add(QPixmap(SPRITE_PATH).copy(QRect(QPoint((980), 2), QSize(43, 46))));

    // Animacao Morte
    dead = QPixmap(SPRITE_PATH).copy(QRect(QPoint((1024), 2), QSize(43, 46)));
}

dinoSprites::~dinoSprites(){

}
