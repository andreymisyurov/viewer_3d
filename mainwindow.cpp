#include "mainwindow.h"

#include "glwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

auto MainWindow::on_slider_x_move_actionTriggered() -> void {
    ui->openGLWidget->setXMove(ui->slider_x_move->value());
}

auto MainWindow::on_slider_y_move_actionTriggered() -> void {
    ui->openGLWidget->setYMove(ui->slider_y_move->value());
}

auto MainWindow::on_slider_z_move_actionTriggered() -> void {
    ui->openGLWidget->setZMove(ui->slider_z_move->value());
}

auto MainWindow::on_slider_x_rotate_actionTriggered() -> void {
    ui->openGLWidget->setXRotate(ui->slider_x_rotate->value());
}

auto MainWindow::on_slider_y_rotate_actionTriggered() -> void {
    ui->openGLWidget->setYRotate(ui->slider_y_rotate->value());
}

auto MainWindow::on_slider_z_rotate_actionTriggered() -> void {
    ui->openGLWidget->setZRotate(ui->slider_z_rotate->value());
}

auto MainWindow::on_slider_zoom_actionTriggered() -> void {
    ui->openGLWidget->setZoom(ui->slider_zoom->value());
}

auto MainWindow::on_actionload_triggered() -> void {
    m_openFile();
}

auto MainWindow::m_openFile() -> void {
    auto path = QFileDialog::getOpenFileName(0, "OpenDialog", "", "*.obj");
    if(!path.isEmpty()) {
        ui->openGLWidget->clearScreen();
        ui->openGLWidget->clearPair();
        QFileInfo fileInfo(path);
        auto transit = path.toLocal8Bit().data();
        ui->openGLWidget->setPath(transit);
        ui->openGLWidget->getInitializeGL();
        ui->show_filename->setText(fileInfo.fileName());
        ui->show_points->setText(ui->openGLWidget->getPointsCount());
        ui->show_faces->setText(ui->openGLWidget->getFacesCount());
    }
}

auto MainWindow::on_save_state_clicked() -> void {
    mrKeeper.setText(ui->show_filename->text().toStdString(), ui->show_points->text().toStdString(), ui->show_faces->text().toStdString());
    mrKeeper.saveData(ui->openGLWidget->getData());
}

auto MainWindow::on_load_state_clicked() -> void {
    ui->show_filename->setText(QString::fromStdString(mrKeeper.getTitle()));
    ui->show_points->setText(QString::fromStdString(mrKeeper.getVerteres()));
    ui->show_faces->setText(QString::fromStdString(mrKeeper.getFaces()));
    ui->openGLWidget->setData(mrKeeper.getData());
}
















