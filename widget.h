#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QTimer>
#include <QMouseEvent>

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    float xRot, yRot, zRot;
    QPoint mPos;
    QTimer tmr;
    void drowCube(float a);
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
};
#endif // WIDGET_H
