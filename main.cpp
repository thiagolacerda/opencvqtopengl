#include <QtGui/QApplication>
#include <QGraphicsScene>
#include <QDeclarativeView>
#include "opencvgl.h"
#include "mydeclarativeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    MyDeclarativeView *view = new MyDeclarativeView();
    OpenCVGL *w = new OpenCVGL();
    w->setView(view);
    w->resize(800, 600);
    scene.addWidget(w);
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setScene(&scene);
    view->setSource(QUrl::fromLocalFile("main.qml"));
    view->show();
    view->resize(800, 600);
    return a.exec();
}
