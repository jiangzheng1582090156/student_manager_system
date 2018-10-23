/********************************************************************************
** Form generated from reading UI file 'course_info_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSE_INFO_DIALOG_H
#define UI_COURSE_INFO_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_course_info_dialog
{
public:
    QPushButton *btn_cannel;
    QListView *lv_courses;
    QPushButton *btn_save;

    void setupUi(QDialog *course_info_dialog)
    {
        if (course_info_dialog->objectName().isEmpty())
            course_info_dialog->setObjectName(QStringLiteral("course_info_dialog"));
        course_info_dialog->resize(280, 509);
        btn_cannel = new QPushButton(course_info_dialog);
        btn_cannel->setObjectName(QStringLiteral("btn_cannel"));
        btn_cannel->setGeometry(QRect(190, 480, 80, 23));
        QFont font;
        font.setFamily(QStringLiteral("Hack"));
        font.setPointSize(11);
        btn_cannel->setFont(font);
        lv_courses = new QListView(course_info_dialog);
        lv_courses->setObjectName(QStringLiteral("lv_courses"));
        lv_courses->setGeometry(QRect(10, 10, 261, 461));
        btn_save = new QPushButton(course_info_dialog);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(100, 480, 80, 23));
        btn_save->setFont(font);

        retranslateUi(course_info_dialog);

        QMetaObject::connectSlotsByName(course_info_dialog);
    } // setupUi

    void retranslateUi(QDialog *course_info_dialog)
    {
        course_info_dialog->setWindowTitle(QApplication::translate("course_info_dialog", "Dialog", nullptr));
        btn_cannel->setText(QApplication::translate("course_info_dialog", "cannel", nullptr));
        btn_save->setText(QApplication::translate("course_info_dialog", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class course_info_dialog: public Ui_course_info_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSE_INFO_DIALOG_H
