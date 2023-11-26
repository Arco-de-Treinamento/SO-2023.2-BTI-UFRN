#ifndef HORIZONLINE_H
#define HORIZONLINE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QList>
#include "floor.h"

class Horizonline : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

public:
    explicit Horizonline(const int currentSpeed, QObject *parent = nullptr);
    ~Horizonline();

    void speedUp();
    void setSpeed(int newSpeed);

private:
    int POS_Y = 180;
    int INIT_POS_X = 0;
    int POS_X = 599;
    int CONST_UPDATE_SPEED = 10;

    int speed;
    QList<Floor*> floors;

    bool isStarted = false;

private slots:
    void createFloor();
};

#endif // HORIZONLINE_H
