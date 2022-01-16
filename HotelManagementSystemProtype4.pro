#-------------------------------------------------
#
# Project created by QtCreator 2021-07-13T12:34:41
#
#-------------------------------------------------

QT       += core gui
QT       += sql xml multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelManagementSystemProtype4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    checkinsystem.cpp \
    checkoutsystem.cpp \
    reservelist.cpp \
    searchlist.cpp \
    connection.cpp \
    help.cpp \
    roomstatus.cpp \
    register.cpp \
    signup.cpp \
    backstage.cpp \
    otherservice.cpp \
    clienthomepage.cpp \
    clientsignup.cpp \
    notice.cpp \
    map.cpp \
    traveltip.cpp

HEADERS += \
        widget.h \
    checkinsystem.h \
    checkoutsystem.h \
    reservelist.h \
    searchlist.h \
    connection.h \
    help.h \
    roomstatus.h \
    register.h \
    signup.h \
    backstage.h \
    otherservice.h \
    clienthomepage.h \
    clientsignup.h \
    notice.h \
    map.h \
    traveltip.h

FORMS += \
        widget.ui \
    checkinsystem.ui \
    checkoutsystem.ui \
    reservelist.ui \
    searchlist.ui \
    help.ui \
    roomstatus.ui \
    register.ui \
    signup.ui \
    backstage.ui \
    otherservice.ui \
    clienthomepage.ui \
    clientsignup.ui \
    notice.ui \
    map.ui \
    traveltip.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    search.qrc \
    otherimages.qrc
