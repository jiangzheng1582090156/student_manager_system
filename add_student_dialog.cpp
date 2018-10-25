#include <QMessageBox>

#include "add_student_dialog.h"
#include "ui_add_student_dialog.h"

add_student_dialog::add_student_dialog(QWidget *parent, QVector<CStudent> * students) :
    QDialog(parent),
    ui(new Ui::add_student_dialog)
{
    ui->setupUi(this);

    m_students = students;

}

add_student_dialog::~add_student_dialog()
{
    delete ui;
}

bool add_student_dialog::check_input()
{
    bool ok = true;
    if (ui->le_stuid->text () == "")
    {
        QMessageBox::information (this, "tip", "id 不能为空");
        ui->le_stuid->setFocus ();
        ok = false;
    }
    else if (ui->le_stuname->text () == "")
    {
        QMessageBox::information (this, "tip", "name 不能为空");
        ui->le_stuname->setFocus ();
        ok = false;
    }
    else if (ui->le_stuage->text () == "")
    {
        QMessageBox::information (this, "tip", "age 不能为空");
        ui->le_stuage->setFocus ();
        ok = false;
    }
    else if (ui->le_stugrade->text () == "")
    {
        QMessageBox::information (this, "tip", "grade 不能为空");
        ui->le_stugrade->setFocus ();
        ok = false;
    }
    else if (ui->le_stuclassid->text () == "")
    {
        QMessageBox::information (this, "tip", "classid 不能为空");
        ui->le_stuclassid->setFocus ();
        ok = false;
    }

    return ok;
}

bool add_student_dialog::check_same_id(const CStudent &student)
{
    for (int i = 0; i < m_students->size (); ++i)
    {
        if (m_students->at (i).stuid () == student.stuid ())
        {
            return false;
        }
    }
    return true;
}

void add_student_dialog::on_btn_cannel_clicked()
{
    int ret = QMessageBox::question (this, "choose", "exit?", QMessageBox::Yes | QMessageBox::No);

    if (QMessageBox::Yes == ret)
    {
        this->close ();
    }
    else
    {
        return ;
    }
}

void add_student_dialog::on_btn_insert_clicked()
{
    if (!check_input ())
    {
        return ;
    }

    CStudent student_temp(
                ui->le_stuid->text (),
                ui->le_stuname->text (),
                ui->le_stuage->text ().toInt (),
                ui->le_stugrade->text (),
                ui->le_stuclassid->text ()
                );
    if (!check_same_id (student_temp))
    {
        QMessageBox::information (this, "error", "id 重复");
        return ;
    }

    m_students->push_back (student_temp);
    this->close ();
}
