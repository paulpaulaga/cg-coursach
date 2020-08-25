#ifndef GLIMAGEWIDGET_H
#define GLIMAGEWIDGET_H

#include "imageprocesser.h"
#include "imagewidget.h"

#include "mygl.h"
#include "model.h"

class GlImageProcesser : public ImageProcesser
{
public:
    GlImageProcesser();

    void process(QImage &image) override;

    void drawWire(QImage &image);

    void drawRandomColored(QImage &image);

    void drawFlatShaded(QImage &image);

private:
    Model model;
};

class GLImageWidget : public ImageWidget
{
    Q_OBJECT
public:
    explicit GLImageWidget(QWidget *parent = nullptr);

    void reprocess() override;

    void resizeEvent(QResizeEvent *event) override;

private:
    GlImageProcesser processer;
};

#endif // GLIMAGEWIDGET_H
