#include "treeView.hpp"
#include "ui_treeView.h"
#include "BinarySearchTree.hpp"

treeView::treeView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::treeView) {
    ui->setupUi(this);
    arbol = new BinarySearchTree();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    coordenadax = 30;
    coordenaday = 30;
    sedibujoantes = false;
}

treeView::~treeView() {
    delete ui;
}

void treeView::on_InsertarButton_clicked() {
    arbol->insertarNodo(ui->LabelInsertar->text().toInt());
    std::cout << "Se inserto el nodo" << std::endl;
    arbol->recorridoPreOrder(arbol->getRoot());
    scene->clear();
    recorreDibuja(arbol->getRoot(), 30, 30, "root");
}

void treeView::on_EliminarButton_clicked() {
    arbol->eliminar(arbol->getRoot(), ui->LabelEliminar->text().toInt());
    scene->clear();
    recorreDibuja(arbol->getRoot(), 30, 30, "root");
}


void treeView::recorreDibuja(TreeNode *nodo, int corx, int cory, QString lado) {

    if (nodo != 0) {

        if (lado == "izquierdo") {
            scene->addLine(corx + 170., cory - 100., corx + 50., cory + 0., QPen(QBrush(Qt::black), 3));
        }
        if (lado == "derecha") {
            scene->addLine(corx - 150., cory - 100., corx + 0., cory + 0., QPen(QBrush(Qt::black), 3));
        }

        int i = nodo->getDato();
        QString s = QString::number(i);
        QFont font;
        font.setPixelSize(25);
        font.setBold(false);
        font.setFamily("Calibri");


        QBrush redBrush(Qt::red);
        QBrush greenBrush(Qt::green);
        QPen blackpen(Qt::black);
        blackpen.setWidth(6);
        scene->addEllipse(corx + 0., cory + 0., 60., 60., blackpen, greenBrush);
        QPainterPath path;

        path.addText(corx + 25, cory + 35, font, s);
        scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

        recorreDibuja(nodo->left, corx - 160, cory + 160, "izquierdo");
        recorreDibuja(nodo->right, corx + 200, cory + 160, "derecha");
    }

}
