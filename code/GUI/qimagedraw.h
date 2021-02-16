#ifndef QIMAGEDRAW_H
#define QIMAGEDRAW_H

#include <QWidget>
#include <QPaintEvent>

class QImageDraw : public QWidget
{
    Q_OBJECT
public:
    explicit QImageDraw(QWidget *parent = 0);

    bool    Show(QString strFile);

signals:

public slots:

protected:
    virtual void	paintEvent(QPaintEvent * event);

private:
    QString     m_strFile;

};

#endif // QIMAGEDRAW_H
