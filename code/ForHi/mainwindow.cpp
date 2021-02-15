#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized|Qt::WindowActive);
    m_pRecentImgCtrl        = new QImageGrid(this);
    m_pFavoriteImgCtrl      = new QImageGrid(this);
    m_pQResManager          = new QResManager(this);
    connect(m_pQResManager, SIGNAL(ClickViewBtn()), this, SLOT(ViewPicture()));
    m_pRecentImgCtrl->SetTitle(tr("Recent Picture"));
    m_pFavoriteImgCtrl->SetTitle(tr("Favorite Picture"));
    m_pQResManager->SetTitle(tr("File Manager"));

    m_WorkspaceLayout.addLayout(&m_LeftLayout);
    m_WorkspaceLayout.addLayout(&m_RightLayout);
    m_LeftLayout.addWidget(m_pRecentImgCtrl);
    m_LeftLayout.addWidget(m_pFavoriteImgCtrl);
    m_RightLayout.addWidget(m_pQResManager);

    m_pRecentImgCtrl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_pFavoriteImgCtrl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_pQResManager->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_WorkspaceLayout.setStretchFactor(&m_LeftLayout, 3);
    m_WorkspaceLayout.setStretchFactor(&m_RightLayout, 1);
    m_WorkspaceLayout.setSpacing(2);
    m_LeftLayout.setStretchFactor(m_pRecentImgCtrl, 2);
    m_LeftLayout.setStretchFactor(m_pFavoriteImgCtrl, 1);
    centralWidget()->setLayout(&m_WorkspaceLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewPicture()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}
