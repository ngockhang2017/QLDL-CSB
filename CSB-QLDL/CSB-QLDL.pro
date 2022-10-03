QT       += core gui
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets sql

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
    cuuho.cpp \
    dialog_suaxoa.cpp \
    dialog_themtaikhoan.cpp \
    dialog_themtau.cpp \
    dialog_xuatfile.cpp \
    khac.cpp \
    main.cpp \
    mainwindow.cpp \
    ungpho.cpp \
    vipham.cpp

HEADERS += \
    cuuho.h \
    dialog_suaxoa.h \
    dialog_themtaikhoan.h \
    dialog_themtau.h \
    dialog_xuatfile.h \
    khac.h \
    mainwindow.h \
    ungpho.h \
    vipham.h

FORMS += \
    cuuho.ui \
    dialog_suaxoa.ui \
    dialog_themtaikhoan.ui \
    dialog_themtau.ui \
    dialog_xuatfile.ui \
    khac.ui \
    mainwindow.ui \
    ungpho.ui \
    vipham.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
