#include <iostream>
#include "floor.h"

Floor::Floor(QObject *parent) : QObject(parent){
    floorSprites *sprites = new floorSprites();
    QGraphicsPixmapItem *floor = new QGraphicsPixmapItem(sprites->texture[0], this);

    floor->setPixmap(sprites->texture[0]);
    floor->setPos(POS_X,POS_Y);

    this->addToGroup(floor);
}

Floor::~Floor(){

}
