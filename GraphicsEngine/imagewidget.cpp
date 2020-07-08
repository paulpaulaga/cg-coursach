#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent),
    image(this->width(), this->height(), QImage::Format_RGB32)
{
    setAutoFillBackground(false);
}

void ImageWidget::resizeEvent(QResizeEvent *event)
{
    image = QImage(this->width(), this->height(), QImage::Format_RGB32);
    image.fill(qRgb(255, 255, 255));
}

void ImageWidget::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QRect imageRect(this->rect());
    QPainter p(this), ip(&image);
    ip.fillRect(imageRect, qRgb(255, 255, 255));
    ip.drawLine(0, 0, 100, 100);
    p.drawImage(imageRect, image, imageRect);
}

