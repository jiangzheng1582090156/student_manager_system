#ifndef CHANGE_STUDENT_DIALOG_H
#define CHANGE_STUDENT_DIALOG_H

#include <QDialog>

#include "cstudent.h"

namespace Ui {
class change_student_dialog;
}

class change_student_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit change_student_dialog(QWidget *parent = 0, CStudent * student = NULL);
    ~change_student_dialog();

    bool check_student_info();

    void init_student_info();

private slots:
    void on_btn_cannel_clicked();

    void on_btn_insert_clicked();

private:
    Ui::change_student_dialog *ui;

    CStudent * m_student;
};

#endif // CHANGE_STUDENT_DIALOG_H
