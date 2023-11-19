#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    ui->setupUi(this);
    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow(){
    delete ui;
}

