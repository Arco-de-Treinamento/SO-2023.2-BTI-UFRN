#include <iostream>
#include "cactus.h"

Cactus::Cactus(int posX, int posY, int currentSpeed, QObject *parent){
    speed = currentSpeed;
    AUX_POS_X = posX;
    TYPE_CACTUS = this->getRand();

    cactusSprites *sprites = new cactusSprites();
    QGraphicsPixmapItem *cactus = new QGraphicsPixmapItem(sprites->texture[TYPE_CACTUS], this);

    cactus->setPixmap(sprites->texture[TYPE_CACTUS]);
    cactus->setPos(posX, posY);

    this->addToGroup(cactus);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cactus::moveCactus);

    // Atualiza a cada n frames por segundos
    timer->start(1000/speed);
}

Cactus::~Cactus(){
    std::cout << "morreu" << std::endl;
    delete timer;
    timer = nullptr;

    while (!childItems().isEmpty())
        delete childItems().first();
}

void Cactus::setSpeed(int newSpeed){
    speed = newSpeed;

    // Reinicia o timer com nova velocidade
    if(timer != nullptr){
        timer->stop();
        timer->start(1000/speed);
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

void Cactus::moveCactus(){
    // Setando pos real e relativa
    AUX_POS_X = AUX_POS_X - PIXEL_COUNT;
    setPos(x() - PIXEL_COUNT, y());

    if(AUX_POS_X + LENGTH == 0)
        this->~Cactus();
}
