#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QKeyEvent>

#include "./config/game_config.h"

#include "./src/floor/horizonline.h"
#include "./src/cactus/cactus.h"
#include "./src/dino/dino.h"
#include "./src/button/actionbutton.h"

class Game : public QGraphicsScene{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    void gameInit();
    void gameStart();
    void gameOver();
    void speedUp();

    Cactus *cactus;
    Dino *dino;
    Horizonline *horizonline;

    QGraphicsProxyWidget *proxy;
    actionButton *startButton;
    actionButton *gameOverButton;

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
