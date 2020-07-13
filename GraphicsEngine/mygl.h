#ifndef MYGL_H
#define MYGL_H

#include <QImage>

#include "geometry.h"

class Bresenham
{
public:
    Bresenham(Vec2i startPoint, Vec2i endPoint);
    void step();
    void nextY();
    Vec2i p;
private:
    int e;
    int dx, dy;
    int sx, sy;
    bool change;
};

void drawLine(QImage &image, Vec2i startPoint, Vec2i endPoint, QColor col = Qt::black);

void drawHorizontalLine(QImage &image, Vec2i startPoint, Vec2i endPoint, QColor col);

void drawTriangle(QImage &image, Vec2i p0, Vec2i p1, Vec2i p2, QColor col = Qt::black);

void drawZTriangle(QImage &image, Vec3i p0, Vec3i p1, Vec3i p2, int *zBuffer, QColor col = Qt::black);

int sgn(int val);

#endif
