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
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,3);
}

void Widget::paintGL() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,0,-2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    drowCube(0.5);
}


void Widget::drowCube(float a){
    float arr[] = {-a,-a,a, a,-a,a, a,a,a, -a,a,a,
                   a,-a,-a, -a,-a,-a, -a,a,-a, a,a,-a,
                   -a,-a,-a, -a,-a,a, -a,a,a, -a,a,-a,
                   a,-a,a, a,-a,-a, a,a,-a, a,a,a,
                   -a,-a,a, a,-a,a, a,-a,-a, -a,-a,-a,
                   -a,a,a, a,a,a, a,a,-a, -a,a,-a,};

    float color[] = {
        1,0,0, 1,0,0, 1,0,0, 1,0,0,
        0,0,1, 0,0,1, 0,0,1, 0,0,1,
        1,1,0, 1,1,0, 1,1,0, 1,1,0,
        0,1,1, 0,1,1, 0,1,1, 0,1,1,
        1,0,1, 1,0,1, 1,0,1, 1,0,1,
        1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5
    };

    glVertexPointer(3, GL_FLOAT, 0, &arr);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &color);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Widget::mousePressEvent(QMouseEvent* mo){
    mPos = mo->pos();
}

void Widget::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}

