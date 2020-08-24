#include "glimagewidget.h"

#include <QDebug>

#include "model.h"

// **************** GLIMAGEPROCESSER ****************
void GlImageProcesser::process(QImage &image)
{
    return;
}

// **************** GLIMAGWEWIDGET ****************

GLImageWidget::GLImageWidget(QWidget *parent) : ImageWidget(parent)
{

}

void GLImageWidget::reprocess()
{
    processer.process(image);
    QTransform myTransform;
    myTransform.rotate(180);
    image = image.transformed(myTransform);
    repaint();
}

















