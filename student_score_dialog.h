#ifndef STUDENT_SCORE_DIALOG_H
#define STUDENT_SCORE_DIALOG_H

#include <QDialog>
#include <QVector>
#include <QStandardItem>
#include <QStandardItemModel>

#include "cscore.h"

namespace Ui {
class student_score_dialog;
}

class student_score_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit student_score_dialog(QWidget *parent = 0, QVector<cscore> * scores = NULL);
    ~student_score_dialog();


    void add_score_model_item();

private slots:
    void on_btn_cannel_clicked();


private:
    Ui::student_score_dialog *ui;

    QStandardItemModel * lv_score_model;


    QVector<cscore> * m_scores;


};

#endif // STUDENT_SCORE_DIALOG_H
