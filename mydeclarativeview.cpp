#include "mydeclarativeview.h"
#include <QResizeEvent>

MyDeclarativeView::MyDeclarativeView(QWidget *parent)
    : QDeclarativeView(parent)
{
}

void MyDeclarativeView::resizeEvent(QResizeEvent *event)
{
    QDeclarativeView::resizeEvent(event);
    emit viewResized();
}
