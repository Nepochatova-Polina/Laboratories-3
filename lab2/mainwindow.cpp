#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QTextEdit>
#include<QString>
#include<QMessageBox>
#include<QList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    ui->setupUi(this);


   }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_pb_clicked()
{
    QString x = ui->plainTextEdit->toPlainText();
    ui->listWidget->addItem(QDateTime::currentDateTime().toString() + "    " + x);
    Noteslist.append(x);

}

void MainWindow::on_actiondeleteAll_triggered()
{
   ui->listWidget->clear();
   Noteslist.clear();
}

void MainWindow::on_actionDeleteOne_triggered()
{
   delete ui->listWidget->currentItem();
}

void MainWindow::on_actionHelp_triggered()
{
   QMessageBox::about(this,"Help box", " Hi, this page will explain what each icon means. With the help of a second icon, you can delete all records. "
                                       "To delete a specific one, select it in the list and click on the third icon. "
                                       "To archive a recording, select it from the list and click on the fourth icon."
                                       "To see all completed notes, click on the last icon");
}

void MainWindow::on_actionDone_triggered()
{
   list.push_back(ui->listWidget->currentItem()->text());
   delete ui->listWidget->currentItem();


}

void MainWindow::on_actionShowDone_triggered()
{
   QList<QString>::iterator it = list.begin();
   QString x;
   int i=0;
   while(it != list.end()){
       x += list[i];
       x += "  ";
       i++;
       it++;
   }
    QMessageBox::about(this,"Archive", x);
}
