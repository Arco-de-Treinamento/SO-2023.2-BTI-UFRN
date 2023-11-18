#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){    
    ui->setupUi(this);

    this->resize((SCREEN_WIDTH + SCREEN_BORDER),(SCREEN_HEIGHT + SCREEN_BORDER));
    game->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow(){
    delete ui;
}

