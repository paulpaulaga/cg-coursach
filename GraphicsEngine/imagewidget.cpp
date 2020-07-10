#include "imagewidget.h"

#include "model.h"

using namespace std;

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent),
    image(this->width(), this->height(), QImage::Format_RGB32)
{
    setAutoFillBackground(false);
}

void ImageWidget::resizeEvent(QResizeEvent *event)
{
    image = QImage(this->width(), this->height(), QImage::Format_RGB32);
    image.fill(qRgb(255, 255, 255));
//    buildObjFile("/home/pavelcheklin/Code/BMSTU/cg-coursach/GraphicsEngine/models/test_thing.obj");
    drawTriangles();
}

void ImageWidget::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QRect imageRect(this->rect());
    QPainter p(this);
    p.drawImage(imageRect, image, imageRect);
}

void ImageWidget::buildObjFile(const char *filename)
{
    Model m(filename);
    for (int i = 0; i < m.faces_count(); ++i)
    {
        vector<int> face = m.face(i);
        for (int j = 0; j < 3; ++j)
        {
            Vec3f v0 = m.vert(face[j]);
            Vec3f v1 = m.vert(face[(j + 1) % 3]);
            int x0 = (v0.x + 1.) * image.width() / 2;
            int y0 = (v0.y + 1.) * image.height() / 2;
            int x1 = (v1.x + 1.) * image.width() / 2;
            int y1 = (v1.y + 1.) * image.height() / 2;
            drawLine(image, Vec2i(x0, y0), Vec2i(x1, y1));
        }
    }
    QTransform myTransform;
    myTransform.rotate(180);
    image = image.transformed(myTransform);
}

void ImageWidget::drawTriangles()
{
    Vec2i p0(10, 10);
    Vec2i p1(image.width() / 2, image.height() / 2);
    Vec2i p2(10, image.height() - 10);
    drawTriangle(image, p0, p1, p2, Qt::red);
}


















