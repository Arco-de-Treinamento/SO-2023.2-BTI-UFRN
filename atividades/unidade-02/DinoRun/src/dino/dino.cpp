#include <iostream>
#include "dino.h"

Dino::Dino(QObject *parent){
    dinoSprites *sprites = new dinoSprites();
    QGraphicsPixmapItem *dino = new QGraphicsPixmapItem(sprites->texture[0], this);

    dino->setPixmap(sprites->texture[0]);
    dino->setPos(POS_X, POS_Y);

    this->addToGroup(dino);
}

Dino::~Dino(){

}
