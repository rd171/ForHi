#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "../GUI/qimagedraw.h"
#include "../FILE/CDriveIndex.h"

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

    wstring str_dir = L"d:\\";
    //CDriveIndex m(str_dir);
    CDriveIndex m;
    BOOL bRet = m.Init('d');
    wstring strQuery                       = L".jpg";
    wstring strQueryPath                   = L"";
    vector<SearchResultFile> *rgsrfResults  = new vector<SearchResultFile>;
    int nRet = m.Find(&strQueryPath, &strQueryPath, rgsrfResults);

    m_pRecentImgCtrl->SetColumnAndRow(4, 2);
    m_pRecentImgCtrl->ShowImg(0, 0, "..\\test.jpg");

    m_pFavoriteImgCtrl->SetColumnAndRow(4, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewPicture()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select a picture"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("File(*.*)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();
    }
    if ( fileNames.size() > 0 )
    {
        QImageDraw* pic = new QImageDraw();
        pic->setWindowTitle(fileNames.at(0));
        pic->show();
        pic->resize(800, 600);
        pic->ShowImage(fileNames.at(0));
    }

}
