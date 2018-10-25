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
    }
    else
        QMessageBox::information(0, QObject::tr("Tips"), QObject::tr(" 连接数据库成功！！！ "));

    add_class_dlg = NULL;
    course_info_dlg = NULL;
    change_class_dlg = NULL;
    add_student_dlg = NULL;
    change_student_dlg = NULL;


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

void MainWindow::add_all_student_model_item()
{
    lv_student_model->clear ();
    init_student_model ();
    for (int i = 0; i < students->size(); ++i)
    {
        add_student_model_item (i, students->at (i));
    }
}
void MainWindow::add_student_model_item(int i, const CStudent& student)
{
    lv_student_model->setItem(i, 0, new QStandardItem(student.stuid()));
    lv_student_model->setItem(i, 1, new QStandardItem(student.stuname()));
    lv_student_model->setItem(i, 2, new QStandardItem(QString::number(student.age())));
    lv_student_model->setItem(i, 3, new QStandardItem(student.grade()));
    lv_student_model->setItem(i, 4, new QStandardItem(student.classid()));

    item_text_center(i);
}

//lv_class双击事件
void MainWindow::on_lv_class_doubleClicked(const QModelIndex &index)
{
    QString classid = classes->at(index.row()).classid();
    init_student(classid);
    add_all_student_model_item();
}


void MainWindow::on_btn_course_clicked()
{
    QString classid = classes->at(ui->lv_class->currentIndex().row()).classid();

    QVector<ccourse> * courses = db_oper.get_class_course(classid);

    if (courses == NULL)
    {
        QMessageBox::information (this, "tip", "暂无该班课程");
        return ;
    }

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
    bool success = true;
    if (classes == NULL || students == NULL || courses == NULL)
    {
        QMessageBox::information (this, "error", "save error");
        return ;
    }

    //save classes
    cclass * find_class = NULL;
    for (int i = 0; i < classes->size (); ++i)
    {
        find_class = db_oper.get_class_by_id (classes->at (i).classid ());

        if (find_class == NULL)
        {
            success = db_oper.insert_class_info (classes->at (i));
        }
        else
        {
            delete find_class;
            find_class = NULL;
        }
    }

    //save student
    CStudent * find_stu = NULL;
    for (int i = 0; i < students->size (); ++i)
    {
        find_stu = db_oper.get_student_by_id (students->at (i).stuid ());

        if (find_stu == NULL)
        {
            success = db_oper.insert_student_info (students->at(i));
        }
        else
        {
            delete find_stu;
            find_stu = NULL;
        }
    }

    //save course
    ccourse * find_course = NULL;
    for (int i = 0; i < courses->size (); ++i)
    {
        find_course = db_oper.get_course_by_id (courses->at (i).courseid (), courses->at (i).classid ());

        if (find_course == NULL)
        {
            success = db_oper.insert_course_info (courses->at(i));
        }
        else
        {
            delete find_course;
            find_course = NULL;
        }
    }

    if (success)
    {
        QMessageBox::information (this, "tip", "save successful");
        return;
    }
    else
    {
        QMessageBox::information (this, "tip", "save unsuccessful");
        return;
    }

}
//add class
void MainWindow::on_btn_add_class_clicked()
{
    int old_size = classes->size ();

    add_class_dlg = new add_class_dialog(this, classes);
    add_class_dlg->exec();

    //update class
    int size = classes->size ();
    if (size == 0 || size == old_size)
    {
        QMessageBox::information (this, "tip", "add class unsuccessful");
        return ;
    }
    cclass class_temp = classes->at (size - 1);
    lv_class_model->appendRow (new QStandardItem (QIcon(":icons/class.ico"), class_temp.classname ()));


    if (db_oper.insert_class_info (class_temp))
    {
        QMessageBox::information (this, "tip", "add class successful");
    }
    else
    {
        QMessageBox::information (this, "tip", "add class unsuccessful");
    }
}

//change class info
void MainWindow::on_btn_change_class_clicked()
{
    if (change_class_dlg != NULL)
    {
        delete change_class_dlg;
        change_class_dlg = NULL;
    }

    int index = ui->lv_class->currentIndex ().row ();

    cclass class_temp = classes->at (index);

    change_class_dlg = new change_class_dialog(this, &class_temp);
    change_class_dlg->exec ();

    //如果class_temp 和 index指向的class不同则更改

    if (class_temp == classes->at (index))
        return;

    lv_class_model->removeRow (index);
    classes->removeAt (index);

    lv_class_model->insertRow (index, new QStandardItem(QIcon(":icons/class.ico"), class_temp.classname ()));
    classes->insert (index, class_temp);

    if (db_oper.update_class_info (class_temp))
    {
        QMessageBox::information (this, "tip", "save successful");
    }
    else
    {
        QMessageBox::information (this, "tip", "svae unsuccessful");
    }
}

//delete class
void MainWindow::on_btn_delete_class_clicked()
{
    int current_index = ui->lv_class->currentIndex ().row ();
    if (current_index == -1)
    {
        QMessageBox::information (this, "tip", "未选中删除班级");
        return ;
    }

    bool success = db_oper.delete_class_info (classes->at (current_index));
    if (success)
    {
        QMessageBox::information (this, "tip", "delete successful");
        lv_class_model->removeRow (current_index);
        classes->removeAt (current_index);
        return;
    }
    else
    {
        QMessageBox::information (this, "tip", "delete unsucessful");
        return ;
    }
}


//全部学生
void MainWindow::on_btn_all_student_clicked()
{
    students = db_oper.get_all_student ();
    add_all_student_model_item ();
}
//add_student
void MainWindow::on_btn_add_student_clicked()
{
    if (add_student_dlg != NULL)
    {
        delete add_student_dlg;
        add_student_dlg = NULL;
    }

    int old_size =  students->size ();
    add_student_dlg = new add_student_dialog(this, students);
    add_student_dlg->exec ();

    if (old_size == students->size ())
    {
        QMessageBox::information (this, "tip", "add student unsuccessful");
        return ;
    }

    CStudent stu_temp = students->at (students->size () - 1);
    //添加model
    add_student_model_item (lv_student_model->rowCount (), stu_temp);
    //添加数据库
    bool success = db_oper.insert_student_info (stu_temp);
    if (success)
    {
        QMessageBox::information (this, "tip", "add student successful");
    }
    else
    {
        QMessageBox::information (this, "tip", "add student unsuccessful");
    }

}

//change student info
void MainWindow::on_btn_change_student_clicked()
{
    if (change_student_dlg != NULL)
    {
        delete change_student_dlg;
        change_student_dlg = NULL;
    }

    int index = ui->lv_class->currentIndex ().row ();

    CStudent student_temp = students->at (index);

    change_student_dlg = new change_student_dialog(this, &student_temp);
    change_student_dlg->exec ();

    //student_temp 和 index指向的student不同则更改

    if (student_temp == students->at (index))
        return;

    lv_student_model->removeRow (index);
    students->removeAt (index);

    add_student_model_item (index, student_temp);

    students->insert (index, student_temp);

    if (db_oper.update_student_info (student_temp))
    {
        QMessageBox::information (this, "tip", "save student successful");
    }
    else
    {
        QMessageBox::information (this, "tip", "svae student unsuccessful");
    }
}
