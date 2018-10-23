#ifndef ADD_CLASS_DIALOG_H
#define ADD_CLASS_DIALOG_H

#include <QDialog>

#include "cclass.h"

namespace Ui {
class add_class_dialog;
}

class add_class_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_class_dialog(QWidget *parent = 0);
    ~add_class_dialog();

private:
    Ui::add_class_dialog *ui;


    cclass add_class;
};

#endif // ADD_CLASS_DIALOG_H
