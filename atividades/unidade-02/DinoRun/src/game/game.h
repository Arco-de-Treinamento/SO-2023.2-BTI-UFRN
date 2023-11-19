#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include "./config/game_config.h"
#include "./src/floor/floor.h"

class Game : public QGraphicsScene{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    void gameStart();
    void gameOver();
    void speedUp();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
