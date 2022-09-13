QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

CONFIG(debug, debug|release) {
 TARGET = ../../bin/ComboTreeD
 DESTDIR = $$PWD/bin
 DEFINES += USE_DEBUG
} else {
 TARGET = ../../bin/ComboTree
 DESTDIR = $$PWD/bin
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TreeModel.cpp \
    TreeNode.cpp \
    combotree.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    TreeModel.h \
    TreeNode.h \
    combotree.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
