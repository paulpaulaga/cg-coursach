#include "imagewidget.h"

#include "model.h"

#include <iostream>

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
    buildObjFile("/home/pavelcheklin/Code/BMSTU/cg-coursach/GraphicsEngine/models/test_thing.obj");
//    drawTriangles();
}

void ImageWidget::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void ImageWidget::paintEvent(QPaintEvent *)
{
    QRect imageRect(this->rect());
    QPainter p(this);
    p.drawImage(imageRect, image, imageRect);
}

void ImageWidget::buildObjFile(const char *filename)
{
    Model m(filename);
    Vec3f light_dir(0,0,-1);
    int *zBuffer = new int[image.width() * image.height()];
    for (int i=0; i< m.faces_count(); i++) {
            std::vector<int> face = m.face(i);
            Vec3i screen_coords[3];
            Vec3f world_coords[3];
            for (int j=0; j < 3; j++)
            {
                Vec3f v = m.vert(face[j]);
                screen_coords[j] = Vec3i((v.x + 1) * image.width() / 2.,
                                         (v.y + 1) * image.height() / 2.,
                                         v.z);
                world_coords[j]  = v;
            }
            Vec3f n = (world_coords[2]-world_coords[0])^(world_coords[1]-world_coords[0]);
            n.normalize();
            float intensity = n * light_dir;
            if (intensity > 0) {
               drawZTriangle(image, screen_coords[0], screen_coords[1], screen_coords[2],
                       zBuffer, qRgba(intensity*255, intensity*255, intensity*255, 255));
            }
        }
    QTransform myTransform;
    myTransform.rotate(180);
    image = image.transformed(myTransform);
    delete[] zBuffer;
}

void ImageWidget::drawTriangles()
{
    drawLine(image, Vec2i(20, 34), Vec2i(744, 400), Qt::red);
    drawLine(image, Vec2i(120, 434), Vec2i(444, 400), Qt::green);
    drawLine(image, Vec2i(330, 463), Vec2i(594, 200), Qt::blue);

    QTransform myTransform;
    myTransform.rotate(180);
    image = image.transformed(myTransform);
}


















