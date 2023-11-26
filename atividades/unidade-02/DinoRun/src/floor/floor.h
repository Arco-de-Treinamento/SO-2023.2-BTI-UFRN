#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "floorsprites.h"

class Floor : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:
    explicit Floor(const int currentSpeed, QObject *parent = nullptr);
    ~Floor();

    void setSpeed(int newSpeed);

private:
    int POS_X = 0;
    int POS_Y = 180;
    int PIXEL_COUNT = 1;
    const int LENGTH = 600;

    int speed;
    QTimer *timer;

signals:
    void started();

private slots:
    void moveFloor();
};

#endif // FLOOR_H
