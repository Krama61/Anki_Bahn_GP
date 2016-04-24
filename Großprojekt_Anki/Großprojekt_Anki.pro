TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/include/glib-2.0/glib
INCLUDEPATH += /usr/lib/x86_64-linux-gnu/glib-2.0/include/
LIBS += -lglib-2.0
LIBS += -lreadline

SOURCES += main.c \
    att.c \
    bluetooth.c \
    btio.c \
    gatt.c \
    gattrib.c \
    hci.c \
    log.c \
    sdp.c \
    utils.c \
    bluetooth_uuid.c \
    advertisement.c \
    anki_util.c \
    eir.c \
    protocol.c \
    uuid.c \
    display.c \
    unterprogramme_flo.c \
    unterprogramme_max.c \
    unterprogramme_norre.c

HEADERS += \
    bluetooth.h \
    btio.h \
    hci.h \
    hci_lib.h \
    l2cap.h \
    sco.h \
    sdp.h \
    sdp_lib.h \
    bluetooth_uuid.h \
    att.h \
    gatt.h \
    gattrib.h \
    utils.h \
    log.h \
    advertisement.h \
    anki_util.h \
    common.h \
    eir.h \
    protocol.h \
    uuid.h \
    vehicle_gatt_profile.h \
    ankidrive.h \
    version.h \
    uthash.h \
    display.h

