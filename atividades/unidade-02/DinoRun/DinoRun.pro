QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assets/image/sprites.cpp \
    main.cpp \
    src/cactus/cactus.cpp \
    src/cactus/cactussprites.cpp \
    src/floor/floor.cpp \
    src/floor/floorsprites.cpp \
    src/mainwindow/mainwindow.cpp \
    src/game/game.cpp

HEADERS += \
    assets/image/sprites.h \
    config/game_config.h \
    config/screen_config.h \
    src/cactus/cactus.h \
    src/cactus/cactussprites.h \
    src/floor/floor.h \
    src/floor/floorsprites.h \
    src/mainwindow/mainwindow.h \
    src/game/game.h

FORMS += \
    src/mainwindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets/assets.qrc
