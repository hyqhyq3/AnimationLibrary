#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T12:17:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimationLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animationpreviewer.cpp \
    animationlibrary.cpp

HEADERS  += mainwindow.h \
    animationpreviewer.h \
    animationlibrary.h

FORMS    += mainwindow.ui

RC_FILE += myapp.rc

OTHER_FILES += \
    myapp.rc

ICON += animation.icns
