#ifndef DOBLELINKEDLIST_H
#define DOBLELINKEDLIST_H

#include "DoubleNode.hpp"
#include "QString"
#include <iostream>
#include <string>


/**
  *@file DoubleLinkedList.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title DobleLinkedList
  * @brief Estructura de datos lista doblemente enlanzada
  */
/**
 * @brief The DobleLinkedList class contiene la estructura de las listas doblemente enlazadas
 */
class DobleLinkedList {
public:
    DoubleNode *first;
    DoubleNode *last;
    int largo = 0;


public:
    /**
     * @brief DobleLinkedList inicia la lista enlazada
     */
    DobleLinkedList() {
        first = last = 0;
        last = first = 0;
    }


public:
    /**
     * @brief insertarPorPosicion inserta un nodo en una posicion especifica
     * @param pos posicion en la que se va a insertar
     * @param val dato del nodo
     */
    void insertarPorPosicion(int pos, QString val) {

        DoubleNode *runner = first;
        DoubleNode *temporal = new DoubleNode(val);
        if (pos > largo) {
            std::cout << "El rango esta fuera del alcance" << std::endl;
            return;
        }

        if (pos == 1) {

            this->ingresarDatoInicio(val);

            DoubleNode *runner2 = first;
            int counter = 1;
            while (runner2 != 0) {
                runner2->setPos(counter);
                counter = counter + 1;
                runner2 = runner2->next;
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


            DoubleNode *runner3 = first;
            int counter = 1;
            while (runner3 != 0) {
                runner3->setPos(counter);
                counter = counter + 1;
                runner3 = runner3->next;
            }
        } else {
            std::cout << "No se pudo eliminar el value" << std::endl;
        }

    }


public:
    /**
     * @brief ingresarDatoFinal ingresa un dato al final de la lista
     * @param val dato del nodo
     */
    void ingresarDatoFinal(QString val) {

        DoubleNode *temporal = new DoubleNode(val);

        if (first == nullptr) {

            first = temporal;
            last = temporal;
            largo = largo + 1;
        } else {

            last->next = temporal;
            temporal->previous = last;
            last = temporal;
            largo = largo + 1;
        }

        DoubleNode *runner = first;
        int counter = 1;

        while (runner != 0) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }


    }


public:
    /**
     * @brief ingresarDatoInicio ingresa un dato al inicio de la lista
     * @param val dato del nodo
     */
    void ingresarDatoInicio(QString val) {
        DoubleNode *temporal = new DoubleNode(val);

        if (first == nullptr) {
            first = temporal;
            last = temporal;
            largo = largo + 1;
        } else {
            temporal->next = first;
            first->previous = temporal;
            first = temporal;
            largo = largo + 1;
        }

        DoubleNode *runner = first;
        int counter = 1;
        while (runner != 0) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }
    }


public:
    /**
     * @brief eliminarPosicion elimina un nodo por la posicion
     * @param pos posicion del nodo a eliminar
     */
    void eliminarPosicion(int pos) {
        std::cout << "  El largo de la list es :" << this->largo << std::endl;
        DoubleNode *runner = first;

        if (pos == 1) {
            this->eliminarInicio();
            largo = largo - 1;
            DoubleNode *runner2 = first;
            int counter = 1;
            while (runner2 != 0) {
                runner2->setPos(counter);
                counter = counter + 1;
                runner2 = runner2->next;
            }
            return;
        }
        if (pos == last->getPos()) {
            this->eliminarInicio();
            largo = largo - 1;
            DoubleNode *corredor2 = first;
            int counter = 1;
            while (corredor2 != 0) {
                corredor2->setPos(counter);
                counter = counter + 1;
                corredor2 = corredor2->next;
            }
            return;
        }

        while (runner->getPos() != pos) {
            runner = runner->next;
        }


        if (runner->getPos() == pos) {

            runner->previous->next = runner->next;

            runner->next->previous = runner->previous;


            largo = largo - 1;


            DoubleNode *corredor2 = first;
            int counter = 1;
            while (corredor2 != 0) {
                corredor2->setPos(counter);
                counter = counter + 1;
                corredor2 = corredor2->next;
            }
        } else {
            std::cout << "No se pudo eliminar el value" << std::endl;
        }

    }

public:
    /**
     * @brief eliminarInicio elimina el nodo del inicio
     */
    void eliminarInicio() {

        first = first->next;
        first->previous = 0;

        largo = largo - 1;


        DoubleNode *corredor = first;
        int counter = 1;
        while (corredor != nullptr) {
            corredor->setPos(counter);
            counter = counter + 1;
            corredor = corredor->next;


            DoubleNode *corredor2 = first;
            int counter2 = 1;
            while (corredor2 != nullptr) {
                corredor2->setPos(counter2);
                counter2 = counter2 + 1;
                corredor2 = corredor2->next;
            }
        }
    }


public:
    /**
     * @brief eliminarFinal elimina el nodo del final de la lista
     */
    void eliminarFinal() {


        last = last->previous;
        last->next = 0;


        largo = largo - 1;
        DoubleNode *runner = first;
        int counter = 1;
        while (runner != nullptr) {
            runner->setPos(counter);
            counter = counter + 1;
            runner = runner->next;
        }
    }


public:
    /**
     * @brief imprimirListaAlRevez imprime la lista al revez
     */
    void imprimirListaAlRevez() {
        DoubleNode *runner = last;
        if (first == nullptr) {
            std::cout << "No hay elementos en la list" << std::endl;
        } else {
            while (runner != 0) {


                runner = runner->previous;
            }
        }
    }

public:
    /**
     * @brief imprimirListaDerecho imprime la lista al derecho
     */
    void imprimirListaDerecho() {
        DoubleNode *runner = first;
        if (first == nullptr) {
            std::cout << "No hay elementos en la list" << std::endl;
        } else {
            while (runner != 0) {


                runner = runner->next;
            }
        }
    }


public:
    /**
     * @brief editar cambia el dato del nodo escogido
     * @param pos posicion del nodo que se quiere insertar
     * @param val dato que se quiere cambiar
     */
    void editar(int pos, QString val) {


        DoubleNode *runner = first;

        while (runner->getPos() != pos) {
            runner = runner->next;
        }

        if (runner->getPos() == pos) {
            runner->setDato(val);

        } else {
            std::cout << "No se pudo editar el value" << std::endl;
        }

    }

public:
    /**
     * @brief obtenerporPosicion retorna el nodo que se esta buscando
     * @param pos posicion del nodo buscado
     * @return el nodo buscado
     */
    DoubleNode obtenerporPosicion(int pos) {

        if (pos < largo) {
            DoubleNode *runner = first;

            while (runner->getPos() != pos) {
                runner = runner->next;
            }

            return *runner;
        } else {
            std::cout << "El largo es menor que la position digitada" << std::endl;
            while (true) {
                break;
            }

        }
    }


};


#endif // DOBLELINKEDLIST_H
