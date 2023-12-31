#include <iostream>
#include "game.h"

Game::Game(QWidget *parent){
    this->setBackgroundBrush(Qt::white);

    // Previne o bug de criar os elementos antes de criar a tela
    // em dispositivos modestos
    QTimer::singleShot(100, this, &Game::gameInit);
    //gameInit();
}

Game::~Game(){
    this->removeItem(dino);
    this->removeItem(obstacle);
    this->removeItem(horizonline);

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

    dino = new Dino(DINO_POS_X, DINO_POS_Y, DINO_HEIGHT_JUMP, 10, this);
    horizonline = new Horizonline(60, this);    
    obstacle = new Obstacle(DINO_POS_X, 60, this);
    gameScore = new GameScore(SCORE_POS_X, SCORE_POS_Y, this);

    this->addItem(horizonline);
    this->addItem(obstacle);
    this->addItem(dino);
    this->addItem(gameScore);

    connect(dino, &Dino::isJump, obstacle, &Obstacle::setDinoJump);

    connect(obstacle, &Obstacle::isCollided, dino, &Dino::dinoDead);
    connect(obstacle, &Obstacle::isCollided, horizonline, &Horizonline::isGameOver);
    connect(obstacle, &Obstacle::isCollided, this, &Game::gameOver);
    connect(obstacle, &Obstacle::incrementScore, gameScore, &GameScore::updateScore);

    connect(gameScore, &GameScore::incrementSpeed, this, &Game::speedUp);
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
    horizonline->speedUp();
    obstacle->speedUp();
}


void Game::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Space:
            dino->dinoJump();
            break;

        case Qt::Key_Up:
            dino->dinoJump();
            break;
    }
}
