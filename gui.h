#ifndef GUI_H
#define GUI_H

#include <QtGui>
#include <frameshow.h>
#include <opencvgl.h>

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = 0);
    ~Gui();
private:
    QVBoxLayout *layout;
    FrameShow *f;
    OpenCVGL *gl;
private slots:
    void gotNewImage();
};

#endif // GUI_H
