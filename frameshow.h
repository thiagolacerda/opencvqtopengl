#ifndef FRAMESHOW_H
#define FRAMESHOW_H
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include<QImage>
#include <QTimer>

#include <QMutex>

class FrameShow : public QObject
{
    Q_OBJECT
public:
    FrameShow();
    QImage out;
    QMutex m_mutex;

private:
    cv::Mat img;
    cv::VideoCapture cap;
    int boardWidth;
    int boardHeight;
    cv::Size boardSize;
    QTimer m_timer;

signals:
    void newImage();

public slots:
    void run();
};

#endif // FRAMESHOW_H
