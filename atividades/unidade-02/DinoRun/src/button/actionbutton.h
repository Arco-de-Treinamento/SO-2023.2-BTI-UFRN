#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <QPushButton>
#include <QFontDatabase>
#include <QString>
#include <QFont>

class actionButton : public QPushButton{
    Q_OBJECT

public:
    explicit actionButton(const QString &title, QWidget *parent = nullptr);
    ~actionButton();

private:
    int FONT_SIZE = 24;
};

#endif // ACTIONBUTTON_H
