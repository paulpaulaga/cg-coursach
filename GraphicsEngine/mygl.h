#ifndef MYGL_H
#define MYGL_H

#include <QImage>

struct Point
{
    int x;
    int y;
};

void drawLine(QImage &image, Point startPoint, Point endPoint, QColor col = Qt::black);

int sgn(int val);

#endif
