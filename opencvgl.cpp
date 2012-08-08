#include "opencvgl.h"

OpenCVGL::OpenCVGL(QWidget *parent)
    : QGLWidget(parent)
    , m_view(0)
{
    f = new FrameShow();

    connect(f,SIGNAL(newImage()),this,SLOT(gotNewImage()));
}

void OpenCVGL::setView(QDeclarativeView *view)
{
    if (m_view == view)
        return;

    if (m_view) {
        disconnect(m_view, SIGNAL(viewResized()), this, SLOT(onViewResized()));
        m_view = 0;
    }

    m_view = view;
    connect(m_view, SIGNAL(viewResized()), SLOT(onViewResized()));
}

void OpenCVGL::onViewResized()
{
    setGeometry(0, 0, m_view->width(), m_view->height());
}

void OpenCVGL::gotNewImage()
{
    f->m_mutex.lock();
    renderImage(f->out);
    f->m_mutex.unlock();
}

void OpenCVGL::initializeGL()
{
//    glPointSize(3.0f);
//    glEnable (GL_BLEND);
//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenCVGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glLoadIdentity();
    glColor3f(1,1,1);
    if(!m_GLFrame.isNull())
    {
        glEnable(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, m_GLFrame.width(), m_GLFrame.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_GLFrame.bits() );
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(0, m_GLFrame.height());
        glTexCoord2f(0, 1); glVertex2f(0, 0);
        glTexCoord2f(1, 1); glVertex2f(m_GLFrame.width(), 0);
        glTexCoord2f(1, 0); glVertex2f(m_GLFrame.width(), m_GLFrame.height());
        glEnd();
        glDisable(GL_TEXTURE_2D);

    }
    glFlush();
}

void OpenCVGL::resizeGL(int width, int height)
{
    qWarning() << "resizeGL";
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width,height,0,-200,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenCVGL::renderImage(const QImage &frame)
{
    m_GLFrame = QGLWidget::convertToGLFormat(frame.scaled(width(), height()));
    this->updateGL();
    update();
}
