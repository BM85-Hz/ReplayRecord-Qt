QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abouttab.cpp \
    calendartab.cpp \
    liststab.cpp \
    logmaker.cpp \
    main.cpp \
    mainwindow.cpp \
    networkrequestmanager.cpp \
    searchtab.cpp \
    stopwatch.cpp

HEADERS += \
    abouttab.h \
    calendartab.h \
    liststab.h \
    logmaker.h \
    mainwindow.h \
    networkrequestmanager.h \
    searchtab.h \
    stopwatch.h

FORMS += \
    mainwindow.ui

QT += network

RC_ICONS = myappico.ico
VERSION = 1.0.3.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
