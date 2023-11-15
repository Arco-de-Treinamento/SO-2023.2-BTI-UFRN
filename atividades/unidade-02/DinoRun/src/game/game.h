#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsTextItem>

class Game : public QGraphicsScene{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
private:

protected:
    void keyPressEvent(QKeyEvent *event) override;
    QGraphicsTextItem *text;
};

#endif // GAME_H
