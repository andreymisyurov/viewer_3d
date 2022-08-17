#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Education");
    setGeometry(400,200,800,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {

}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);

}

void Widget::paintGL() {
    glClearColor(0, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3d(1,0,0);
    glVertex2d(0,0);
    glVertex2d(1,0);
    glVertex2d(0,1);
    glEnd();
}

