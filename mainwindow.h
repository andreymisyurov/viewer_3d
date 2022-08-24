#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QFileDialog>

#include "./model/glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    auto on_slider_y_move_actionTriggered() -> void;
    auto on_slider_x_move_actionTriggered() -> void;
    auto on_slider_z_move_actionTriggered() -> void;
    auto on_slider_x_rotate_actionTriggered() -> void;
    auto on_slider_y_rotate_actionTriggered() -> void;
    auto on_slider_z_rotate_actionTriggered() -> void;
    auto on_slider_zoom_actionTriggered() -> void;
    auto on_actionload_triggered() -> void;
    auto on_save_state_clicked() -> void;
    auto on_load_state_clicked() -> void;

private:
    auto m_openFile() -> void;

    Momento mrKeeper;

private:
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
