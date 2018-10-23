#include "add_class_dialog.h"
#include "ui_add_class_dialog.h"

#include <QMessageBox>

add_class_dialog::add_class_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_class_dialog)
{
    ui->setupUi(this);
}

add_class_dialog::~add_class_dialog()
{
    delete ui;
}

void add_class_dialog::on_btn_cannel_clicked()
{
    int ret = QMessageBox::question(this, "tip", "exit ?", QMessageBox::Yes | QMessageBox::No);

    if (QMessageBox::Yes == ret)
    {
        this->close();
    }
    else
        return;
}

void add_class_dialog::on_btn_insert_clicked()
{
    QString id = ui->le_classid->text();
    QString name =  ui->le_classname->text();
    QString tname =  ui->le_teachername->text();
    cclass add_class(id, name, tname);

    bool success = db_oper.add_class_info(add_class);
    if (success)
    {
        QMessageBox::information(this, "tip", "success");
    }
    else
    {
        QMessageBox::information(this, "tip", "unsuccess");
    }
}
