#include <iostream>
#include "cactus.h"

Cactus::Cactus(int posX, int posY, int currentSpeed, int posCollider, int posAlert, QObject *parent){
    speed = currentSpeed;
    TYPE_CACTUS = this->getRand();
    POS_COLLIDER_X = posCollider;

    cactusSprites *sprites = new cactusSprites();
    QGraphicsPixmapItem *cactus = new QGraphicsPixmapItem(sprites->texture[TYPE_CACTUS], this);

    LENGTH = sprites->texture[TYPE_CACTUS].width();
    ALERT_POS_X = posAlert;
    AUX_POS_X = posX;

    cactus->setPixmap(sprites->texture[TYPE_CACTUS]);
    cactus->setPos(posX, posY);

    this->addToGroup(cactus);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cactus::moveCactus);

    // Atualiza a cada n frames por segundos
    timer->start(1000/speed);
}

Cactus::~Cactus(){
    delete timer;
    timer = nullptr;

    while (!childItems().isEmpty())
        delete childItems().first();
}

void Cactus::setSpeed(int newSpeed){
    speed = newSpeed;

    if(timer != nullptr){
        if(speed != 0){
            // Reinicia o timer com nova velocidade
            timer->stop();
            timer->start(1000/speed);

        } else {
            timer->stop();
        }
    }
}

int Cactus::getPos(){
    return AUX_POS_X;
}

int Cactus::getRand(){
    // Semeando srand
    std::srand(std::time(0));
    return std::rand() % 3;  // entre 0 e 2
}

void Cactus::setPosAlert(int pos){
    ALERT_POS_X = pos;
}

void Cactus::moveCactus(){
    // Setando pos real e relativa
    AUX_POS_X = AUX_POS_X - PIXEL_COUNT;
    setPos(x() - PIXEL_COUNT, y());

    // Sinal de alerta para criar outro cacto
    if(AUX_POS_X + LENGTH == ALERT_POS_X)
        emit alertPos();

    if(AUX_POS_X == POS_COLLIDER_X)
        emit isCactusCollided();

    if(AUX_POS_X + LENGTH == 0)
        this->~Cactus();
}
