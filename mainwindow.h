#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animationlibrary.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void selectLibraryPath();

    void onItemSelected(QModelIndex index);

private slots:
    void on_pushButton_clicked();

private:
    void showAnimation(QString path);

private:
    Ui::MainWindow *ui;
    AnimationLibrary library_;
};

#endif // MAINWINDOW_H
