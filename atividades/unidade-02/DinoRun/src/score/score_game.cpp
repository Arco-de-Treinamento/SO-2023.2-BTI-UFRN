#include <iostream>
#include<stdexcept>
#include "score_game.h"

GameScore::GameScore(int posX, int posY, QObject *parent){
    int fontId = QFontDatabase::addApplicationFont(":assets/font/alagard.ttf");
    QString fontFamily = "";

    setPos(posX, posY);

    try{
        fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);

    }catch(const std::exception& e){
        std::cerr << "Erro ao adicionar fonte: " << e.what() << std::endl;
        return;
    }

    if(fontFamily != ""){
        QFont newFont;
        newFont.setFamily(fontFamily);
        newFont.setPointSize(FONT_SIZE);

        this->setFont(newFont);
        this->setDefaultTextColor(QColor("#535353"));
    }

    setPlainText(QString("Score: ") + QString::number(score));
}

GameScore::~GameScore(){

}

void GameScore::updateScore(){
    score += INCREMENT_SCORE;
    setPlainText(QString("Score: ") + QString::number(score));

    emit incrementSpeed();
}
