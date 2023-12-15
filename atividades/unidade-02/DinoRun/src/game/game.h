#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QKeyEvent>
#include <QTimer>

#include "./config/game_config.h"

#include "./src/floor/horizonline.h"
#include "./src/cactus/obstacle.h"
#include "./src/dino/dino.h"
#include "./src/button/actionbutton.h"
#include "./src/score/score_game.h"

class Game : public QGraphicsScene{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    Dino *dino;
    Obstacle *obstacle;
    Horizonline *horizonline;
    GameScore *gameScore;

    QGraphicsProxyWidget *proxy;
    actionButton *startButton;
    actionButton *gameOverButton;

private slots:
    void gameInit();
    void gameStart();
    void gameOver();
    void speedUp();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
