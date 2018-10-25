#-------------------------------------------------
#
# Project created by QtCreator 2018-10-18T14:07:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student_manager_system
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cstudent.cpp \
    cclass.cpp \
    ccourse.cpp \
    db_operator.cpp \
    course_info_dialog.cpp \
    add_class_dialog.cpp \
    change_class_dialog.cpp

HEADERS += \
        mainwindow.h \
    cstudent.h \
    cclass.h \
    ccourse.h \
    db_operator.h \
    course_info_dialog.h \
    add_class_dialog.h \
    change_class_dialog.h

FORMS += \
        mainwindow.ui \
    course_info_dialog.ui \
    add_class_dialog.ui \
    change_class_dialog.ui

DISTFILES +=

RESOURCES += \
    icons/student_manager.qrc
