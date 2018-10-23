#include "course_info_dialog.h"
#include "ui_course_info_dialog.h"
#include <QMessageBox>
course_info_dialog::course_info_dialog(QVector<ccourse> * courses, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_info_dialog)
{
    this->m_courses = courses;
    ui->setupUi(this);

    lv_course_model = new QStandardItemModel(this);
    ui->lv_courses->setModel(lv_course_model);

    set_dialog_title();
    add_course_model_item();
}

course_info_dialog::~course_info_dialog()
{
    delete ui;
    if (m_courses != NULL)
        delete m_courses;
}

void course_info_dialog::add_course_model_item()
{
    if (this->m_courses == NULL)
        return;
    for (int i = 0; i < m_courses->size(); ++i)
    {
        QStandardItem * item = new QStandardItem(m_courses->at(i).coursename() + " -- " + m_courses->at(i).teacher());
        item->setIcon(QIcon(":icons/class.ico"));
        lv_course_model->appendRow(item);
    }
}

void course_info_dialog::set_dialog_title()
{
    if (m_courses == NULL)
    {
        QMessageBox::information(this, tr("tips"), tr("not selected class"));
        return;
    }

    this->setWindowTitle(m_courses->at(0).classid() +"--" + "班课程");
}
