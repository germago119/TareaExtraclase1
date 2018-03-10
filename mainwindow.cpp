#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "simpleLinkedView.hpp"
#include "doubleLinkedView.hpp"
#include "circularView.hpp"
#include "treeView.hpp"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ButtonSimple_clicked() {
    SimpleList simpleWindow;

    simpleWindow.setModal(true);
    simpleWindow.exec();

}

void MainWindow::on_ButtonDoble_clicked() {
    DoubleLinked ventanaEnlazada;
    ventanaEnlazada.setModal(true);
    ventanaEnlazada.exec();
}

void MainWindow::on_ButtonCircular_clicked() {
    ViewCircularList ventanacircular;
    ventanacircular.setModal(true);
    ventanacircular.exec();
}

void MainWindow::on_ButtonArbol_clicked() {
    treeView ventanaArbol;
    ventanaArbol.setModal(true);
    ventanaArbol.exec();
}
