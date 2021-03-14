#include "qimagegrid.h"

QImageGrid::QImageGrid(QWidget *parent) :
    QWidget(parent)
{
    m_pTitle        = new QLabel(this);
    m_WorkspaceLayout.addWidget(m_pTitle);
    m_WorkspaceLayout.addLayout(&m_ImgLayout);
    m_nCols         = 1;
    m_nRows         = 1;
    UiLayout();
}

void QImageGrid::SetTitle(QString str)
{
    m_pTitle->setText(str);
}

void QImageGrid::SetColumnAndRow(int nCols, int nRows)
{
    m_nCols     = nCols;
    m_nRows     = nRows;
    UiLayout();
}

void  QImageGrid::UiLayout()
{
    for(auto it = m_vtImg.begin(); it != m_vtImg.end(); ++it)
    {
        if(*it != nullptr)
        {
            delete (*it);
            (*it) = nullptr;
        }

    }
    m_vtImg.clear();
    QVector<QImageDraw*>().swap(m_vtImg);

    for ( int i = 0; i < m_nRows; i++ )
    {
        for ( int j = 0; j < m_nCols; j++)
        {
            QImageDraw* pItem = new QImageDraw(this);
            pItem->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            m_vtImg.append(pItem);
            m_ImgLayout.addWidget(pItem, i, j);
        }
    }
    setLayout(&m_WorkspaceLayout);
}

bool QImageGrid::ShowImg(int nCols, int nRows, QString strPath)
{
    if ( ( nCols < 0 || nCols >= m_nCols ) && ( nRows < 0 || nRows >= m_nRows ) )
        return  false;
    m_vtImg[nRows*m_nCols + nCols]->ShowImage(strPath);
    return true;
}
