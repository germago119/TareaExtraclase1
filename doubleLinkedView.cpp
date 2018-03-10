#include "doubleLinkedView.hpp"
#include "ui_doubleLinkedView.h"

#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>

DoubleLinked::DoubleLinked(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::DoubleLinked) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    lista = new DobleLinkedList();
    int posx = 50;
}

DoubleLinked::~DoubleLinked() {
    delete ui;
}

void DoubleLinked::on_addFinalButton_clicked() {
    lista->ingresarDatoFinal(ui->LabelAddFinal->text());
    recorreDibuja(lista);
}

void DoubleLinked::recorreDibuja(DobleLinkedList *lista) {

    std::cout << "El largo de la list es:" << lista->largo << std::endl;
    if (lista->largo == 0) {
        return;
    }
    DoubleNode *corredor = lista->first;
    scene->clear();
    if (lista->first == 0) {
        std::cout << "No hay elementos en la list" << std::endl;
        return;
    } else {
        while (corredor != 0) {

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
            path.addText(posx + 45, 50, font, corredor->getDato());
            scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if (corredor != lista->last) {
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

            posx = posx + 150;
            corredor = corredor->next;
        }
        posx = 50;

    }
}

void DoubleLinked::on_addInicioButton_clicked() {
    lista->ingresarDatoInicio(ui->LabeladdInicio->text());
    recorreDibuja(lista);
}

void DoubleLinked::on_ButtonInsertarporPos_clicked() {
    QString pos = ui->labelTextoposicionInsertar->text();
    if (pos.toInt() > lista->largo || pos.toInt() < 1) {
        return;
    }
    lista->insertarPorPosicion(pos.toInt(), ui->labeltextovalor->text());
    recorreDibuja(lista);
}

void DoubleLinked::on_EliminarInicioButton_clicked() {
    lista->eliminarInicio();
    recorreDibuja(lista);
}

void DoubleLinked::on_EliminarFinalButton_clicked() {
    lista->eliminarFinal();
    recorreDibuja(lista);
}

void DoubleLinked::on_EliminarPosButton_clicked() {
    QString posicion = ui->labelEliminarPos->text();
    if (posicion.toInt() > lista->largo || posicion.toInt() < 1) {
        return;
    }
    lista->eliminarPosicion(posicion.toInt());
    recorreDibuja(lista);
}

void DoubleLinked::on_EditarButton_clicked() {
    std::cout << "ENTRO" << std::endl;
    if (ui->LabelEditarPos->text().toInt() > lista->largo || ui->LabelEditarPos->text().toInt() < 1) {
        return;
    }
    lista->editar(ui->LabelEditarPos->text().toInt(), ui->LabelEditarVal->text());
    recorreDibuja(lista);
}

void DoubleLinked::on_buscarButton_clicked() {

    {
        QString entero = ui->labelBuscar->text();
        DoubleNode *runner = lista->first;
        scene->clear();
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
                if (runner->getPos() != entero.toInt()) {
                    rectangle = scene->addRect(posx, 0, 100, 100, blackpen, greenBrush);
                }
                if (runner->getPos() == entero.toInt()) {
                    rectangle = scene->addRect(posx, 0, 100, 100, blackpen, redBrush);
                }
                QPainterPath path;
                path.addText(posx + 45, 50, font, runner->getDato());
                scene->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

                if (runner != lista->last) {
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

                posx = posx + 150;
                runner = runner->next;
            }
            posx = 50;

        }
    }
}
