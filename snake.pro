SOURCES = main.cpp food.cpp snake.cpp field.cpp wall.cpp
HEADERS += food.h snake.h field.h wall.h
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = $$EC535/lab5/snake/main
INSTALLS += sources
QT+= widgets

QMAKE_CXXFLAGS += -static -static-libgcc -static-libstdc++
