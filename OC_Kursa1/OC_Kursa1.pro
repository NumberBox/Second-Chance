QT       += core gui

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
    dialog.cpp \
    label_clic.cpp \
    main.cpp \
    page.cpp \
    widget.cpp

HEADERS += \
    dialog.h \
    label_clic.h \
    page.h \
    widget.h

FORMS += \
    dialog.ui \
    page.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurs.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/OC_Kyrsa_dynamic_lib/release/ -lOC_Kyrsa_dynamic_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/OC_Kyrsa_dynamic_lib/debug/ -lOC_Kyrsa_dynamic_lib

INCLUDEPATH += $$PWD/OC_Kyrsa_dynamic_lib/include
DEPENDPATH += $$PWD/OC_Kyrsa_dynamic_lib/include

