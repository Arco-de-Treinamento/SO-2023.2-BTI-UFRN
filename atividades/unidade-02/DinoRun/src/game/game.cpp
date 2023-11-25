#include <iostream>
#include <QApplication>
#include <QTimer>
#include "game.h"

Game::Game(QWidget *parent){
    this->setBackgroundBrush(Qt::white);

    // Previne o bug de criar os elementos antes de criar a tela
    // em dispositivos modestos
    QTimer::singleShot(100, this, &Game::gameInit);
    //gameInit();
}

Game::~Game(){
    this->removeItem(floor);
    this->removeItem(cactus);
    this->removeItem(dino);

    delete proxy;
    proxy = nullptr;
}

void Game::gameInit(){
    startButton = new actionButton("Start !");
    proxy = this->addWidget(startButton);

    connect(startButton, &QPushButton::clicked, this, &Game::gameStart);

    // Centralize o botão
    qreal x = (this->width() - startButton->width()) / 2;
    qreal y = (this->height() - startButton->height()) / 2;
    proxy->setPos(x, y);
}

void Game::gameStart(){
    this->removeItem(startButton->graphicsProxyWidget());

    floor = new Floor(this);
    cactus = new Cactus(this);
    dino = new Dino(this);

    this->addItem(floor);
    this->addItem(cactus);
    this->addItem(dino);
}

void Game::gameOver(){
    gameOverButton = new actionButton("Game Over");
    proxy = this->addWidget(gameOverButton);

    connect(gameOverButton, &QPushButton::clicked, this, &QApplication::quit);

    // Centralize o botão
    qreal x = (this->width() - gameOverButton->width()) / 2;
    qreal y = (this->height() - gameOverButton->height()) / 2;
    proxy->setPos(x, y);
}

void Game::speedUp(){

}

void Game::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Space:
            std::cout << "space" << std::endl;
            gameOver();
            break;

        case Qt::Key_Up:
            std::cout << "UP" << std::endl;
            break;

        case Qt::Key_Down:
            std::cout << "DOWN" << std::endl;
            break;
    }
}


