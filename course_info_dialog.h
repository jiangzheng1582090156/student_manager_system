#ifndef COURSE_INFO_DIALOG_H
#define COURSE_INFO_DIALOG_H

#include <QDialog>
#include <QVector>
#include <QStandardItem>
#include <QStandardItemModel>
#include "ccourse.h"

namespace Ui {
class course_info_dialog;
}

class course_info_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit course_info_dialog(QVector<ccourse> * courses = NULL, QWidget *parent = 0 );
    ~course_info_dialog();

    void add_course_model_item();
    void set_dialog_title();
private:
    Ui::course_info_dialog *ui;

    QVector<ccourse> * m_courses;

    QStandardItemModel * lv_course_model;
};

#endif // COURSE_INFO_DIALOG_H
