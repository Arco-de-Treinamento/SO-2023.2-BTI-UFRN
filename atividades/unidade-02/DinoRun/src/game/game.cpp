#include "game.h"
#include <QKeyEvent>
#include <iostream>

Game::Game(QWidget *parent){
    this->setBackgroundBrush(Qt::white);
}

Game::~Game(){

}

void Game::gameStart(){

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
