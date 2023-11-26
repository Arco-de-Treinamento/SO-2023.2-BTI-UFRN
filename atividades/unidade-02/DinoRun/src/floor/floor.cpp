#include <iostream>
#include "floor.h"

Floor::Floor(const int currentSpeed, QObject *parent) : QObject(parent){
    this->setSpeed(currentSpeed);

    floorSprites *sprites = new floorSprites();
    QGraphicsPixmapItem *floor = new QGraphicsPixmapItem(sprites->texture[0], this);

    floor->setPixmap(sprites->texture[0]);
    floor->setPos(POS_X,POS_Y);

    this->addToGroup(floor);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Floor::moveFloor);

    // Atualiza a cada 60 frames por segundos
    timer->start(1000/60);
}

Floor::~Floor(){
    delete timer;
    timer = nullptr;

    while (!childItems().isEmpty())
        delete childItems().first();

}

void Floor::setSpeed(int newSpeed){
    speed = newSpeed;
}

void Floor::moveFloor(){
    setPos(x() - speed, y());

    if(x() + 600 == 0)
        this->~Floor();
}
