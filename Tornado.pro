TARGET=Tornado
QT+=gui opengl core\

CONFIG+=c++11

isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}

MOC_DIR=moc
CONFIG-=app_bundle
SOURCES+=src/TornadoCurve.cpp \
         src/main.cpp \
    src/Particle.cpp \
    src/ParticleSystem.cpp \
    src/Tornado.cpp \
    src/NGL_Context.cpp \
    src/MainWindow.cpp


HEADERS+=include/TornadoCurve.h \
    include/Particle.h \
    include/ParticleSystem.h \
    include/Tornado.h \
    include/NGL_Context.h \
    include/MainWindow.h

OBJECTS_DIR= $$PWD/obj

INCLUDEPATH+=$$PWD/include

DESTDIR=./

CONFIG += console


QMAKE_CXXFLAGS+=$$system(Magick++-config --cppflags )
LIBS+=$$system(Magick++-config --ldflags --libs )
macx:CONFIG+=c++11
macx:INCLUDEPATH+=/opt/ImageMagick/include/ImageMagick-6/
macx:INCLUDEPATH+=/usr/local/include
macx:LIBS+= -L/opt/ImageMagick/lib/ -lMagick++-6.Q16 -lc++
macx:QMAKE_CXXFLAGS+= -std=c++11 -stdlib=libc++

OTHER_FILES+= \
              ./shaders/*.glsl

!equals(PWD, $${OUT_PWD}){
        copydata.commands = echo "creating destination dirs" ;

        copydata.commands += mkdir -p $$OUT_PWD/shaders ;
        copydata.commands += echo "copying files" ;

        copydata.commands += $(COPY_DIR) $$PWD/shaders/* $$OUT_PWD/shaders/ ;

        first.depends = $(first) copydata
        export(first.depends)
        export(copydata.commands)

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

FORMS += \
    ui/MainWindow.ui
