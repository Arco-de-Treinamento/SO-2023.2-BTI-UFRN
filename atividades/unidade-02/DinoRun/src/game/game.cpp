#include <iostream>
#include <QTime>
#include "game.h"

Game::Game(QWidget *parent){
    this->setBackgroundBrush(Qt::white);
    QTimer::singleShot(100);

    gameInit();
}

Game::~Game(){

}

void Game::gameInit(){
    actionButton *startButton = new actionButton("Start !");

    QGraphicsProxyWidget *proxy = this->addWidget(startButton);

    connect(startButton, &QPushButton::clicked, this, &Game::gameStart);

    // Centralize o botão
    qreal x = (this->width() - startButton->width()) / 2;
    qreal y = (this->height() - startButton->height()) / 2;
    proxy->setPos(x, y);

}

void Game::gameStart(){
    Floor *floor = new Floor(this);
    Cactus *cactus = new Cactus(this);
    Dino *dino = new Dino(this);

    this->addItem(floor);
    this->addItem(cactus);
    this->addItem(dino);
}

void Game::gameOver(){

}

void Game::speedUp()
{

}

void Game::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Space:
            std::cout << "space" << std::endl;
            break;

        case Qt::Key_Up:
            std::cout << "UP" << std::endl;
            break;

        case Qt::Key_Down:
            std::cout << "DOWN" << std::endl;
            break;
    }
}


