#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

#include "QString"
#include <iostream>
#include <string>

using std::string;
#define null 0;

/**
  *@file SimpleNode.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Nodo Simple
  * @brief Estructura del nodo de la lista simple
  */
/**
 * @brief The NodoSimple class Estructura del nodo de la lista simple
 */
class SimpleNode {
private:
    QString value;
    int position;
public:
    SimpleNode *next;

    /**
 * @brief NodoSimple inicia el nodo
 * @param dat
 */
    SimpleNode(QString dat) {
        this->value = dat;
        next = null;
    }

    /**
     * @brief getDato da el dato del nodo
     * @return QString del nodo
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
      * @brief getPos da la posicion del nodo
      * @return entero con la posicion del nodo
      */
    int getPos() {
        return this->position;
    }

public:
    /**
    * @brief setDato establece el dato del nodo
    * @param dat dato del nodo
    */
    void setValue(QString dat) {
        this->value = dat;
    }
};


#endif // NODOSIMPLE_H
