#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <QDialog>
#include "QGraphicsScene"
#include "SimpleLinkedList.hpp"

/**
  *@file simpleLinkedView.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title ListaSimple
  * @brief contiene lo referente a la ventana de la lista simple
  */
namespace Ui {
    class SimpleList;
}
/**
 * @brief The ListaSimple class clase que contiene lo referente a la ventana de la lista simple
 */
class SimpleList : public QDialog {
Q_OBJECT


public:
    explicit SimpleList(QWidget *parent = 0);

    ~SimpleList();

private slots:

    /**
     * @brief recorreDibuja Este metodo recorre la lista y la dibuja en el recuadro
     * @param lista la lista que se va a dibujar
     */
    void recorreDibuja(SimpleLinkedList *lista);

    /**
     * @brief on_addButton_clicked anade un elemento a la lista
     */
    void on_addButton_clicked();

    /**
     * @brief on_addInicioButton_clicked anade un nodo al inicio de la lista
     */
    void on_addInicioButton_clicked();

    /**
     * @brief on_ButtonInsertarporPos_clicked inserta un nodo por la posicion requerida
     */
    void on_ButtonInsertarporPos_clicked();

    /**
     * @brief on_EliminarInicioButton_clicked elimina el nodo del inicio
     */
    void on_EliminarInicioButton_clicked();

    /**
     * @brief on_EliminarFinalButton_clicked elimina el nodo al final de la lista
     */
    void on_EliminarFinalButton_clicked();

    /**
     * @brief on_EliminarPosButton_clicked elimina un nodo por la posicion dicha
     */
    void on_EliminarPosButton_clicked();

    /**
     * @brief on_EditarButton_clicked edita el dato que contiene un nodo
     */
    void on_EditarButton_clicked();

    /**
     * @brief on_buscarButton_clicked busca y resalta el nodo en la lista
     */
    void on_buscarButton_clicked();

private:
    Ui::SimpleList *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *dato;

public:
    SimpleLinkedList *list;
    int posx;
};


#endif // LISTASIMPLE_H
