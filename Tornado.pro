TARGET=Tornado
QT+=opengl
CONFIG+=c++11

SOURCES+=$$PWD/src/TornadoCurve.cpp \
         $$PWD/src/main.cpp \
    src/Organizer.cpp \
    src/ParticleSubsystem.cpp
OBJECTS_DIR= $$PWD/obj

HEADERS+=$$PWD/include/TornadoCurve.h \
    include/ParticleSubsystem.h \
    include/Particle.h \
    include/Organizer.h

INCLUDEPATH+=$$PWD/include


OTHER_FILES+= README.mp

