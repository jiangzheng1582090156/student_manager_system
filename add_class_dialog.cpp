#include "add_class_dialog.h"
#include "ui_add_class_dialog.h"

#include <QMessageBox>

add_class_dialog::add_class_dialog(QWidget *parent, QVector<cclass> * classes) :
    QDialog(parent),
    ui(new Ui::add_class_dialog)
{
    this->m_classes = classes;
    ui->setupUi(this);
}

add_class_dialog::~add_class_dialog()
{
    delete ui;
}

void add_class_dialog::on_btn_cannel_clicked()
{
    if (ui->le_classid->text () != "" || ui->le_classname->text () != "" || ui->le_teachername->text () != "")
    {
        int ret = QMessageBox::question(this, "tip", "exit ?", QMessageBox::Yes | QMessageBox::No);

        if (QMessageBox::Yes == ret)
        {
            this->close();
        }
        else
            return;
    }
    else
    {
        this->close ();
    }


}

void add_class_dialog::on_btn_insert_clicked()
{
    QString id = ui->le_classid->text();
    QString name =  ui->le_classname->text();
    QString tname =  ui->le_teachername->text();

    if (id == "" || name == "" || tname == "")
    {
        QMessageBox::information (this, "tip", "信息不为空");
        return ;
    }

    if (input_check () == false)
    {
        return;
    }

    cclass add_class(id, name, tname);

    m_classes->push_back (add_class);
    this->close();
}

bool add_class_dialog::input_check()
{
    for (int i = 0; i < m_classes->size (); ++i)
    {
        if (m_classes->at (i).classid () == ui->le_classid->text ())
        {
            QMessageBox::information (this, "tip", "id已存在");
            ui->le_classid->setFocus ();
            return false;
        }
        else if (m_classes->at (i).classname ()== ui->le_classid->text ())
        {
            QMessageBox::information (this, "tip", "name已存在");
            ui->le_classname->setFocus ();
            return false;
        }
    }

    return true;
}
