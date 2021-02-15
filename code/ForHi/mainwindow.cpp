#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized|Qt::WindowActive);
    m_pRecentImgCtrl        = new QImageCtrl(this);
    m_pFavoriteImgCtrl      = new QImageCtrl(this);
    m_pQResManager          = new QResManager(this);

    m_WorkspaceLayout.addLayout(&m_LeftLayout);
    m_WorkspaceLayout.addLayout(&m_RightLayout);
    m_LeftLayout.addWidget(m_pRecentImgCtrl);
    m_LeftLayout.addWidget(m_pFavoriteImgCtrl);
    m_RightLayout.addWidget(m_pQResManager);
}

MainWindow::~MainWindow()
{
    delete ui;
}
