QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classmeta.cpp \
    editmeta.cpp \
    editvocabulary.cpp \
    main.cpp \
    mainwindow.cpp \
    md5.cpp \
    meta.cpp \
    newdiscipline.cpp \
    newmeta.cpp \
    newoperator.cpp \
    newoption.cpp \
    newtype_of_obs.cpp \
    workwindowadm.cpp \
    workwindowoper.cpp

HEADERS += \
    classmeta.h \
    editmeta.h \
    editvocabulary.h \
    mainwindow.h \
    md5.h \
    meta.h \
    newdiscipline.h \
    newmeta.h \
    newoperator.h \
    newoption.h \
    newtype_of_obs.h \
    sql.h \
    workwindowadm.h \
    workwindowoper.h

FORMS += \
    editmeta.ui \
    editvocabulary.ui \
    mainwindow.ui \
    meta.ui \
    newdiscipline.ui \
    newmeta.ui \
    newoperator.ui \
    newoption.ui \
    newtype_of_obs.ui \
    workwindowadm.ui \
    workwindowoper.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
