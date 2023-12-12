#include <iostream>
#include "dino.h"

Dino::Dino(int posX, int posY, int heightJump, int currentSpeed, QObject *parent){
    speed = currentSpeed;
    HEIGHT_JUMP = heightJump;

    sprites = new dinoSprites();
    dino = new QGraphicsPixmapItem(sprites->idle.get(0), this);

    dino->setPixmap(sprites->idle.get(0));
    dino->setPos(posX, posY);

    this->addToGroup(dino);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dino::dinoWalk);

    // Atualiza a cada n frames por segundo
    timer->start(1000/speed);
}

Dino::~Dino(){
    delete timer;
    timer = nullptr;

    delete dino;
    dino = nullptr;

    delete sprites;
    sprites = nullptr;
}

void Dino::speedUp(){
    speed = speed + CONST_UPDATE_SPEED;
}

void Dino::setSpeed(int newSpeed){
    speed = newSpeed;

    // Reinicia o timer com nova velocidade
    if(timer != nullptr){
        timer->stop();
        timer->start(1000/speed);
    }
}

void Dino::dinoIdle(){
    dino->setPixmap(sprites->idle.next());
}

void Dino::dinoWalk(){
    dino->setPixmap(sprites->walk.next());
}

void Dino::dinoJump(){
    emit isJumped();
    emit isWalking();
}

void Dino::dinoDead(){
    dino->setPixmap(sprites->dead);
    this->~Dino();
}
