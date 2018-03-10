#include "circularView.hpp"
#include "ui_circularView.h"

#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>
#include "CircularList.hpp"

ViewCircularList::ViewCircularList(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ViewCircularList) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    list = new CircularList();
    int posx = 50;
}

ViewCircularList::~ViewCircularList() {
    delete ui;
}

void ViewCircularList::on_addButton_clicked() {
    list->ingresarDatoFinal(ui->addText->text());
    recorreDibuja(list);
}

void ViewCircularList::recorreDibuja(CircularList *lista) {


    if (lista->largo == 0) {
        return;
    }
    bool alreadyDrawn = false;
    NodoListaCircular *corredor = lista->first;
    scene->clear();
    if (lista->first == 0) {
        std::cout << "No hay elementos en la list" << std::endl;
        return;
    } else {
        while (corredor != lista->first || !alreadyDrawn) {

            alreadyDrawn = true;
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
            path.addText(posx + 45, 50, font, corredor->getValue());
            scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if (corredor->next != lista->first) {

                QPolygonF Triangle;
                Triangle.append(QPointF(posx + 150., 30));
                Triangle.append(QPointF(posx + 130., 50.));
                Triangle.append(QPointF(posx + 130., 10.));
                Triangle.append(QPointF(posx + 150., 30.));


                Triangle.append(QPointF(posx + 100., 60));
                Triangle.append(QPointF(posx + 120., 80.));
                Triangle.append(QPointF(posx + 120., 40.));
                Triangle.append(QPointF(posx + 100., 60.));

                scene->addLine(posx + 130., 30., posx + 105., 30., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 145., 60., posx + 120., 60., QPen(QBrush(Qt::black), 10));
                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));


            }
            if (corredor->next == lista->first) {
                scene->addLine(posx + 105., 45., posx + 130., 45., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 130., 45., posx + 130., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 130., -20., -25., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(-25., 45., -25., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(-25., 45., 0., 45., QPen(QBrush(Qt::black), 10));

                QPolygonF Triangle;
                Triangle.append(QPointF(20., 45));
                Triangle.append(QPointF(0., 65.));
                Triangle.append(QPointF(0., 25.));
                Triangle.append(QPointF(20., 45.));

                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            }
            posx = posx + 150;
            corredor = corredor->next;

        }
        posx = 50;
    }
}

void ViewCircularList::on_addInicioButton_clicked() {
    list->ingresarDatoInicio(ui->addInicio->text());
    recorreDibuja(list);
}

void ViewCircularList::on_ButtonInsertarporPos_clicked() {
    if (ui->labelTextoposicionInsertar->text().toInt() > list->largo ||
        ui->labelTextoposicionInsertar->text().toInt() < 1) {
        return;
    }
    list->insertarPorPosicion(ui->labelTextoposicionInsertar->text().toInt(), ui->labeltextovalor->text());
    recorreDibuja(list);
}

void ViewCircularList::on_EliminarInicioButton_clicked() {
    list->eliminarInicio();
    recorreDibuja(list);
}

void ViewCircularList::on_EliminarFinalButton_clicked() {
    list->eliminarFinal();
    recorreDibuja(list);
}

void ViewCircularList::on_EliminarPosButton_clicked() {
    if (ui->labelEliminarPos->text().toInt() > list->largo || ui->labelEliminarPos->text().toInt() < 1) {
        return;
    }
    list->eliminarPosicion(ui->labelEliminarPos->text().toInt());
    recorreDibuja(list);
}

void ViewCircularList::on_EditarButton_clicked() {
    if (ui->LabelEditarPos->text().toInt() > list->largo || ui->LabelEditarPos->text().toInt() < 1) {
        return;
    }
    list->editar(ui->LabelEditarPos->text().toInt(), ui->LabelEditarVal->text());
    recorreDibuja(list);
}

void ViewCircularList::on_buscarButton_clicked() {

    if (list->largo == 0) {
        return;
    }
    bool alreadyDrawn = false;
    NodoListaCircular *runner = list->first;
    scene->clear();
    if (list->first == nullptr) {
        std::cout << "No hay elementos en la list" << std::endl;
        return;
    } else {
        while (runner != list->first || !alreadyDrawn) {
            alreadyDrawn = true;
            QFont font;
            font.setPixelSize(25);
            font.setBold(false);
            font.setFamily("Calibri");

            QBrush redBrush(Qt::red);
            QBrush greenBrush(Qt::green);
            QPen blackpen(Qt::black);
            blackpen.setWidth(6);
            if (runner->getPos() != ui->labelBuscar->text().toInt()) {
                rectangle = scene->addRect(posx, 0, 100, 100, blackpen, greenBrush);
            }
            if (runner->getPos() == ui->labelBuscar->text().toInt()) {
                rectangle = scene->addRect(posx, 0, 100, 100, blackpen, redBrush);
            }
            QPainterPath path;
            path.addText(posx + 45, 50, font, runner->getValue());
            scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if (runner != list->last) {
                QPolygonF Triangle;
                Triangle.append(QPointF(posx + 150., 30));
                Triangle.append(QPointF(posx + 130., 50.));
                Triangle.append(QPointF(posx + 130., 10.));
                Triangle.append(QPointF(posx + 150., 30.));


                Triangle.append(QPointF(posx + 100., 60));
                Triangle.append(QPointF(posx + 120., 80.));
                Triangle.append(QPointF(posx + 120., 40.));
                Triangle.append(QPointF(posx + 100., 60.));

                scene->addLine(posx + 130., 30., posx + 105., 30., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 145., 60., posx + 120., 60., QPen(QBrush(Qt::black), 10));
                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            if (runner->next == list->first) {
                scene->addLine(posx + 105., 45., posx + 130., 45., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 130., 45., posx + 130., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(posx + 130., -20., -25., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(-25., 45., -25., -20., QPen(QBrush(Qt::black), 10));
                scene->addLine(-25., 45., 0., 45., QPen(QBrush(Qt::black), 10));

                QPolygonF Triangle;
                Triangle.append(QPointF(20., 45));
                Triangle.append(QPointF(0., 65.));
                Triangle.append(QPointF(0., 25.));
                Triangle.append(QPointF(20., 45.));

                scene->addPolygon(Triangle, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            }

            posx = posx + 150;
            runner = runner->next;
        }

        posx = 50;

    }
}


