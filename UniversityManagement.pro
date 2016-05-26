#-------------------------------------------------
#
# Project created by QtCreator 2016-04-26T19:17:16
#
#-------------------------------------------------

QT       += core gui sql

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
    newdepartment.cpp \
    BusinessLogic/authorization.cpp \
    loginscreen.cpp \
    student_registration.cpp \
    studentdashboard.cpp \
    students_tab.cpp \
    department_tab.cpp \
    new_department.cpp

HEADERS  += mainwindow.h \
    information.h \
    BusinessLogic/course.h \
    BusinessLogic/department.h \
    BusinessLogic/programme.h \
    BusinessLogic/student.h \
    datahandler.h \
    newdepartment.h \
    BusinessLogic/authorization.h \
    loginscreen.h \
    student_registration.h \
    studentdashboard.h \
    students_tab.h \
    department_tab.h \
    new_department.h

FORMS    += mainwindow.ui \
    information.ui \
    new_department.ui \
    newdepartment.ui \
    loginscreen.ui \
    student_registration.ui \
    studentdashboard.ui \
    students_tab.ui \
    department_tab.ui
