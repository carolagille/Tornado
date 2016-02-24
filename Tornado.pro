TARGET=Tornado
QT+=opengl
CONFIG+=c++11

SOURCES+=$$PWD/src/TornadoCurve.cpp \
         $$PWD/src/main.cpp
OBJECTS_DIR= $$PWD/obj
HEADERS+=$$PWD/include/TornadoCurve.h
INCLUDEPATH+=$$PWD/include

OTHER_FILES+= README.mp
