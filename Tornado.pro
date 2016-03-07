TARGET=Tornado
QT+=opengl
CONFIG+=c++11

SOURCES+=$$PWD/src/TornadoCurve.cpp \
         $$PWD/src/main.cpp \
    src/Particle.cpp \
    src/ParticleSystem.cpp \
    src/Tornado.cpp
OBJECTS_DIR= $$PWD/obj

HEADERS+=$$PWD/include/TornadoCurve.h \
    include/Particle.h \
    include/ParticleSystem.h \
    include/Tornado.h

INCLUDEPATH+=$$PWD/include


OTHER_FILES+= README.mp

