#include "qimagedraw.h"
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QImageReader>
#include <QString>
#include <stdio.h>
#include "Exif.h"

QImageDraw::QImageDraw(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color:gray");
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
    QPixmap* pImg = new QPixmap();
    if ( !pImg->load(strFile) )
    {
        return false;
    }
    m_pImgLab->setStyleSheet("background-color:black");
    m_pImgLab->setAlignment(Qt::AlignCenter);

    *pImg = pImg->scaled(m_pImgLab->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_pImgLab->setScaledContents(false);
    m_pImgLab->setPixmap(*pImg);
    delete pImg;

    QString strExIf = GetExIf(strFile);
    m_pImgInfoLab->setText(strExIf);
    m_pImgInfoLab->setStyleSheet("background-color:#F0F0F0;color:black;");
    m_pImgInfoLab->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_strImg        = strFile;
    return true;
}

QString QImageDraw::GetExIf(QString strFile)
{
    QString strExIf;
    QFile mFile(strFile);
    if ( mFile.open(QIODevice::ReadOnly) )
    {
        int nSize           = mFile.size();
        QByteArray data     = mFile.readAll();
        // Parse EXIF
        easyexif::EXIFInfo result;
        unsigned char *buf  = (unsigned char*)data.data();
        int code = result.parseFrom(buf, nSize);
        if (code)
        {
            printf("Error parsing EXIF: code %d\n", code);
            return "";
        }
        strExIf     = QString("相机品牌:%1\r\n相机型号:%2\r\n曝光时间:1/%3s\r\n光圈:%4\r\nISO:%5\r\n焦距:%6\r\n精度:%7\r\n维度:%8\r\n高度:%9\r\n拍摄时间:%10\r\n")
                                                        .arg(QString::fromStdString(result.Make))
                                                        .arg(QString::fromStdString(result.Model))
                                                        .arg(QString::number(1/result.ExposureTime,'f',0))
                                                        .arg(QString::number(result.FNumber,'f',1))
                                                        .arg(QString::number(result.ISOSpeedRatings,'f',0))
                                                        .arg(QString::number(result.FocalLength,'f',0))
                                                        .arg(result.GeoLocation.Longitude)
                                                        .arg(result.GeoLocation.Latitude)
                                                        .arg(result.GeoLocation.AltitudeRef)
                                                        .arg(QString::fromStdString(result.DateTimeOriginal));


        //strExIf += "相机品牌" + QString::fromStdString(result.Make);
        //strExIf = strExIf + "\r\n" + "相机型号" + QString::fromStdString(result.Model);
        //QString s = QString("%d s").arg((unsigned)(1.0 / result.ExposureTime));
        //strExIf = "\r\n" + "快门速度：";
        //strExIf = strExIf + "\r\n" + "光圈：" + QString("f/%.1f").arg(result.FNumber);
        //strExIf = strExIf + "\r\n" + "ISO：" + QString("%d").arg(result.ISOSpeedRatings);
        //strExIf = strExIf + "\r\n" + "焦段：" + QString("%f mm").arg(result.FocalLength);
        //strExIf += "\r\n" + "GPS：" + QString::fromStdString(result.Model);
        /*
        // Dump EXIF information
        printf("Camera make       : %s\n", result.Make.c_str());
        printf("Camera model      : %s\n", result.Model.c_str());
        printf("Software          : %s\n", result.Software.c_str());
        printf("Bits per sample   : %d\n", result.BitsPerSample);
        printf("Image width       : %d\n", result.ImageWidth);
        printf("Image height      : %d\n", result.ImageHeight);
        printf("Image description : %s\n", result.ImageDescription.c_str());
        printf("Image orientation : %d\n", result.Orientation);
        printf("Image copyright   : %s\n", result.Copyright.c_str());
        printf("Image date/time   : %s\n", result.DateTime.c_str());
        printf("Original date/time: %s\n", result.DateTimeOriginal.c_str());
        printf("Digitize date/time: %s\n", result.DateTimeDigitized.c_str());
        printf("Subsecond time    : %s\n", result.SubSecTimeOriginal.c_str());
        printf("Exposure time     : 1/%d s\n", (unsigned)(1.0 / result.ExposureTime));
        printf("F-stop            : f/%.1f\n", result.FNumber);
        printf("ISO speed         : %d\n", result.ISOSpeedRatings);
        printf("Subject distance  : %f m\n", result.SubjectDistance);
        printf("Exposure bias     : %f EV\n", result.ExposureBiasValue);
        printf("Flash used?       : %d\n", result.Flash);
        printf("Metering mode     : %d\n", result.MeteringMode);
        printf("Lens focal length : %f mm\n", result.FocalLength);
        printf("35mm focal length : %u mm\n", result.FocalLengthIn35mm);
        printf("GPS Latitude      : %f deg (%f deg, %f min, %f sec %c)\n",
            result.GeoLocation.Latitude,
            result.GeoLocation.LatComponents.degrees,
            result.GeoLocation.LatComponents.minutes,
            result.GeoLocation.LatComponents.seconds,
            result.GeoLocation.LatComponents.direction);
        printf("GPS Longitude     : %f deg (%f deg, %f min, %f sec %c)\n",
            result.GeoLocation.Longitude,
            result.GeoLocation.LonComponents.degrees,
            result.GeoLocation.LonComponents.minutes,
            result.GeoLocation.LonComponents.seconds,
            result.GeoLocation.LonComponents.direction);
        printf("GPS Altitude      : %f m\n", result.GeoLocation.Altitude);
        */
    }
    return strExIf;
}

void QImageDraw::resizeEvent(QResizeEvent *event)
{
    ShowImage(m_strImg);
}
