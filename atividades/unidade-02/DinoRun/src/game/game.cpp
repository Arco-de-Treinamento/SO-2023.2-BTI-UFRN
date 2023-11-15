#include "game.h"
#include <QKeyEvent>
#include <iostream>

Game::Game(QWidget *parent){
    std::cout << "Abriu game widget" << std::endl;

    text = new QGraphicsTextItem("Dino Run");
    text->setPos(this->width() / 3, this->height() / 4);

    this->addItem(text);
}

Game::~Game(){

}

void Game::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Space:
            std::cout << "space" << std::endl;
            break;

        case Qt::Key_Escape:
            std::cout << "ESC" << std::endl;
            break;

        case Qt::Key_Up:
            std::cout << "UP" << std::endl;
            text->setPos(text->x(), text->y() - 10);
            break;

        case Qt::Key_Down:
            std::cout << "DOWN" << std::endl;
            text->setPos(text->x(), text->y() + 10);
            break;
    }
}
