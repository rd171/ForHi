#ifndef QRESMANAGER_H
#define QRESMANAGER_H

#include <QWidget>
#include <QPushButton>

class QResManager : public QWidget
{
    Q_OBJECT
public:
    explicit QResManager(QWidget *parent = 0);

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

};

#endif // QRESMANAGER_H
