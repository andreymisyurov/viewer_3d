#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QTimer>

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void changeZ();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    float z = 0;
    QTimer tmr;
};
#endif // WIDGET_H
