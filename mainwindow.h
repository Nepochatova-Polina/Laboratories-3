#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimeEdit>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_pb_clicked();
    void UpdateTime();

private:
    Ui::MainWindow *ui;
     QTimer *timer_1s;
     QTime *timer;
     QTimeEdit *timeEdit;
};
#endif // MAINWINDOW_H



