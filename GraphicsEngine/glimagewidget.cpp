#include "glimagewidget.h"

#include <QDebug>
#include <vector>

using namespace std;

// **************** GLIMAGEPROCESSER ****************
GlImageProcesser::GlImageProcesser() :
    model("./GraphicsEngine/models/test_thing.obj")
{
}

void GlImageProcesser::process(QImage &image)
{
//    drawWire(image);
    drawRandomColored(image);
}

void GlImageProcesser::drawWire(QImage &image)
{
    int width = image.width() / 2;
    int height = image.height() / 2;

    for (int i = 0; i < model.faces_count(); ++i)
    {
        vector<int> face = model.face(i);
        for (int j = 0; j < 3; ++j)
        {
            Vec3f v0 = model.vert(face[j]);
            Vec3f v1 = model.vert(face[(j + 1) % 3]);
            Vec2i p0((v0.x + 1.) * width, (v0.y + 1.) * height);
            Vec2i p1((v1.x + 1.) * width, (v1.y + 1.) * height);
            drawLine(image, p0, p1, Qt::black);
        }
    }
}

void GlImageProcesser::drawRandomColored(QImage &image)
{
    int width = image.width() / 2;
    int height = image.height() / 2;
    Vec2i screenCoords[3];
    for (int i = 0; i < model.faces_count(); ++i)
    {
        vector<int> face = model.face(i);
        for (int j = 0; j < 3; ++j)
        {
            Vec3f v = model.vert(face[j]);
            screenCoords[j] = Vec2i((v.x + 1.) * width,
                                    (v.y + 1.) * height);
        }
        drawTriangle(image, screenCoords[0], screenCoords[1], screenCoords[2],
                            qRgb(rand() % 256, rand() % 256, rand() % 256));
    }
}

// **************** GLIMAGWEWIDGET ****************

GLImageWidget::GLImageWidget(QWidget *parent) : ImageWidget(parent)
{

}

void GLImageWidget::reprocess()
{
    image.fill(Qt::white);
    processer.process(image);
    QTransform myTransform;
    myTransform.rotate(180);
    image = image.transformed(myTransform);
    repaint();
}

void GLImageWidget::resizeEvent(QResizeEvent *event)
{
    ImageWidget::resizeEvent(event);
    reprocess();
}
