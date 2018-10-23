#ifndef ADD_CLASS_DIALOG_H
#define ADD_CLASS_DIALOG_H

#include <QDialog>

#include "cclass.h"
#include "db_operator.h"

namespace Ui {
class add_class_dialog;
}

class add_class_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_class_dialog(QWidget *parent = 0);
    ~add_class_dialog();

private slots:
    void on_btn_cannel_clicked();

    void on_btn_insert_clicked();

private:
    Ui::add_class_dialog *ui;

    db_operator db_oper;
};

#endif // ADD_CLASS_DIALOG_H
