#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtCore>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    library_(this)
{
    ui->setupUi(this);
    ui->listView->setModel(&library_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectLibraryPath()
{
    QFileDialog d(this);
    d.setDirectory(library_.path());
    d.setFileMode(QFileDialog::DirectoryOnly);
    if(d.exec())
    {
        library_.rebuild(d.selectedFiles().front());
    }
}

void MainWindow::onItemSelected(QModelIndex index)
{
    showAnimation(library_.data(index, Qt::DisplayRole).toString());
}

void MainWindow::showAnimation(QString path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.png";
    auto names = dir.entryList(nameFilters);
    for(auto& name : names)
    {
        name = dir.filePath(name);
    }
    ui->label->setFiles(names);
}
