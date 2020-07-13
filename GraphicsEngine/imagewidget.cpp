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

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QRect imageRect(this->rect());
    QPainter p(this);
    p.drawImage(imageRect, image, imageRect);
}

void ImageWidget::buildObjFile(const char *filename)
{
    Model m(filename);
    Vec3f light_dir(0,0,-1);
    for (int i=0; i< m.faces_count(); i++) {
            std::vector<int> face = m.face(i);
            Vec2i screen_coords[3];
            Vec3f world_coords[3];
            for (int j=0; j < 3; j++)
            {
                Vec3f v = m.vert(face[j]);
                screen_coords[j] = Vec2i((v.x + 1) * image.width() / 2.,
                                         (v.y + 1) * image.height() / 2.);
                world_coords[j]  = v;
                cout << world_coords[j].x << " " << world_coords[j].y << " "
                     << world_coords[j].z << " ";
                cout << "(" << screen_coords[j].x << " " << screen_coords[j].y << ")" << endl;
            }
            cout << endl;
            Vec3f n = (world_coords[2]-world_coords[0])^(world_coords[1]-world_coords[0]);
            n.normalize();
            float intensity = n * light_dir;
            if (intensity > 0) {
               drawTriangle(image, screen_coords[0], screen_coords[1], screen_coords[2],
                            qRgba(intensity*255, intensity*255, intensity*255, 255));
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


















