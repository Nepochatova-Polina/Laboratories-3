#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimeEdit>
#include <QLabel>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timeEdit->setTime(QTime(0,0,5,0));
    timer_1s = new QTimer(this);
    timer_2s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(ShowCurTime()));
    QObject::connect(timer_2s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);
    timer_2s->start(1000);



 }
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::UpdateTime(){
    QTime timer(0,0,0,0);
    QTime time = ui->timeEdit->time().addSecs(-1);
    ui->timeEdit->setTime(time);
    ui->labelTimer->setText(time.toString("hh:mm:ss"));
    if(time == timer){
          timer_2s->stop();
          ui->lightLbl->setFixedSize( 60, 60 );
          ui->lightLbl->setStyleSheet( "border-radius: 30px; background-color: red;" );
         }
  }
    
void MainWindow::ShowCurTime(){
     ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
}


void MainWindow:: compare(){
    if(ui->timeEdit->MinuteSection == 8){

    }
}

void MainWindow::on_pbStart1_clicked()
{
     timer_2s->start();
     ui->lightLbl->setStyleSheet( "border-radius: 30px; background-color: white;" );
}

void MainWindow::on_pbStop1_clicked()
{
    timer_2s->stop();
}

void MainWindow::on_pbStart2_clicked()
{
    timer_1s->start();
}

void MainWindow::on_pbStop2_clicked()
{
      timer_1s->stop();
}


void MainWindow::on_actionStartAll_changed()
{
    timer_1s->start();
    timer_2s->start();
    ui->lightLbl->setStyleSheet( "border-radius: 30px; background-color: white;" );

}

void MainWindow::on_actionStop_All_changed()
{
    timer_1s->stop();
    timer_2s->stop();
}
