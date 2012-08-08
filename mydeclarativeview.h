#ifndef MYDECLARATIVEVIEW_H
#define MYDECLARATIVEVIEW_H

#include <QDeclarativeView>

class MyDeclarativeView : public QDeclarativeView
{
    Q_OBJECT
public:
    MyDeclarativeView(QWidget *parent = 0);

signals:
    void viewResized();

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MYDECLARATIVEVIEW_H
