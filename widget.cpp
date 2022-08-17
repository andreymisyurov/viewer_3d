#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Education");
    setGeometry(400,200,800,600);

    connect(&tmr, SIGNAL(timeout()), this, SLOT(changeZ()));
    tmr.start(100);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {

}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1,1,-1,1,1,2);
    glFrustum(-1,1,-1,1,1,2);

}

//float arr[] = {0,0, -1.5, 1,0, -1.5, 0,1, -1.5};

void Widget::paintGL() {
    glClearColor(0, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glRotatef(90, 0, 0, 1);
    glTranslated(0, 0, z);
    glBegin(GL_TRIANGLES);
    glColor3d(1,0,0);

    glVertex3d(0,0, -1.5);
    glVertex3d(1,0, -1.5);
    glVertex3d(0,1, -1.5);
    glEnd();
}

void Widget::changeZ(){
    z -= 0.01;
    update();
}









