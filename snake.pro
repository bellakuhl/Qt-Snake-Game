SOURCES = main.cpp food.cpp snake.cpp field.cpp wall.cpp piece.cpp Game.cpp
HEADERS += food.h snake.h field.h wall.h piece.h Game.h
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = $$EC535/lab5/snake/main
INSTALLS += sources
QT+= widgets core gui
CONFIG += qt resources
RESOURCES += resources/icons.qrc

QMAKE_CXXFLAGS += -static -static-libgcc -static-libstdc++
