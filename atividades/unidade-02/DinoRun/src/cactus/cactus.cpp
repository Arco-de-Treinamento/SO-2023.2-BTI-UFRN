#include <iostream>
#include "cactus.h"

Cactus::Cactus(QObject *parent){
    cactusSprites *sprites = new cactusSprites();
    QGraphicsPixmapItem *cactus = new QGraphicsPixmapItem(sprites->texture[0], this);

    cactus->setPixmap(sprites->texture[0]);
    cactus->setPos(POS_X,POS_Y);

    this->addToGroup(cactus);
}

Cactus::~Cactus(){

}
