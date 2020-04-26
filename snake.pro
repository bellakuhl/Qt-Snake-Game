SOURCES = main.cpp food.cpp snake.cpp
HEADERS += food.h snake.h
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = $$EC535/lab5/snake/main
INSTALLS += sources

QMAKE_CXXFLAGS += -static -static-libgcc -static-libstdc++
