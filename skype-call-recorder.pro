
TEMPLATE = app
TARGET = skype-call-recorder
DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES = common.cpp recorder.cpp trayicon.cpp skype.cpp preferences.cpp call.cpp writer.cpp wavewriter.cpp mp3writer.cpp
HEADERS = common.h   recorder.h   trayicon.h   skype.h   preferences.h   call.h   writer.h   wavewriter.h   mp3writer.h

HEADERS += smartwidgets.h

RESOURCES = resources.qrc

LIBS += -lmp3lame

CONFIG += qdbus
QT += network
