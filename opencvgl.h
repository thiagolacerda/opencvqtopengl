#ifndef OPENCVGL_H
#define OPENCVGL_H

#include <QGLWidget>
#include <qgl.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "frameshow.h"

class OpenCVGL : public QGLWidget
{
    Q_OBJECT
public:
    OpenCVGL(QWidget *parent = 0); // constructor
    void renderImage(const QImage& frame);

public slots:
    void gotNewImage();
protected:
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    void initializeGL();
private:
    QImage m_GLFrame;
    FrameShow *f;
};

#endif // OPENCVGL_H
