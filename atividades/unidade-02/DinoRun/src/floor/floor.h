#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTime>
#include "floorsprites.h"

#define POS_X 0
#define POS_Y 200

class Floor : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:    
    explicit Floor(QObject *parent = nullptr);
    ~Floor();
};

#endif // FLOOR_H
