#include "student_score_dialog.h"
#include "ui_student_score_dialog.h"

#include <QMessageBox>

student_score_dialog::student_score_dialog(QWidget *parent, QVector<cscore> * scores) :
    QDialog(parent),
    ui(new Ui::student_score_dialog)
{
    ui->setupUi(this);

    m_scores = scores;

    lv_score_model = new QStandardItemModel(this);
    add_score_model_item ();
    ui->lv_student_score->setModel (lv_score_model);

}

student_score_dialog::~student_score_dialog()
{
    delete ui;
}

void student_score_dialog::add_score_model_item()
{
    if (m_scores == NULL)
    {
        QMessageBox::information (this, "tip", "成绩未空");
        return ;
    }


    for (int i = 0; i < m_scores->size (); ++i)
    {
        QString info = m_scores->at (i).courseid () + "-" + m_scores->at (i).score ();
        lv_score_model->appendRow (new QStandardItem(info));
    }
}



//cannel
void student_score_dialog::on_btn_cannel_clicked()
{
    int ret = QMessageBox::question(this, "tip", "exit ?", QMessageBox::Yes | QMessageBox::No);

    if (QMessageBox::Yes == ret)
    {
        this->close();
    }
    else
        return;
}
