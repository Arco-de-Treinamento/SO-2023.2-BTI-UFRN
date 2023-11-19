#include <iostream>
#include "game.h"

Game::Game(QWidget *parent){
    this->setBackgroundBrush(Qt::white);
    gameStart();
}

Game::~Game(){

}

void Game::gameStart(){
    Floor *floor = new Floor(this);

    this->addItem(floor);
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
