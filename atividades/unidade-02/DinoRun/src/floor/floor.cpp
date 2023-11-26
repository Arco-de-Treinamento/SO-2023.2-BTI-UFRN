#include <iostream>
#include "floor.h"

Floor::Floor(int posX, int posY, int currentSpeed, QObject *parent) : QObject(parent){
    speed = currentSpeed;
    AUX_POS_X = posX;

    floorSprites *sprites = new floorSprites();
    QGraphicsPixmapItem *floor = new QGraphicsPixmapItem(sprites->texture[0], this);

    floor->setPixmap(sprites->texture[0]);
    floor->setPos(posX,posY);

    addToGroup(floor);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Floor::moveFloor);

    // Atualiza a cada n frames por segundos
    timer->start(1000/speed);
}

Floor::~Floor(){
    delete timer;
    timer = nullptr;

    while (!childItems().isEmpty())
        delete childItems().first();
}

void Floor::setSpeed(int newSpeed){
    speed = newSpeed;

    // Reinicia o timer com nova velocidade
    if(timer != nullptr) {
        timer->stop();
        timer->start(1000/speed);
    }
}

void Floor::moveFloor(){
    // Setando pos real e relativa
    AUX_POS_X = AUX_POS_X - PIXEL_COUNT;
    setPos(x() - PIXEL_COUNT, y());

    if(AUX_POS_X + LENGTH == 599)
        emit started();

    if(AUX_POS_X + LENGTH == 0)
        this->~Floor();
}
