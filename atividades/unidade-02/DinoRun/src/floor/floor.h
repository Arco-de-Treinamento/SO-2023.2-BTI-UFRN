#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "floorsprites.h"

class Floor : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:
    explicit Floor(int posX, int posY, int currentSpeed, QObject *parent = nullptr);
    ~Floor();

    void setSpeed(int newSpeed);

private:
    int PIXEL_COUNT = 1;
    int LENGTH = 600;

    int AUX_POS_X;

    int speed;
    QTimer *timer;

signals:
    void started();

private slots:
    void moveFloor();
};

#endif // FLOOR_H
