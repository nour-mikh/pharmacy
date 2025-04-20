QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    DatabaseManager.cpp \
    Employee.cpp \
    Manager.cpp \
    Medicine.cpp \
    Person.cpp \
    Sale.cpp \
    SalesItem.cpp \
    main.cpp \
    mainwindow.cpp \
    medui.cpp \
    personui.cpp \
    receipt.cpp \
    selectroleui.cpp \
    viewitems.cpp

HEADERS += \
    Client.h \
    DatabaseManager.h \
    Employee.h \
    Manager.h \
    Medicine.h \
    Person.h \
    Sale.h \
    SalesItem.h \
    mainwindow.h \
    medui.h \
    personui.h \
    receipt.h \
    selectroleui.h \
    viewitems.h

FORMS += \
    mainwindow.ui \
    medui.ui \
    personui.ui \
    receipt.ui \
    selectroleui.ui \
    viewitems.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += sql

DISTFILES +=
