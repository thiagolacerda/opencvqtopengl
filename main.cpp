#include <QtGui/QApplication>
#include <QGraphicsScene>
#include <QDeclarativeView>
#include "opencvgl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    OpenCVGL w;
    w.setFixedSize(800, 600);
    scene.addWidget(&w);
    QDeclarativeView view;
    view.setMinimumSize(800, 600);
    view.move(0, 0);
    view.setScene(&scene);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();
    return a.exec();
}
