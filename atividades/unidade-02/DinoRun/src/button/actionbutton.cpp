#include <iostream>
#include<stdexcept>
#include "actionbutton.h"


actionButton::actionButton(const QString &title, QWidget *parent) : QPushButton(title, parent){
    int fontId = QFontDatabase::addApplicationFont(":assets/font/alagard.ttf");
    QString fontFamily = "";

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
        this->setStyleSheet("color: #535353;"
                            "border: none;"
                            "background-color: white;");
    }

}

actionButton::~actionButton(){

}
