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

    void on_actiondeleteAll_triggered();

    void on_actionDeleteOne_triggered();

    void on_actionHelp_triggered();

    void on_actionDone_triggered();

    void on_actionShowDone_triggered();

private:
    Ui::MainWindow *ui;
     QList <QString> list;
     QList <QString> Noteslist;

};
#endif // MAINWINDOW_H

