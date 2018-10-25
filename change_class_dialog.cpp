#include "change_class_dialog.h"
#include "ui_change_class_dialog.h"


#include <QMessageBox>

change_class_dialog::change_class_dialog(QWidget *parent, cclass * class_info) :
    QDialog(parent),
    ui(new Ui::change_class_dialog)
{
    m_class_info = class_info;
    ui->setupUi(this);

    init_class_info ();
}

change_class_dialog::~change_class_dialog()
{
    delete ui;
}

void change_class_dialog::init_class_info()
{
    if (m_class_info == NULL)
    {
        QMessageBox::information (this, "error", "class == null");
        return ;
    }
    ui->le_classid->setText (m_class_info->classid ());
    ui->le_classname->setText (m_class_info->classname ());
    ui->le_teachername->setText (m_class_info->leaderteacher ());
}

bool change_class_dialog::check_class_info()
{
    if (ui->le_classid->text () == "" || ui->le_classname->text () == "" || ui->le_teachername->text () == "")
    {
        QMessageBox::information (this, "error", "内容不能为空");
        return false;
    }
    return true;
}


//cannel
void change_class_dialog::on_btn_cannel_clicked()
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


//save changes
void change_class_dialog::on_btn_insert_clicked()
{
    if (check_class_info ())
    {
        m_class_info->setClassid (ui->le_classid->text ());
        m_class_info->setClassname (ui->le_classname->text ());
        m_class_info->setLeaderteacher (ui->le_teachername->text ());
        this->close ();
    }


}
