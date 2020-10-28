#-------------------------------------------------
#
# Project created by QtCreator 2010-09-05T08:51:50
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    form.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    form.ui
