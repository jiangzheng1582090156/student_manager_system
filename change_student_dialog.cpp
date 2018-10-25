#include "change_student_dialog.h"
#include "ui_change_student_dialog.h"

#include <QMessageBox>
change_student_dialog::change_student_dialog(QWidget *parent, CStudent * student) :
    QDialog(parent),
    ui(new Ui::change_student_dialog)
{
    ui->setupUi(this);

    m_student = student;
    init_student_info ();
}

change_student_dialog::~change_student_dialog()
{
    delete ui;
}

bool change_student_dialog::check_student_info()
{
    if (ui->le_stuid->text () == "" || ui->le_stuname->text () == "" || ui->le_stuage->text () == ""
       || ui->le_stugrade->text () == "" || ui->le_stuclassid->text ()== ""
       )
    {
        return false;
    }
    return true;
}

void change_student_dialog::init_student_info()
{
    if (m_student == NULL)
    {
        QMessageBox::information (this, "tip", "未选择学生");
        return ;
    }

    ui->le_stuid->setText (m_student->stuid ());
    ui->le_stuname->setText (m_student->stuname ());
    ui->le_stuage->setText (QString::number(m_student->age()));
    ui->le_stugrade->setText (m_student->grade ());
    ui->le_stuclassid->setText (m_student->classid ());

}

void change_student_dialog::on_btn_cannel_clicked()
{
    int ret = QMessageBox::question (this, "tip", "exit?", QMessageBox::Yes | QMessageBox::No);
    if (QMessageBox::Yes == ret)
    {
        this->close();
    }
    else
    {
        return ;
    }
}

void change_student_dialog::on_btn_insert_clicked()
{
    if (!check_student_info ())
    {
        QMessageBox::information (this, "tip", "内容不能为空");
        return ;
    }

    if (m_student == NULL)
    {
        return ;
    }

    m_student->setStuid (ui->le_stuid->text ());
    m_student->setStuname (ui->le_stuname->text ());
    m_student->setAge (ui->le_stuage->text ().toInt ());
    m_student->setGrade (ui->le_stugrade->text ());
    m_student->setClassid (ui->le_stuclassid->text ());

    this->close ();
}
