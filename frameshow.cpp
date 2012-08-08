#include "frameshow.h"

FrameShow::FrameShow()
{
    boardWidth = 0;
    boardHeight = 0;
    boardSize = cv::Size(boardWidth,boardHeight);
    //start();
    cap.open(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH,800);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,600);
    m_timer.setInterval(10);
    connect(&m_timer, SIGNAL(timeout()), SLOT(run()));
    m_timer.start();
}

void FrameShow::run()
{
    cap >> img;
    m_mutex.lock();
    out = QImage((const unsigned char*)(img.data),img.cols,img.rows,img.step,QImage::Format_RGB888).rgbSwapped();;
    m_mutex.unlock();
    emit newImage();
}


