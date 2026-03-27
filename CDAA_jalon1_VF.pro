QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichercontact.cpp \
    ajoutcontact.cpp \
    ajoutinteraction.cpp \
    basededonnee.cpp \
    contact.cpp \
    formcontact.cpp \
    formmodifcontact.cpp \
    gestioncontact.cpp \
    gestioninteraction.cpp \
    gestiontache.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    tache.cpp

HEADERS += \
    affichercontact.h \
    ajoutcontact.h \
    ajoutinteraction.h \
    basededonnee.h \
    contact.h \
    formcontact.h \
    formmodifcontact.h \
    gestioncontact.h \
    gestioninteraction.h \
    gestiontache.h \
    interaction.h \
    mainwindow.h \
    tache.h

FORMS += \
    affichercontact.ui \
    ajoutcontact.ui \
    ajoutinteraction.ui \
    formcontact.ui \
    formmodifcontact.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icones.qrc
