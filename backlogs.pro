#-------------------------------------------------
#
# Project created by QtCreator 2018-08-23T13:46:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = backlogs
TEMPLATE = app

CONFIG(debug, debug|release):DESTDIR = $$PWD/build/bin
RC_ICONS = config/myico.ico

SOURCES += main.cpp\
        backlogs.cpp

HEADERS  += backlogs.h

FORMS    += backlogs.ui
