#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>

#include "cstudent.h"
#include "cclass.h"
#include "ccourse.h"
#include "db_operator.h"

#include "course_info_dialog.h"
#include "add_class_dialog.h"
#include "change_class_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_author_triggered();

    void on_action_qiut_triggered();

    //初始化班级
    void init_class();
    //添加classItem
    void add_class_model_item();
    //lv_class双击事件
    void on_lv_class_doubleClicked(const QModelIndex &index);

    //Student
    void init_student(QString classid);
    //添加studentItem
    void add_all_student_model_item();
    void add_student_model_item(int i, const CStudent& student);

    //init student model
    void init_student_model();

    //item align center
    void item_text_center(int i);
    //班级课程查询
    void on_btn_course_clicked();
    // 保存修改的学生信息
    void on_btn_save_clicked();
    //add class
    void on_btn_add_class_clicked();
    //change class info
    void on_btn_change_class_clicked();

private:
    Ui::MainWindow *ui;


    QVector<CStudent> * students;
    QVector<cclass> * classes;
    QVector<ccourse> * courses;

    db_operator db_oper;

    QStandardItemModel * lv_class_model;
    QStandardItemModel * lv_student_model;

    course_info_dialog * course_info_dlg;
    add_class_dialog * add_class_dlg;
    change_class_dialog * change_class_dlg;
};

#endif // MAINWINDOW_H
