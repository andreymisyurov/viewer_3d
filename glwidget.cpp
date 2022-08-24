#include "glwidget.h"

#include <math.h>

Widget::Widget(QWidget* parent) : QOpenGLWidget(parent) {}

Widget::~Widget() {
  delete (m_indexes);
  delete (m_verteres);
}

auto Widget::initializeGL() -> void {
  clearScreen();
  glClearColor(0, 0.75, 0.7, 0);
  glEnable(GL_DEPTH_TEST);
  pair = Parser::getInstanse().getObj(m_line);
  m_counter = m_countFace(pair);
  m_build();
}

auto Widget::resizeGL(int w, int h) -> void { glViewport(0, 0, w, h); }

auto Widget::paintGL() -> void {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(m_xMove, m_yMove, m_zMove);
  rotate();
  glScalef(m_scale, m_scale, m_scale);
  m_draw();
  update();
}

auto Widget::setPath(char* value) -> void { m_line = value; }

auto Widget::m_build() -> void {
  delete (m_indexes);
  delete (m_verteres);
  m_verteres = new float[pair.first.size() * 3];
  m_indexes = new GLuint[m_counter * 2];

  for (size_t i = 0, k = 0, l = pair.first.size() * 3; i < l; ++k) {
    m_verteres[i++] = pair.first.at(k).m_x / 2.;
    m_verteres[i++] = pair.first.at(k).m_y / 2.;
    m_verteres[i++] = pair.first.at(k).m_z / 2.;
  }

  for (size_t i = 0, k = 0, l = m_counter * 2; i < l; ++k) {
    m_indexes[i++] = pair.second.at(k).at(0) - 1;
    for (size_t e = 1; e < pair.second.at(k).size(); ++e) {
      m_indexes[i++] = pair.second.at(k).at(e) - 1;
      m_indexes[i++] = pair.second.at(k).at(e) - 1;
    }
    m_indexes[i++] = pair.second.at(k).at(0) - 1;
  }
}

auto Widget::m_draw() -> void {
  glColor3f(0.5, 0, 0);
  glVertexPointer(3, GL_FLOAT, 0, m_verteres);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_LINES, m_counter * 2, GL_UNSIGNED_INT, m_indexes);
  glDisableClientState(GL_VERTEX_ARRAY);
}

auto Widget::m_countFace(
    const std::pair<std::vector<Data>, std::vector<std::vector<int>>>& pair)
    -> int {
  auto temp = 0;
  for (size_t i = 0, l = pair.second.size(); i < l; ++i) {
    temp += pair.second.at(i).size();
  }
  return temp;
}

auto Widget::setXMove(int value) -> void { m_xMove = value / 200.; }

auto Widget::setYMove(int value) -> void { m_yMove = value / 200.; }

auto Widget::setZMove(int value) -> void { setZoom(value); }

auto Widget::setXRotate(int value) -> void { m_xRotate = value; }

auto Widget::setYRotate(int value) -> void { m_yRotate = value; }

auto Widget::setZRotate(int value) -> void { m_zRotate = value; }

auto Widget::setZoom(float value) -> void { m_scale = value / 10; }

auto Widget::rotate() -> void {
  glRotatef(m_xRotate, 1, 0, 0);
  glRotatef(m_yRotate, 0, 1, 0);
  glRotatef(m_zRotate, 0, 0, 1);
}

auto Widget::clearScreen() -> void {
  delete (m_indexes);
  delete (m_verteres);
  m_indexes = nullptr;
  m_verteres = nullptr;
  m_xMove = 0.0;
  m_yMove = 0.0;
  m_zMove = 0.0;
  m_xRotate = 0.0;
  m_yRotate = 0.0;
  m_zRotate = 0.0;
  m_scale = 1;
  pair.first.clear();
  pair.second.clear();
}

auto Widget::getFacesCount() -> QString {
  return QString::number(pair.second.size());
}

auto Widget::getPointsCount() -> QString {
  return QString::number(pair.first.size());
}

auto Widget::clearPair() -> void { Parser::getInstanse().clearData(); }

auto Widget::getData() -> MomentoData {
  MomentoData result;
  result.m_xMove = m_xMove;
  result.m_yMove = m_yMove;
  result.m_zMove = m_zMove;
  result.m_xRotate = m_xRotate;
  result.m_yRotate = m_yRotate;
  result.m_zRotate = m_zRotate;
  result.m_scale = m_scale;
  result.pair = pair;
  return result;
}

auto Widget::setData(MomentoData data) -> void {
  clearScreen();
  glClearColor(0, 0.75, 0.7, 0);
  glEnable(GL_DEPTH_TEST);
  pair = data.pair;
  m_counter = m_countFace(pair);
  m_build();

  m_xMove = data.m_xMove;
  m_yMove = data.m_yMove;
  m_zMove = data.m_zMove;
  m_xRotate = data.m_xRotate;
  m_yRotate = data.m_yRotate;
  m_zRotate = data.m_zRotate;
  m_scale = data.m_scale;
}
