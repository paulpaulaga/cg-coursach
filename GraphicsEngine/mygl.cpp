#include "mygl.h"

int sgn(int val)
{
    return (0 < val) - (val < 0);
}

void drawLine(QImage &image, Point startPoint, Point endPoint, QColor col)
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
        std::swap(dx, dy);
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
