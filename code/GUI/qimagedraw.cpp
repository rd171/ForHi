#include "qimagedraw.h"
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QDebug>

QImageDraw::QImageDraw(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color:black");
    m_pImgLab       = new QLabel(this);
    m_pImgInfoLab   = new QLabel(this);
    m_pImgInfoLab->setWordWrap(true);
    m_pImgLab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_pImgInfoLab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_WorkspaceLayout.addWidget(m_pImgLab, 4);
    m_WorkspaceLayout.addWidget(m_pImgInfoLab, 1);
    m_WorkspaceLayout.setSpacing(0);
    setLayout(&m_WorkspaceLayout);
}

bool QImageDraw::ShowImage(QString strFile)
{
    QPixmap img;
    if ( !img.load(strFile) )
        return false;

    m_pImgLab->setStyleSheet("background-color:black");
    m_pImgLab->setAlignment(Qt::AlignCenter);

    img = img.scaled(m_pImgLab->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_pImgLab->setScaledContents(false);
    m_pImgLab->setPixmap(img);

    m_pImgInfoLab->setText(strFile);
    m_pImgInfoLab->setStyleSheet("background-color:blue;color:white;text-align:left;vertical-align:top;");
    return true;
}
