#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QWidget>

#include "parser.cpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QOpenGLWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

public:
    auto setXMove(int value) -> void;
    auto setYMove(int value) -> void;
    auto setZMove(int value) -> void;
    auto rotate() -> void;
    auto setXRotate(int value) -> void;
    auto setYRotate(int value) -> void;
    auto setZRotate(int value) -> void;
    auto setZoom(float value) -> void;
    auto clearPair() -> void;
    auto setPath(char* value) -> void;
    auto clearScreen() -> void;
    auto getFacesCount() -> QString;
    auto getPointsCount() -> QString;
    auto getInitializeGL() -> void {
        initializeGL();
    }
    auto getData() -> MomentoData;
    auto setData(MomentoData data) -> void;

protected:
    auto initializeGL() -> void override;
    auto resizeGL(int w, int h) -> void override;
    auto paintGL() -> void override;

private:
    auto m_build() -> void;
    auto m_draw() -> void;
    auto m_countFace(
            const std::pair<std::vector<Data>, std::vector<std::vector<int>>>& pair)
    -> int;


private:
    float m_xMove = 0.0;
    float m_yMove = 0.0;
    float m_zMove = 0.0;
    float m_xRotate = 0.0;
    float m_yRotate = 0.0;
    float m_zRotate = 0.0;
    float m_scale = 1.0;

//    Parser m_parser;
    float* m_verteres = nullptr;
    GLuint* m_indexes = nullptr;

    std::pair<std::vector<Data>, std::vector<std::vector<int>>> pair;

    size_t m_counter = 0;
    char* m_line = NULL;
};
#endif  // WIDGET_H
