#ifndef OPENCVGL_H
#define OPENCVGL_H

#include <QGLWidget>
#include <qgl.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "frameshow.h"
#include <QDeclarativeView>

class OpenCVGL : public QGLWidget
{
    Q_OBJECT
public:
    OpenCVGL(QWidget *parent = 0); // constructor
    void renderImage(const QImage& frame);

    void setView(QDeclarativeView *view);

public slots:
    void gotNewImage();
    void onViewResized();

protected:
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    void initializeGL();
private:
    QImage m_GLFrame;
    FrameShow *f;
    QDeclarativeView *m_view;
};

#endif // OPENCVGL_H
