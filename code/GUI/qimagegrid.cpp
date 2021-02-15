#include "qimagegrid.h"

QImageGrid::QImageGrid(QWidget *parent) :
    QWidget(parent)
{
    m_pTitle        = new QLabel(this);
    m_nCols         = 1;
    m_nRows         = 1;
}

void QImageGrid::SetTitle(QString str)
{
    m_pTitle->setText(str);
}

void QImageGrid::SetColumn(int nCols)
{
    m_nCols     = nCols;
    UiLayout();
}

void QImageGrid::SetRow(int nRows)
{
    m_nRows     = nRows;
    UiLayout();
}

void  QImageGrid::UiLayout()
{

}
