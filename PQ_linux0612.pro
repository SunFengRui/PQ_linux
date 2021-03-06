#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T22:22:31
#
#-------------------------------------------------

QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PQ_linux0612
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
        V_Dip_Swell_Interrupt.cpp \
        data.cpp \
        dlist.cpp \
        main.cpp \
        net_init.cpp \
        pq_linux.cpp \
        socket_send.cpp \
        tool.cpp \
        workthread.cpp

HEADERS += \
        data.h \
        dlist.h \
        main.h \
        net_init.h \
        pq_linux.h \
        socket_send.h \
        tool.h \
        workthread.h

FORMS += \
        pq_linux.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/libpcap-1.9.1/release/ -lpcap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/libpcap-1.9.1/debug/ -lpcap
else:unix: LIBS += -L$$PWD/../../../../tools/libpcap-1.9.1/ -lpcap

INCLUDEPATH += $$PWD/../../../../tools/libpcap-1.9.1
DEPENDPATH += $$PWD/../../../../tools/libpcap-1.9.1

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tools/libpcap-1.9.1/release/libpcap.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tools/libpcap-1.9.1/debug/libpcap.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tools/libpcap-1.9.1/release/pcap.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tools/libpcap-1.9.1/debug/pcap.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../tools/libpcap-1.9.1/libpcap.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/fftw-3.3.8/lib/release/ -lfftw3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/fftw-3.3.8/lib/debug/ -lfftw3
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/fftw-3.3.8/lib/ -lfftw3

INCLUDEPATH += $$PWD/../../../../../../usr/local/fftw-3.3.8/include
DEPENDPATH += $$PWD/../../../../../../usr/local/fftw-3.3.8/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/fftw-3.3.8/lib/release/libfftw3.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/fftw-3.3.8/lib/debug/libfftw3.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/fftw-3.3.8/lib/release/fftw3.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/fftw-3.3.8/lib/debug/fftw3.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/fftw-3.3.8/lib/libfftw3.a
