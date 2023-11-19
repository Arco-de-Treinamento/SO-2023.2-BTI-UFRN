#ifndef CACTUS_H
#define CACTUS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTime>
#include "cactussprites.h"

class Cactus : public QObject, public QGraphicsItemGroup{
    Q_OBJECT
public:
    explicit Cactus(QObject *parent = nullptr);
    ~Cactus();

private:
    int POS_X = 14;
    int POS_Y = 170;
};

#endif // CACTUS_H
