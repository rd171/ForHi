#ifndef QIMAGEDRAW_H
#define QIMAGEDRAW_H

#include <QWidget>
#include <QPaintEvent>
#include <QLabel>
#include <QHBoxLayout>

class QImageDraw : public QWidget
{
    Q_OBJECT
public:
    explicit QImageDraw(QWidget *parent = 0);

    bool    ShowImage(QString strFile);

signals:

public slots:

protected:


private:
    QLabel*     m_pImgLab;
    QLabel*     m_pImgInfoLab;
    QHBoxLayout    m_WorkspaceLayout;

};

#endif // QIMAGEDRAW_H
