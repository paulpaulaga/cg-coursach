#ifndef GLIMAGEWIDGET_H
#define GLIMAGEWIDGET_H

#include "imageprocesser.h"
#include "imagewidget.h"

#include "mygl.h"

class GlImageProcesser : public ImageProcesser
{
public:
    GlImageProcesser() = default;
    void process(QImage &image) override;
};

class GLImageWidget : public ImageWidget
{
    Q_OBJECT
public:
    explicit GLImageWidget(QWidget *parent = nullptr);

    void reprocess() override;
private:
    GlImageProcesser processer;
};

#endif // GLIMAGEWIDGET_H
