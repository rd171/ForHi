#include "qimagedraw.h"
#include <QPainter>
#include <QPixmap>

QImageDraw::QImageDraw(QWidget *parent) :
    QWidget(parent)
{
}

bool QImageDraw::Show(QString strFile)
{
    QPainter painter(this);
    QPixmap pix;
    if ( pix.load(strFile) )
    {
        painter.drawPixmap(0,0,100,33,pix);
        return true;
    }
    else
    {
        return false;
    }
}
