#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../GUI/qimagectrl.h"
#include "../GUI/qresmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QHBoxLayout    m_WorkspaceLayout;
    QVBoxLayout    m_LeftLayout;
    QVBoxLayout    m_RightLayout;

    QImageCtrl*     m_pRecentImgCtrl;
    QImageCtrl*     m_pFavoriteImgCtrl;
    QResManager*    m_pQResManager;
};

#endif // MAINWINDOW_H
