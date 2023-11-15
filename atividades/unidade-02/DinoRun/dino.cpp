#include "dino.h"
#include <QDebug>

Dino::Dino(){

}

Dino::~Dino()
{

}

void Dino::keyPressEvent(QKeyEvent *event){
    qDebug() << "key pressed";
}


