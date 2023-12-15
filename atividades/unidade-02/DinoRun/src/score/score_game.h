#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QFontDatabase>
#include <QString>
#include <QFont>


class GameScore : public QGraphicsTextItem {
    Q_OBJECT

public:
    explicit GameScore(int posX, int posY, QObject *parent = nullptr);
    ~GameScore();

signals:
    void incrementSpeed();

public slots:
    void updateScore();

private:
    int score = 0;
    int INCREMENT_SCORE = 100;
    int FONT_SIZE = 18;
};

#endif // SCORE_H
