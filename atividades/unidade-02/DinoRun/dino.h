#ifndef DINO_H
#define DINO_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMouseEvent>

class Dino : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Dino();
    ~Dino();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // DINO_H
