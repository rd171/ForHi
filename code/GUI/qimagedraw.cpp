#include "qimagedraw.h"
#include <QPainter>
#include <QPixmap>

QImageDraw::QImageDraw(QWidget *parent) :
    QWidget(parent)
{
}

bool QImageDraw::Show(QString strFile)
{
    QPixmap pix;
    if ( pix.load(strFile) )
    {
        m_strFile   = strFile;
        update();
        return true;
    }
    else
    {
        return false;
    }
}

void QImageDraw::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QRect rc = rect();
    painter.fillRect(rc, Qt::black);
    QPixmap pix;
    if ( pix.load(m_strFile) )
    {
        double dR1 = 1.0*pix.width()/rc.width();
        double dR2 = 1.0*pix.height()/rc.height();
        double dR  = dR1;
        if ( dR1 > dR2  )
            dR = dR2;
        pix.scaled(rc.width()*dR, rc.height()*dR, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.drawPixmap(rc, pix);
    }
}
