QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/button/actionbutton.cpp \
    src/cactus/cactus.cpp \
    src/cactus/cactussprites.cpp \
    src/cactus/obstacle.cpp \
    src/dino/dino.cpp \
    src/dino/dinosprites.cpp \
    src/floor/floor.cpp \
    src/floor/floorsprites.cpp \
    src/floor/horizonline.cpp \
    src/mainwindow/mainwindow.cpp \
    src/game/game.cpp \
    src/score/score_game.cpp

HEADERS += \
    config/circularlist.h \
    config/game_config.h \
    config/screen_config.h \
    src/button/actionbutton.h \
    src/cactus/cactus.h \
    src/cactus/cactussprites.h \
    src/cactus/obstacle.h \
    src/dino/dino.h \
    src/dino/dinosprites.h \
    src/floor/floor.h \
    src/floor/floorsprites.h \
    src/floor/horizonline.h \
    src/mainwindow/mainwindow.h \
    src/game/game.h \
    src/score/score_game.h

FORMS += \
    src/mainwindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets/assets.qrc
