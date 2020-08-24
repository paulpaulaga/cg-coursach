#include "mygl.h"
#include <iostream>

using namespace std;

Bresenham::Bresenham(Vec2i startPoint, Vec2i endPoint)
{
    dx = endPoint.x - startPoint.x;
    dy = endPoint.y - startPoint.y;
    sx = sgn(dx), sy = sgn(dy);
    p.x = startPoint.x;
    p.y = startPoint.y;
    change = false;
    dx = abs(dx);
    dy = abs(dy);
    if (dy >= dx)
    {
        swap(dx, dy);
        change = true;
    }
    e = 2 * dy - dx;
}

void Bresenham::step()
{
    if (e >= 0)
    {
        if (change)
            p.x += sx;
        else
            p.y += sy;
        e -= 2 * dx;
    }
    if (change)
        p.y += sy;
    else
        p.x += sx;
    e +=  2 * dy;
}

void Bresenham::nextY()
{
    int currentY = p.y;
    while (!(currentY - p.y))
        step();
}

int sgn(int val)
{
    return (0 < val) - (val < 0);
}

void drawLine(QImage &image, Vec2i startPoint, Vec2i endPoint, QColor col)
{
    int dx = endPoint.x - startPoint.x;
    int dy = endPoint.y - startPoint.y;
    int sx = sgn(dx), sy = sgn(dy);
    int x = startPoint.x;
    int y = startPoint.y;
    bool change = false;
    dx = abs(dx);
    dy = abs(dy);
    if (dx == 0 && dy == 0)
    {
        image.setPixel(x, y, col.rgb());
        return;
    }
    if (dy >= dx)
    {
        swap(dx, dy);
        change = true;
    }
    int e = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        image.setPixel(x, y, col.rgb());
        if (e >= 0)
        {
            if (change)
                x = x + sx;
            else
                y = y + sy;
            e = e - 2 * dx;
        }
        if (change)
            y = y + sy;
        else
            x = x + sx;
        e = e + 2 * dy;
    }
}

void drawHorizontalLine(QImage &image, Vec2i startPoint, Vec2i endPoint, QColor col)
{
    if (startPoint.y != endPoint.y)
        return;
    if (endPoint.x < startPoint.x)
        swap(startPoint, endPoint);
    for (int x = startPoint.x; x <= endPoint.x; ++x)
        image.setPixel(x, startPoint.y, col.rgb());
}

void drawTriangle(QImage &image, Vec2i p0, Vec2i p1, Vec2i p2, QColor col)
{
    drawLine(image, p0, p1, col);
    drawLine(image, p1, p2, col);
    drawLine(image, p2, p0, col);

    if (p0.y > p1.y)
        swap(p0, p1);
    if (p1.y > p2.y)
        swap(p1, p2);
    if (p0.y > p1.y)
        swap(p0, p1);

    Bresenham p0p2(p0, p2), p0p1(p0, p1), p1p2(p1, p2);
    while (p0p1.p.y < p1.y)
    {
        drawHorizontalLine(image, p0p2.p, p0p1.p, col);
        p0p2.nextY();
        p0p1.nextY();
    }
    while (p1p2.p.y < p2.y)
    {
        drawHorizontalLine(image, p0p2.p, p1p2.p, col);
        p0p2.nextY();
        p1p2.nextY();
    }
}

void drawZTriangle(QImage &image, Vec3i p0, Vec3i p1, Vec3i p2, int *zBuffer, QColor col)
{
}
