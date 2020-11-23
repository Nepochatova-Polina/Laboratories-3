#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTimeEdit>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void UpdateTime();
    void ShowCurTime();
    void compare();

    void on_pbStart1_clicked();
    void on_pbStop1_clicked();
    void on_pbStart2_clicked();
    void on_pbStop2_clicked();



    void on_actionStartAll_changed();
    void on_actionStop_All_changed();

private:
    Ui::MainWindow *ui;

    QTimer *timer_1s;
    QTimer *timer_2s;
    QTimeEdit *timeEdit;
};


#endif // MAINWINDOW_H
