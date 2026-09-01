#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compare()
{
        const QString s1 = ui->password1->text();
        const QString s2 = ui->password2->text();
        if(s1 == s2)
        {
            qDebug() << "相同";
        }
        else
            {
            qDebug() << "不同";
        }

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    (void)arg1;
    compare();
}

void MainWindow::on_password2_textChanged(const QString &arg1)
{
    (void)arg1;
    compare();
}
