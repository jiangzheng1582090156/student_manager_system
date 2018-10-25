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
