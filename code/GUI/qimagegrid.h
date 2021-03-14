#ifndef QIMAGEGRID_H
#define QIMAGEGRID_H

#include <QWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVector>
#include <QLabel>
#include "qimagedraw.h"

class QImageGrid : public QWidget
{
    Q_OBJECT
public:
    explicit QImageGrid(QWidget *parent = 0);

    // Purpose
    //   Set title
    // Parameter:
    //  str：        title
    // Return:
    // Remark:
    void SetTitle(QString str);

    void SetColumnAndRow(int nCols, int nRows);

    bool ShowImg(int nCols, int nRows, QString strPath);

signals:

public slots:

private:
    QVBoxLayout     m_WorkspaceLayout;
    QGridLayout     m_ImgLayout;
    QVector<QImageDraw*>    m_vtImg;
    QLabel*         m_pTitle;
    int             m_nCols;
    int             m_nRows;

private:
    void  UiLayout();

};

#endif // QIMAGEGRID_H
