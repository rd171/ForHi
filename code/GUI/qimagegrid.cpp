#include "qimagegrid.h"

QImageGrid::QImageGrid(QWidget *parent) :
    QWidget(parent)
{
    m_pTitle        = new QLabel(this);
    m_WorkspaceLayout.addWidget(m_pTitle);
    m_WorkspaceLayout.addLayout(&m_ImgLayout);
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 6; j++)
        {
            QImageDraw* pItem = new QImageDraw(this);
            pItem->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            m_vtImg.append(pItem);
            m_ImgLayout.addWidget(pItem, i, j);
        }
    }
    setLayout(&m_WorkspaceLayout);
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
