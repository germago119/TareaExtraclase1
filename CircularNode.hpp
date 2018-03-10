#ifndef NODOLISTACIRCULAR_H
#define NODOLISTACIRCULAR_H

#include "QString"
#include <iostream>
#include <string>

#define null 0;

/**
  *@file CircularNode.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Nodo Lista Circular
  * @brief Estructura del nodo de la lista circular
  */
/**
 * @brief The NodoListaCircular class Estructura del nodo de la lista circular
 */
class NodoListaCircular {
private:
    QString value;
    int position;
public:
    NodoListaCircular *next;
    NodoListaCircular *previous;

    /**
     * @brief NodoListaCircular inicializa el nodo
     * @param val dato que va a contener el nodo
     */
    NodoListaCircular(QString val) {

        this->value = val;

        next = null;

        previous = null;

    }

    /**
     * @brief getValue da el dato que contiene el nodo
     * @return dato del nodo
     */
    QString getValue() {
        return value;
    }

public:
    /**
     * @brief setPos establece la posicion del nodo
     * @param pos posicion del nodo
     */
    void setPos(int pos) {
        this->position = pos;
    }

public:
    /**
     * @brief getPos da la posicon del nodo
     * @return  entero de la posicion
     */
    int getPos() {
        return this->position;
    }

public:
    /**
     * @brief setValue establece el dato del nodo
     * @param val dato del nodo
     */
    void setValue(QString val) {
        this->value = val;
    }

};


#endif // NODOLISTACIRCULAR_H
