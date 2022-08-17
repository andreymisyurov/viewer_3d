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

// массив с вершинами
float arr[] = {0,0, -1.5, 1,0, -1.5, 0,1, -1.5};

void Widget::paintGL() {
    glClearColor(0, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, z);

    //вызываем функцию вертекс поинтер
    // сколько переменных на одну вершину
    // тип
    // смещение
    // адресс массива
    glVertexPointer(3, GL_FLOAT, 0, &arr);

    // разрешаем использовать вершинный буфер
    glEnableClientState(GL_VERTEX_ARRAY);
    //  добавляем цвет треугольника
    glColor3b(1,0,0);
    // рисуем треугольники, первый эл = 0, всего вершин 3
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // запрещаем использовать вершинный буфер
    glDisableClientState(GL_VERTEX_ARRAY);

}

void Widget::changeZ(){
    z -= 0.01;
    update();
}









