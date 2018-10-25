#ifndef ADD_STUDENT_DIALOG_H
#define ADD_STUDENT_DIALOG_H

#include <QDialog>
#include <QVector>

#include "cstudent.h"

namespace Ui {
class add_student_dialog;
}

class add_student_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_student_dialog(QWidget *parent = 0, QVector<CStudent> * students = NULL);
    ~add_student_dialog();


    bool check_input();
    bool check_same_id(const CStudent & student);



private slots:
    void on_btn_cannel_clicked();

    void on_btn_insert_clicked();

private:
    Ui::add_student_dialog *ui;

    QVector<CStudent> * m_students;
};

#endif // ADD_STUDENT_DIALOG_H
