#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    students = new QVector<CStudent>();
    classes = new QVector<cclass>();
    courses = new QVector<ccourse>();

    //初始化数据库
    if(!db_oper.create_connect())
    {
        QMessageBox::information(0, QObject::tr("Tips"), QObject::tr(" 连接数据库失败！！！ "));
        return;
    }
    else
        QMessageBox::information(0, QObject::tr("Tips"), QObject::tr(" 连接数据库成功！！！ "));

    add_class_dlg = NULL;
    course_info_dlg = NULL;


    lv_class_model = new QStandardItemModel(this);
    ui->lv_class->setModel(lv_class_model);

    lv_student_model = new QStandardItemModel(this);
    init_student_model();
    ui->tv_student_info->setModel(lv_student_model);

    init_class();
}

MainWindow::~MainWindow()
{
    delete ui;

    if (classes != NULL)
        delete classes;
    if (students != NULL)
        delete students;
    if (courses != NULL)
        delete courses;

    if (add_class_dlg != NULL)
        delete add_class_dlg;
    if (course_info_dlg != NULL)
        delete course_info_dlg;
}

//初始化班级
void MainWindow::init_class()
{
    if (this->classes != NULL)
    {
        delete classes;
        classes = NULL;
    }
    this->classes = db_oper.get_all_class();

    add_class_model_item();
}
//添加classItem
void MainWindow::add_class_model_item()
{
    if (this->classes == NULL)
        return;
    for (int i = 0; i < classes->size(); ++i)
    {
        QStandardItem * item = new QStandardItem(classes->at(i).classname());
        item->setIcon(QIcon(":icons/class.ico"));
        lv_class_model->appendRow(item);
    }
}
//init student model
void MainWindow::init_student_model()
{
    lv_student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    lv_student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("NAME")));
    lv_student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("AGE")));
    lv_student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("GRADE")));
    lv_student_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("CLASS")));

    //设置选中时为整行选中
    ui->tv_student_info->setSelectionBehavior(QAbstractItemView::SelectRows);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->tv_student_info->setContextMenuPolicy(Qt::CustomContextMenu);


}
//item align center
void MainWindow::item_text_center(int i)
{
    //设置单元格文本居中，张三的数据设置为居中显示
    lv_student_model->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    lv_student_model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
    lv_student_model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    lv_student_model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
    lv_student_model->item(i, 4)->setTextAlignment(Qt::AlignCenter);
}

//about author
void MainWindow::on_action_author_triggered()
{
    QMessageBox::information(this, "author", "jiangz");
}

//退出
void MainWindow::on_action_qiut_triggered()
{
    int ret = QMessageBox::question(this, "question", "exit?", QMessageBox::Yes | QMessageBox::No);
    if (QMessageBox::Yes == ret)
        this->close();
    else
        return;

}

//init student
void MainWindow::init_student(QString classid)
{
    students = db_oper.get_class_student(classid);
}

void MainWindow::add_student_model_item()
{
    lv_student_model->clear ();

    for (int i = 0; i < students->size(); ++i)
    {
        lv_student_model->setItem(i, 0, new QStandardItem(students->at(i).stuid()));
        lv_student_model->setItem(i, 1, new QStandardItem(students->at(i).stuname()));
        lv_student_model->setItem(i, 2, new QStandardItem(QString::number(students->at(i).age())));
        lv_student_model->setItem(i, 3, new QStandardItem(students->at(i).grade()));
        lv_student_model->setItem(i, 4, new QStandardItem(students->at(i).classid()));

        item_text_center(i);
    }
}

//lv_class双击事件
void MainWindow::on_lv_class_doubleClicked(const QModelIndex &index)
{
    QString classid = classes->at(index.row()).classid();
    init_student(classid);
    add_student_model_item();
}


void MainWindow::on_btn_course_clicked()
{
    QString classid = classes->at(ui->lv_class->currentIndex().row()).classid();

    QVector<ccourse> * courses = db_oper.get_class_course(classid);


    if (course_info_dlg != NULL)
    {
        delete course_info_dlg;
        course_info_dlg = NULL;
    }

    course_info_dlg = new course_info_dialog(courses, this);
    course_info_dlg->show();
}

// save change status
void MainWindow::on_btn_save_clicked()
{
    if (classes == NULL || students == NULL || courses == NULL)
    {
        QMessageBox::information (this, "error", "save error");
        return ;
    }
    //save classes

    //add student
    CStudent * find_stu = NULL;
    for (int i = 0; i < students->size (); ++i)
    {
        find_stu = db_oper.get_student_by_id (students->at (i).stuid ());

//        if (find_stu != NULL)
//        {
//            db_oper.
//        }
    }
//    CStudent update_stu(
//                lv_student_model->index(current_row, 0).data().toString(),
//                lv_student_model->index(current_row, 1).data().toString(),
//                lv_student_model->index(current_row, 2).data().toInt(),
//                lv_student_model->index(current_row, 3).data().toString(),
//                lv_student_model->index(current_row, 4).data().toString()
//                );

//    bool success = db_oper.save_student_info(update_stu);

//    if (success)
//        QMessageBox::information(this, "tips", "save successful");
//    else
//        QMessageBox::information(this, "tips", "save unsuccessful");
}
//add class
void MainWindow::on_btn_add_class_clicked()
{
    add_class_dlg = new add_class_dialog(this, classes);
    add_class_dlg->exec();

    //update class
    int size = classes->size ();
    if (size == 0)
        return ;
    lv_class_model->appendRow (new QStandardItem (QIcon(":icons/class.ico"), classes->at (size - 1).classname ()));
}
