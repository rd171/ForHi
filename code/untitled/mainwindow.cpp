#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_p1 = new QImageCtrl(this);
    m_p2 = new QResManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
