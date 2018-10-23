/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_author;
    QAction *action_qiut;
    QWidget *centralWidget;
    QListView *lv_class;
    QLabel *label;
    QTableView *tv_student_info;
    QPushButton *btn_course;
    QPushButton *btn_save;
    QPushButton *btn_add_class;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(957, 649);
        action_author = new QAction(MainWindow);
        action_author->setObjectName(QStringLiteral("action_author"));
        QFont font;
        font.setPointSize(11);
        action_author->setFont(font);
        action_qiut = new QAction(MainWindow);
        action_qiut->setObjectName(QStringLiteral("action_qiut"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lv_class = new QListView(centralWidget);
        lv_class->setObjectName(QStringLiteral("lv_class"));
        lv_class->setGeometry(QRect(9, 30, 171, 571));
        QFont font1;
        font1.setFamily(QStringLiteral("Hack"));
        font1.setPointSize(10);
        lv_class->setFont(font1);
        lv_class->setEditTriggers(QAbstractItemView::EditKeyPressed);
        lv_class->setTextElideMode(Qt::ElideRight);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 40, 19));
        QFont font2;
        font2.setFamily(QStringLiteral("Hack"));
        font2.setPointSize(11);
        label->setFont(font2);
        tv_student_info = new QTableView(centralWidget);
        tv_student_info->setObjectName(QStringLiteral("tv_student_info"));
        tv_student_info->setGeometry(QRect(189, 30, 757, 570));
        tv_student_info->horizontalHeader()->setDefaultSectionSize(150);
        btn_course = new QPushButton(centralWidget);
        btn_course->setObjectName(QStringLiteral("btn_course"));
        btn_course->setGeometry(QRect(190, 5, 80, 23));
        btn_save = new QPushButton(centralWidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(860, 5, 80, 23));
        btn_add_class = new QPushButton(centralWidget);
        btn_add_class->setObjectName(QStringLiteral("btn_add_class"));
        btn_add_class->setGeometry(QRect(280, 5, 80, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 957, 22));
        menuBar->setFont(font1);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setFont(font1);
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(action_qiut);
        menu_4->addSeparator();
        menu_4->addAction(action_author);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "studnet_manager_system", nullptr));
        action_author->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", nullptr));
        action_qiut->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272 ", nullptr));
        label->setText(QApplication::translate("MainWindow", " \347\217\255\347\272\247", nullptr));
        btn_course->setText(QApplication::translate("MainWindow", "\347\217\255\347\272\247\350\257\276\347\250\213", nullptr));
        btn_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\233\264\346\224\271  ", nullptr));
        btn_add_class->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\247\213 ", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
