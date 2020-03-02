#include <QImageReader>
#include <QImageWriter>
#include <QElapsedTimer>
#include <QDebug>

extern "C" int thumbnail(const char* input, const char* output, int width, int height)
{
    QImageReader rd(QString::fromUtf8(input));
    rd.setAutoTransform(true);
    QSize imageSize = rd.size();
    if (!imageSize.isValid())
        return -1;
    QSize scaledSize = imageSize.scaled(width, height, Qt::KeepAspectRatio);
    rd.setScaledSize(scaledSize);
    QImage img = rd.read();
    if (img.isNull())
        return -1;

    QImageWriter wr(QString::fromUtf8(output), "jpg");
    if (!wr.write(img))
        return -1;
    return 0;
}
