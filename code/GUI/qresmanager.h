#ifndef QRESMANAGER_H
#define QRESMANAGER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class QResManager : public QWidget
{
    Q_OBJECT
public:
    explicit QResManager(QWidget *parent = 0);

    // Purpose
    //   Set title
    // Parameter:
    //  str：        title
    // Return:
    // Remark:
    void SetTitle(QString str);

signals:
    // Purpose
    //   This signal is emitted when the view button is clicked
    // Parameter:
    // Return:
    // Remark:
    void ClickViewBtn();

public slots:

private:
    QPushButton*    m_pViewBtn;
    QVBoxLayout     m_WorkspaceLayout;
    QLabel*         m_pTitle;

};

#endif // QRESMANAGER_H
