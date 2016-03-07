TARGET=Tornado
QT+=gui opengl core
CONFIG+=c++11

SOURCES+=$$PWD/src/TornadoCurve.cpp \
         $$PWD/src/main.cpp \
    src/Particle.cpp \
    src/ParticleSystem.cpp \
    src/Tornado.cpp \
    src/NGL_Context.cpp
OBJECTS_DIR= $$PWD/obj

HEADERS+=$$PWD/include/TornadoCurve.h \
    include/Particle.h \
    include/ParticleSystem.h \
    include/Tornado.h \
    include/NGL_Context.h

INCLUDEPATH+=$$PWD/include


OTHER_FILES+= README.mp

NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){
        message("including $HOME/NGL")
        include($(HOME)/NGL/UseNGL.pri)
}
else{
        message("Using custom NGL location")
        include($(NGLDIR)/UseNGL.pri)
}
