#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QTime>
#include<QLabel>
#include<QTextEdit>
#include<QString>
#include<QTimeEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    ui->setupUi(this);
     ui->lightLbl->setFixedSize( 60, 60 );
     ui->lightLbl->setStyleSheet( "border-radius: 30px; background-color: white;" );
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Add_pb_clicked()
{
    QString x = ui->plainTextEdit->toPlainText();
    ui->listWidget->addItem( x);
     *timer = QTime::fromString(x, "hh:mm:ss");

    
}


void MainWindow::UpdateTime(){
    QTime time(0,0,0,0);
    ui->listWidget->addItem(timer->toString("hh:mm:ss"));
    *timer = timeEdit->time().addSecs(-1);
    delete ui->listWidget->takeItem(1);
    ui->listWidget->addItem(timer->toString("hh:mm:ss"));
    if(*timer == time){
          timer_1s->stop();
          ui->lightLbl->setFixedSize( 60, 60 );
          ui->lightLbl->setStyleSheet( "border-radius: 30px; background-color: red;" );
         }
  }






