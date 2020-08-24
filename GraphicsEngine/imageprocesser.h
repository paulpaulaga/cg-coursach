#ifndef IMAGEPROCESSER_H
#define IMAGEPROCESSER_H

#include <QImage>
#include <memory>


class ImageProcesser
{
public:
    ImageProcesser() = default;
    virtual void process(QImage &image) = 0;
};

#endif // IMAGEPROCESSER_H
