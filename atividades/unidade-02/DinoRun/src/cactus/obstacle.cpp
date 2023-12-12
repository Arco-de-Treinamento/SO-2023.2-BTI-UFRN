#include <iostream>
#include "obstacle.h"


Obstacle::Obstacle(const int posCollider, const int currentSpeed, QObject *parent){
    speed = currentSpeed;
    POS_COLLIDER = posCollider;
    createCactus();
}

Obstacle::~Obstacle(){
    qDeleteAll(obstacles);
    obstacles.clear();
}

void Obstacle::speedUp(){
    speed = speed + CONST_UPDATE_SPEED;

    for(Cactus* cactus : obstacles)
        cactus->setSpeed(speed);
}

void Obstacle::setSpeed(int newSpeed){
    speed = newSpeed;
}

int Obstacle::getRand(){
    // Semeando srand
    std::srand(std::time(0));
    return (std::rand() %  MAX_UNIT_INTERVAL) + MIN_UNIT_INTERVAL;  // entre MIN E MAX
}

void Obstacle::createCactus(){
    // Condicao de elatoriedade
    Cactus *cactus = new Cactus(POS_X, POS_Y, speed, POS_COLLIDER, SCREEN_SIZE - (getRand() * INTERVAL_UNIT), this);

    this->addToGroup(cactus);

    connect(cactus, &Cactus::alertPos, this, &Obstacle::createCactus);
    connect(cactus, &Cactus::isCactusCollided, this, &Obstacle::checkCollider);

    obstacles.append(cactus);

}

void Obstacle::checkCollider(){
    // Zera velocidade dos cactos
    speed = 0;

    for(Cactus* cactus : obstacles)
        cactus->setSpeed(speed);

    emit isCollided();
}
