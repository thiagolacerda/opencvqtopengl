QT += opengl declarative
TEMPLATE = app

unix {
    INCLUDEPATH += /usr/local/include
        LIBS += -L/usr/local/lib -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc
}

OTHER_FILES = main.qml

macx {
    APP_QML_FILES.files = $$OTHER_FILES

    APP_QML_FILES.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += APP_QML_FILES
}

SOURCES += main.cpp \
    frameshow.cpp \
    opencvgl.cpp
HEADERS += frameshow.h \
    opencvgl.h

