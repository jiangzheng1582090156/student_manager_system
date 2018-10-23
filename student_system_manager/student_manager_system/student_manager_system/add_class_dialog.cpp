#include "add_class_dialog.h"
#include "ui_add_class_dialog.h"

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
