#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTime>
#include "floorsprites.h"

class Floor : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:    
    explicit Floor(QObject *parent = nullptr);
    ~Floor();

private:
    int POS_X = 0;
    int POS_Y = 180;
};

#endif // FLOOR_H
