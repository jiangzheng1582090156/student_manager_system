/********************************************************************************
** Form generated from reading UI file 'add_class_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CLASS_DIALOG_H
#define UI_ADD_CLASS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add_class_dialog
{
public:
    QPushButton *btn_ok;
    QPushButton *btn_cannel;

    void setupUi(QDialog *add_class_dialog)
    {
        if (add_class_dialog->objectName().isEmpty())
            add_class_dialog->setObjectName(QStringLiteral("add_class_dialog"));
        add_class_dialog->resize(306, 489);
        btn_ok = new QPushButton(add_class_dialog);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(120, 460, 80, 23));
        btn_cannel = new QPushButton(add_class_dialog);
        btn_cannel->setObjectName(QStringLiteral("btn_cannel"));
        btn_cannel->setGeometry(QRect(210, 460, 80, 23));

        retranslateUi(add_class_dialog);

        QMetaObject::connectSlotsByName(add_class_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_class_dialog)
    {
        add_class_dialog->setWindowTitle(QApplication::translate("add_class_dialog", "class_info", nullptr));
        btn_ok->setText(QApplication::translate("add_class_dialog", "ok", nullptr));
        btn_cannel->setText(QApplication::translate("add_class_dialog", "cannel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_class_dialog: public Ui_add_class_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CLASS_DIALOG_H
