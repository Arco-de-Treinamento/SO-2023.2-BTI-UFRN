#ifndef DINO_H
#define DINO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTime>
#include "dinosprites.h"

class Dino : public QObject, public QGraphicsItemGroup{
    Q_OBJECT
public:
    explicit Dino(QObject *parent = nullptr);
    ~Dino();

private:
    int POS_X = 48;
    int POS_Y = 170;
};

#endif // DINO_H

