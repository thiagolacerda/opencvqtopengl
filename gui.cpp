#include "gui.h"

Gui::Gui(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    f = new FrameShow();
    gl = new OpenCVGL();
    gl->setFixedSize(800, 600);

    connect(f,SIGNAL(newImage()),this,SLOT(gotNewImage()));

    layout->addWidget(gl);
    this->setLayout(layout);
}

void Gui::gotNewImage()
{
    f->m_mutex.lock();
    gl->renderImage(f->out);
    f->m_mutex.unlock();
}

Gui::~Gui()
{

}
