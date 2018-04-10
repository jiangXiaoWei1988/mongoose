#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T09:55:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

LIBS +=  libwsock32

TARGET = mongoose
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app


SOURCES += main.cpp \
    mongoose.c

HEADERS += \
    mongoose.h
