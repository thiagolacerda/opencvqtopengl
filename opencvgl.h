#ifndef OPENCVGL_H
#define OPENCVGL_H

#include <QGLWidget>
#include <qgl.h>
#include <iostream>
#include <opencv2/opencv.hpp>

class OpenCVGL : public QGLWidget
{
public:
    OpenCVGL(); // constructor
    void renderImage(const QImage& frame);
protected:
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    void initializeGL();
private:
    QImage m_GLFrame;
};

#endif // OPENCVGL_H
