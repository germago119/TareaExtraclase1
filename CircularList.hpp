#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "CircularNode.hpp"
#include "QString"
#include <iostream>
#include <string>
#include <cstdio>

#include "CircularNode.hpp"

/**
  *@file CircularList.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title CircularList
  * @brief Estructura de datos lista circular
  */

/**
 * @brief The CircularList class contiene la estructura de datos de la lista circular
 */
class CircularList {
public:
    NodoListaCircular *first;
    NodoListaCircular *last;
    int largo = 0;


public:
    /**
     * @brief CircularList inicia la lista circular
     */
    CircularList() {
        first = last = null;
        last = first = null;
    }


public:
    /**
     * @brief ingresarDatoFinal ingresa un dato al final de la lista
     * @param val es un QString que es el dato del nodo
     */
    void ingresarDatoFinal(QString val) {

        NodoListaCircular *temporal = new NodoListaCircular(val);

        if (first == nullptr) {

            first = temporal;
            last = temporal;
            temporal->next = temporal;
            temporal->previous = temporal;
            largo = largo + 1;
        } else {

            last->next = temporal;
            temporal->previous = last;
            last = temporal;
            temporal->next = first;
            first->previous = temporal;
            largo = largo + 1;
        }

        NodoListaCircular *runner = first->next;
        int counter = 2;

        first->setPos(1);

        while (runner != first) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }

    }

public:
    /**
     * @brief ingresarDatoInicio ingresa un dato al inicio
     * @param value el dato del nodo
     */
    void ingresarDatoInicio(QString value) {
        NodoListaCircular *temporal = new NodoListaCircular(value);

        if (first == nullptr) {
            first = temporal;
            last = temporal;
            temporal->next = temporal;
            temporal->previous = temporal;
            largo = largo + 1;
        } else {

            temporal->next = first;
            first->previous = temporal;

            last->next = temporal;
            temporal->previous = last;
            first = temporal;
            largo = largo + 1;
        }

        NodoListaCircular *corredor = first->next;
        int counter = 2;

        first->setPos(1);

        while (corredor != first) {
            corredor->setPos(counter);
            counter = counter + 1;
            corredor = corredor->next;
        }
    }


public:
    /**
     * @brief insertarPorPosicion inserta un nodo en la lista por su posicion
     * @param pos entero que especifica la posicion en la que se quiere insertar
     * @param val dato que se le quiere dar al nodo insertado
     */
    void insertarPorPosicion(int pos, QString val) {

        NodoListaCircular *runner = first;
        NodoListaCircular *temporal = new NodoListaCircular(val);
        if (pos > largo) {
            std::cout << "El rango esta fuera del alcance" << std::endl;
            return;
        }

        if (pos == 1) {

            this->ingresarDatoInicio(val);

            NodoListaCircular *corredor = first->next;
            int counter = 2;

            first->setPos(1);

            while (corredor != first) {
                corredor->setPos(counter);
                counter = counter + 1;
                corredor = corredor->next;
            }
            return;
        }


        while (runner->getPos() != pos) {

            runner = runner->next;
        }

        if (runner->getPos() == pos) {

            temporal->next = runner;
            temporal->previous = runner->previous;
            runner->previous->next = temporal;
            runner->previous = temporal;


            NodoListaCircular *corredor = first->next;
            int counter = 2;

            first->setPos(1);

            while (corredor != first) {
                corredor->setPos(counter);
                counter = counter + 1;
                corredor = corredor->next;
            }
        } else {
            std::cout << "No se pudo eliminar el value" << std::endl;
        }

    }

public:
    /**
     * @brief eliminarPosicion eliminar un nodo por posicion
     * @param pos posicion del nodo que se quiere eliminar
     */
    void eliminarPosicion(int pos) {
        if (pos > largo) {
            std::cout << "No se pudo eliminar el value porque no existe tal position" << std::endl;
        }

        if (pos == 1) {
            eliminarInicio();
            return;
        }
        if (pos == largo) {
            eliminarFinal();
            return;
        }

        NodoListaCircular *runner = first;

        while (runner->getPos() != pos) {
            runner = runner->next;
        }

        if (runner->getPos() == pos) {

            runner->previous->next = runner->next;
            runner->next->previous = runner->previous;

            largo = largo - 1;


            NodoListaCircular *corredor = first->next;
            int counter = 2;

            first->setPos(1);

            while (corredor != first) {
                corredor->setPos(counter);
                counter = counter + 1;
                corredor = corredor->next;
            }
        } else {
            std::cout << "No se pudo eliminar el value" << std::endl;
        }

    }

public:
    /**
     * @brief eliminarInicio elimina el nodo inicial de la lista
     */
    void eliminarInicio() {

        first = first->next;
        last->next = first;
        first->previous = last;

        largo = largo - 1;

        NodoListaCircular *runner = first->next;
        int counter = 2;

        first->setPos(1);

        while (runner != first) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }

    }


public:
    /**
     * @brief eliminarFinal elimina el nodo final de la lista
     */
    void eliminarFinal() {
        last = last->previous;
        last->next = first;
        first->previous = last;


        largo = largo - 1;
        NodoListaCircular *runner = first->next;
        int counter = 2;

        first->setPos(1);

        while (runner != first) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }
    }

    // IMPRIMIR LISTA AL DERECHO

public:
    /**
     * @brief imprimirListaAlDerecho imprime la lista de inicio a fin
     */
    void imprimirListaAlDerecho() {
        NodoListaCircular *runner = first;
        if (first == nullptr) {
            std::cout << "No hay elementos en la list" << std::endl;
        } else {

            NodoListaCircular *corredor = first->next;
            int counter = 2;

            first->setPos(1);

            while (corredor != first) {

                counter = counter + 1;
                corredor = corredor->next;
            }
        }
    }



    //EDITAR POR POSICION

public:
    /**
     * @brief editar cambia el valor de un nodo en especifico
     * @param pos la posicion del nodo que se quiere editar
     * @param dato dato nuevo que se le quiere dar
     */
    void editar(int pos, QString dato) {

        if (pos > largo) {
            std::cout << "No se puede eliminar porque la pos es mayor que el largo" << std::endl;
        }

        NodoListaCircular *corredor = first;

        while (corredor->getPos() != pos) {
            corredor = corredor->next;
        }

        if (corredor->getPos() == pos) {
            corredor->setValue(dato);

        } else {
            std::cout << "No se pudo editar el value" << std::endl;
        }

    }

public:
    /**
     * @brief obtenerporPosicion retorna el nodo que se especifica en la posicion
     * @param pos posicion del nodo que se quiere retornar
     * @return
     */
    NodoListaCircular obtenerporPosicion(int pos) {

        if (pos < largo) {
            NodoListaCircular *corredor = first;

            while (corredor->getPos() != pos) {
                corredor = corredor->next;
            }

            return *corredor;
        } else {
            std::cout << "El largo es menor que la position digitada" << std::endl;
        }
    }

};


#endif // CIRCULARLIST_H
