#-------------------------------------------------
#
# Project created by QtCreator 2016-04-26T19:17:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UniversityManagement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    information.cpp \
    BusinessLogic/course.cpp \
    BusinessLogic/department.cpp \
    BusinessLogic/programme.cpp \
    BusinessLogic/student.cpp \
    datahandler.cpp \
    newdepartment.cpp

HEADERS  += mainwindow.h \
    information.h \
    BusinessLogic/course.h \
    BusinessLogic/department.h \
    BusinessLogic/programme.h \
    BusinessLogic/student.h \
    datahandler.h \
    newdepartment.h

FORMS    += mainwindow.ui \
    information.ui \
    new_department.ui \
    newdepartment.ui
