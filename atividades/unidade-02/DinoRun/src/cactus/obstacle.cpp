#include <iostream>
#include "obstacle.h"


Obstacle::Obstacle(const int currentSpeed, QObject *parent){
    speed = currentSpeed;
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
    Cactus *cactus = new Cactus(POS_X, POS_Y, speed, SCREEN_SIZE - (getRand() * INTERVAL_UNIT), this);
    this->addToGroup(cactus);

    connect(cactus, &Cactus::alertPos, this, &Obstacle::createCactus);
    obstacles.append(cactus);

}
