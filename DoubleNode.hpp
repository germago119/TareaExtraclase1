#ifndef NODODOBLEENLAZADO_H
#define NODODOBLEENLAZADO_H

#include "QString"
#include <iostream>
#include <string>

#define null 0;
/**
  *@file DoubleNode.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Nodo para la lista doble enlazada
  * @brief Estructura de datos nodo para lista doble enlazada
  */
/**
 * @brief The NodoDobleEnlazado class Estructura de datos nodo para lista doble enlazada
 */
class DoubleNode {
private:
    QString value;
    int position;
public:
    DoubleNode *next;
    DoubleNode *previous;

    /**
     * @brief NodoDobleEnlazado inicializa el nodo
     * @param dat dato del nodo
     */
    DoubleNode(QString dat) {
        this->value = dat;
        next = null;
        previous = null;
    }

    /**
     * @brief getDato retorna el dato que contiene el nodo
     * @return QString del nodo
     */
    QString getDato() {
        return value;
    }

public:
    /**
     * @brief setPos establece la posicion en la lista del nodo
     * @param pos entero de la posicion
     */
    void setPos(int pos) {
        this->position = pos;
    }

public:
    /**
     * @brief getPos da la posicion del nodo
     * @return posicion del nodo
     */
    int getPos() {
        return this->position;
    }

public:
    /**
     * @brief setDato establece el dato del nodo
     * @param dat dato del nodo
     */
    void setDato(QString dat) {
        this->value = dat;
    }

};


#endif // NODODOBLEENLAZADO_H
