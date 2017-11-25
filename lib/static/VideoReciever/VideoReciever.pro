#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T14:48:37
#
#-------------------------------------------------

QT       += core network widgets

QT       -= gui

TARGET = VideoReciever
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += VideoReciever.cpp

HEADERS += VideoReciever.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Converter/release/ -lConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Converter/debug/ -lConverter
else:unix: LIBS += -L$$OUT_PWD/../Converter/ -lConverter

INCLUDEPATH += $$PWD/../Converter
DEPENDPATH += $$PWD/../Converter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Converter/release/libConverter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Converter/debug/libConverter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Converter/release/Converter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Converter/debug/Converter.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Converter/libConverter.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageSerialization/release/ -lImageSerialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageSerialization/debug/ -lImageSerialization
else:unix:!macx: LIBS += -L$$OUT_PWD/../ImageSerialization/ -lImageSerialization

INCLUDEPATH += $$PWD/../ImageSerialization
DEPENDPATH += $$PWD/../ImageSerialization

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/release/libImageSerialization.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/debug/libImageSerialization.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/release/ImageSerialization.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/debug/ImageSerialization.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/libImageSerialization.a
