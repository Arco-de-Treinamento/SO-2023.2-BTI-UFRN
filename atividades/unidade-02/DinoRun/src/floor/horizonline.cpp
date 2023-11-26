#include <iostream>
#include "horizonline.h"

Horizonline::Horizonline(const int currentSpeed, QObject *parent){
    speed = currentSpeed;
    createFloor();
}

Horizonline::~Horizonline(){
    qDeleteAll(floors);
    floors.clear();
}

void Horizonline::speedUp(){
    speed = speed + CONST_UPDATE_SPEED;

    for(Floor* floor : floors)
        floor->setSpeed(speed);
}

void Horizonline::setSpeed(int newSpeed){
    speed = newSpeed;
}

void Horizonline::createFloor(){
    Floor *floor = new Floor((!isStarted ? INIT_POS_X : POS_X), POS_Y, speed, this);

    this->addToGroup(floor);

    connect(floor, &Floor::started, this, &Horizonline::createFloor);

    floors.append(floor);
    isStarted = true;
}
