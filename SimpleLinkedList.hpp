#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H


#include "QString"
#include "SimpleNode.hpp"

#define null 0;


/**
  *@file SimpleLinkedList.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Simple Linked List
  * @brief Estructura de la lista simple
  */
/**
 * @brief The SimpleLinkedList class Estructura de la lista simple
 */
class SimpleLinkedList {
public:
    SimpleNode *first;
    SimpleNode *last;
    int largo = 0;


public:
    /**
     * @brief SimpleLinkedList incializa la lista simple
     */
    SimpleLinkedList() {
        first = last = null;
        last = first = null;
    }


public:
    /**
 * @brief insertarPorPosicion inserta un nodo en una posicion en especifico
 * @param pos posicon en la que se va a insertar
 * @param dato dato del nodo
 */
    void insertarPorPosicion(int pos, QString dato) {

        SimpleNode *runner = first;
        SimpleNode *temporal = new SimpleNode(dato);
        std::cout << largo << std::endl;
        if (pos > largo) {
            std::cout << "El rango esta fuera del alcance: " << pos << ", ya que se tiene un largo = " << largo
                      << std::endl;
            return;
        }
        if (pos == 1) {

            this->ingresarDatoInicio(dato);


            SimpleNode *runner2 = first;
            int counter = 1;
            while (runner2 != 0) {
                runner2->setPos(counter);
                counter = counter + 1;
                runner2 = runner2->next;
            }
            return;
        } else {

            while (runner->getPos() != (pos - 1)) {
                runner = runner->next;
            }

            if (runner->next->getPos() == pos) {
                temporal->next = runner->next;
                runner->next = temporal;

                SimpleNode *corredor2 = first;
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

    }


public:
    /**
     * @brief ingresarDatoFinal inserta un dato al final de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoFinal(QString dato) {

        SimpleNode *temporal = new SimpleNode(dato);

        if (first == 0) {
            first = temporal;
            last = temporal;
            largo = largo + 1;
        } else {
            last->next = temporal;
            last = temporal;
            largo = largo + 1;
        }

        SimpleNode *corredor = first;
        int counter = 1;

        while (corredor != 0) {
            corredor->setPos(counter);
            counter = counter + 1;
            corredor = corredor->next;
        }


    }


public:
    /**
     * @brief ingresarDatoInicio inserta un nodo al inicio de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoInicio(QString dato) {
        SimpleNode *temporal = new SimpleNode(dato);

        if (first == 0) {
            first = temporal;
            last = temporal;
            largo = largo + 1;
        } else {
            temporal->next = first;
            first = temporal;
            largo = largo + 1;
        }

        SimpleNode *corredor = first;
        int counter = 1;
        while (corredor != 0) {
            corredor->setPos(counter);
            counter = counter + 1;
            corredor = corredor->next;
        }
    }


public:
    /**
     * @brief eliminarPosicion elimina un nodo en una posicion en especifico
     * @param pos posicion en la que se va a eliminar
     */
    void eliminarPosicion(int pos) {
        SimpleNode *corredor = first;
        while (corredor->getPos() != (pos - 1)) {
            corredor = corredor->next;
        }
        if (corredor->next->getPos() == pos) {

            corredor->next = corredor->next->next;
            largo = largo - 1;


            SimpleNode *corredor2 = first;
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
     * @brief eliminarInicio elimina el nodo del inicio de la lista
     */
    void eliminarInicio() {
        first = first->next;

        largo = largo - 1;
        SimpleNode *corredor = first;
        int counter = 1;
        while (corredor != 0) {
            corredor->setPos(counter);
            counter = counter + 1;
            corredor = corredor->next;


            SimpleNode *corredor2 = first;
            int counter = 1;
            while (corredor2 != 0) {
                corredor2->setPos(counter);
                counter = counter + 1;
                corredor2 = corredor2->next;
            }
        }
    }


public:
    /**
     * @brief eliminarFinal elimina el nodo del final de la lista
     */
    void eliminarFinal() {

        if (first == 0) {
            return;
        } else {

            SimpleNode *corredor = first;
            int counter = 1;

            while (corredor->next != last) {

                corredor->setPos(counter);
                counter = counter + 1;
                corredor = corredor->next;
            }
            corredor->next = 0;
            last = corredor;
            delete (corredor->next);
            largo = largo - 1;

        }
    }


public:
    /**
     * @brief imprimirLista imprime la lista
     */
    void imprimirLista() {
        SimpleNode *corredor = first;
        if (first == 0) {
            std::cout << "No hay elementos en la list" << std::endl;
        } else {
            while (corredor != 0) {

                corredor = corredor->next;
            }
        }
    }


public:
    /**
     * @brief editar edita el dato de un nodo en especifico
     * @param pos posicion del nodo que se quiere editar
     * @param dato dato por el que se quiere modificar
     */
    void editar(int pos, QString dato) {


        SimpleNode *corredor = first;

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
     * @brief obtenerporPosicion retorna el nodo que se esta buscando
     * @param pos posicion del nodo buscado
     * @return el nodo buscado
     */
    SimpleNode obtenerporPosicion(int pos) {
        SimpleNode *corredor = first;
        if (pos < largo) {


            while (corredor->getPos() != pos) {
                corredor = corredor->next;
            }
            return *corredor;
        } else {
            corredor;

        }

    }


};


#endif // SIMPLELINKEDLIST_H
