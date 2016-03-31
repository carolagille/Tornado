TARGET=Tornado
QT+=gui opengl core
CONFIG+=c++11

isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}

MOC_DIR=moc

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
    include/NGL_Context.h \
    include/Shaders.h

INCLUDEPATH+=$$PWD/include

DESTDIR=./

CONFIG += console


QMAKE_CXXFLAGS+=$$system(Magick++-config --cppflags )
LIBS+=$$system(Magick++-config --ldflags --libs )
macx:CONFIG+=c++11

macx:INCLUDEPATH+=/usr/local/include/ImageMagick-6/

macx:INCLUDEPATH+=/usr/local/include
macx:LIBS+= -L/usr/local/lib/ -lMagick++-6.Q16 -lc++

macx:QMAKE_CXXFLAGS+= -std=c++11 -stdlib=libc++



OTHER_FILES+= README.mp \
              ./shaders/*.glsl

!equals(PWD, $${OUT_PWD}){
        copydata.commands = echo "creating destination dirs" ;
        # now make a dir
        copydata.commands += mkdir -p $$OUT_PWD/shaders ;
        copydata.commands += echo "copying files" ;
        # then copy the files
        copydata.commands += $(COPY_DIR) $$PWD/shaders/* $$OUT_PWD/shaders/ ;
        # now make sure the first target is built before copy
        first.depends = $(first) copydata
        export(first.depends)
        export(copydata.commands)
        # now add it as an extra target
        QMAKE_EXTRA_TARGETS += first copydata
}

NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){
        message("including $HOME/NGL")
        include($(HOME)/NGL/UseNGL.pri)
}
else{
        message("Using custom NGL location")
        include($(NGLDIR)/UseNGL.pri)
}
