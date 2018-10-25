#ifndef CHANGE_CLASS_DIALOG_H
#define CHANGE_CLASS_DIALOG_H

#include <QDialog>

#include "cclass.h"

namespace Ui {
class change_class_dialog;
}

class change_class_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit change_class_dialog(QWidget *parent = 0, cclass * class_info = NULL);
    ~change_class_dialog();

    void init_class_info();

    bool check_class_info();
private slots:
    void on_btn_cannel_clicked();

    void on_btn_insert_clicked();

private:
    Ui::change_class_dialog *ui;

    cclass * m_class_info;
};

#endif // CHANGE_CLASS_DIALOG_H
