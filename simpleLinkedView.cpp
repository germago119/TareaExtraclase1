#include "simpleLinkedView.hpp"
#include "ui_simpleLinkedView.h"
#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>
#include "SimpleLinkedList.hpp"

SimpleList::SimpleList(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::SimpleList) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    list = new SimpleLinkedList();
    int posx = 50;


}

SimpleList::~SimpleList() {
    delete ui;
}


void SimpleList::on_addButton_clicked() {
    posx = 50;
    list->ingresarDatoFinal(ui->addText->text());
    recorreDibuja(list);

}

void SimpleList::recorreDibuja(SimpleLinkedList *lista) {

    SimpleNode *runner = lista->first;
    scene->clear();
    posx = 50;
    if (lista->first == 0) {
        std::cout << "No hay elementos en la list" << std::endl;
    } else {
        while (runner != 0) {

            QFont font;
            font.setPixelSize(25);
            font.setBold(false);
            font.setFamily("Calibri");

            QBrush redBrush(Qt::red);
            QBrush greenBrush(Qt::green);
            QPen blackpen(Qt::black);
            blackpen.setWidth(6);

            rectangle = scene->addRect(posx, 0, 100, 100, blackpen, greenBrush);
            QPainterPath path;
            path.addText(posx + 45, 50, font, runner->getValue());
            scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if (runner != lista->last) {
                QPolygonF Triangle;
                Triangle.append(QPointF(posx + 150., 45));
                Triangle.append(QPointF(posx + 130., 65.));
                Triangle.append(QPointF(posx + 130., 25.));
                Triangle.append(QPointF(posx + 150., 45.));

                scene->addLine(posx + 130., 45., posx + 105., 45., QPen(QBrush(Qt::black), 10));
                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            posx = posx + 150;
            runner = runner->next;
        }
        posx = 50;

    }
}

void SimpleList::on_addInicioButton_clicked() {
    list->ingresarDatoInicio(ui->addInicio->text());
    recorreDibuja(list);
}

void SimpleList::on_ButtonInsertarporPos_clicked() {

    QString entero = ui->labelTextoposicionInsertar->text();

    if (entero.toInt() > list->largo || entero.toInt() < 1) {
        return;
    }
    list->insertarPorPosicion(entero.toInt(), ui->labeltextovalor->text());
    recorreDibuja(list);
}

void SimpleList::on_EliminarInicioButton_clicked() {
    list->eliminarInicio();
    recorreDibuja(list);
}

void SimpleList::on_EliminarFinalButton_clicked() {
    list->eliminarFinal();
    recorreDibuja(list);
    posx = posx - 150;
}

void SimpleList::on_EliminarPosButton_clicked() {
    QString entero = ui->labelEliminarPos->text();
    if (entero.toInt() > list->largo || entero.toInt() < 1) {
        return;
    }
    list->eliminarPosicion(entero.toInt());
    recorreDibuja(list);
}

void SimpleList::on_EditarButton_clicked() {
    QString entero = ui->LabelEditarPos->text();
    if (entero.toInt() > list->largo || entero.toInt() < 1) {
        return;
    }
    list->editar(entero.toInt(), ui->LabelEditarVal->text());
    recorreDibuja(list);
}

void SimpleList::on_buscarButton_clicked() {
    QString entero = ui->labelBuscar->text();
    SimpleNode *runner = list->first;
    scene->clear();
    if (list->first == 0) {
        std::cout << "No hay elementos en la list" << std::endl;
    } else {
        while (runner != 0) {

            QFont font;
            font.setPixelSize(25);
            font.setBold(false);
            font.setFamily("Calibri");

            QBrush redBrush(Qt::red);
            QBrush greenBrush(Qt::green);
            QPen blackpen(Qt::black);
            blackpen.setWidth(6);
            if (runner->getPos() != entero.toInt()) {
                rectangle = scene->addRect(posx, 0, 100, 100, blackpen, greenBrush);
            }
            if (entero.toInt() == runner->getPos()) {
                rectangle = scene->addRect(posx, 0, 100, 100, blackpen, redBrush);
            }

            QPainterPath path;
            path.addText(posx + 45, 50, font, runner->getValue());
            scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if (runner != list->last) {
                QPolygonF Triangle;
                Triangle.append(QPointF(posx + 150., 45));
                Triangle.append(QPointF(posx + 130., 65.));
                Triangle.append(QPointF(posx + 130., 25.));
                Triangle.append(QPointF(posx + 150., 45.));

                scene->addLine(posx + 130., 45., posx + 105., 45., QPen(QBrush(Qt::black), 10));
                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            posx = posx + 150;
            runner = runner->next;
        }
        posx = 50;

    }

}

