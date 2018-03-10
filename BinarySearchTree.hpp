#ifndef BINARYTREE_H
#define BINARYTREE_H

/**
  *@file BinarySearchTree.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Binary Tree
  * @brief Archivo que tiene lo relacionado al arbol binario de busqueda
  */

#include <iostream>
#include <string>

#include "TreeNode.hpp"

using std::string;

/**
 * @brief The BinarySearchTree class que maneja la estructura del arbol binario de busqueda
 */
class BinarySearchTree {

private:
    TreeNode *root;


public:
    /**
         * @brief BinaryTree inicia el arbol binario de busqueda
         */
    BinarySearchTree() {
        root = nullptr;
    }

public:
    TreeNode *getRoot() {
        return root;
    }

public:
    /**
     * @brief insertarNodo inserta un nodo
     * @param value es el dato del nodo
     */
    void insertarNodo(int value) {
        string posFinal;
        TreeNode *parent = nullptr;
        TreeNode *runner = root;
        auto *temporal = new TreeNode(value);

        if (root == nullptr) {

            root = temporal;
            return;

        } else {
            while (runner != nullptr) {


                if (runner->getDato() > value) {


                    if (runner->left == nullptr) {
                        temporal->parent = runner;
                        parent = runner;
                        posFinal = "izquierda";

                    }

                    runner = runner->left;


                } else if (runner->getDato() < value) {

                    if (runner->right == nullptr) {
                        temporal->parent = runner;
                        parent = runner;
                        posFinal = "derecha";
                    }

                    runner = runner->right;


                }
            }

            if (posFinal == "izquierda") {

                parent->left = temporal;

            }
            if (posFinal == "derecha") {

                parent->right = temporal;

            }


        }
    }

public:
    /**
     * @brief recorridoPreOrder es el dato del nodo
     * @param node nodo inicial desde donde se va a recorrer
     */
    void recorridoPreOrder(TreeNode *node) {
        if (node != nullptr) {
            std::cout << "El recorrido del arbol es: " << node->getDato() << std::endl;
            recorridoPreOrder(node->left);
            recorridoPreOrder(node->right);
        }
    }


public:
    /**
 * @brief eliminar busca el nodo que se quiere eliminar
 * @param node nodo por el que se esta recorriendo
 * @param buscado valor entero que determina el valor buscado
 */
    void eliminar(TreeNode *node, int buscado) {
        if (root == nullptr) {
            return;
        } else if (buscado < node->getDato()) {
            eliminar(node->left, buscado);
        } else if (buscado > node->getDato()) {
            eliminar(node->right, buscado);
        } else {
            removeNodo(node);
        }
    }

public:
    bool removeNodo(TreeNode *nodo) {
        bool tieneNodoDerecha = nodo->right != nullptr;
        bool tieneNodoIzquierda = nodo->left != nullptr;
        if (!tieneNodoDerecha && !tieneNodoIzquierda) {
            return removeNodoCaso1(nodo);
        }


        if (tieneNodoDerecha && !tieneNodoIzquierda) {
            return removeNodoCaso2(nodo);
        }


        if (!tieneNodoDerecha && tieneNodoIzquierda) {
            return removeNodoCaso2(nodo);
        }


        if (tieneNodoDerecha && tieneNodoIzquierda) {
            return removeNodoCaso3(nodo);
        }

        return false;
    }


public:
    bool removeNodoCaso1(TreeNode *nodo) {

        TreeNode *hijoIzquierdo = nodo->parent->left;
        TreeNode *hijoDerecho = nodo->parent->right;

        if (hijoIzquierdo == nodo) {
            nodo->parent->left = nullptr;

            return true;
        }

        if (hijoDerecho == nodo) {
            nodo->parent->right = nullptr;

            return true;
        }

        return false;
    }


public:
    bool removeNodoCaso2(TreeNode *nodo) {


        TreeNode *hijoIzquierdo = nodo->parent->left;
        TreeNode *hijoDerecho = nodo->parent->right;


        TreeNode *hijoActual = nodo->left != nullptr ?
                               nodo->left : nodo->right;

        if (hijoIzquierdo == nodo) {
            nodo->parent->left = hijoActual;


            hijoActual->parent = nodo->parent;
            nodo->right = nullptr;
            nodo->left = nullptr;


            return true;
        }

        if (hijoDerecho == nodo) {
            nodo->parent->right = hijoActual;


            hijoActual->parent = nodo->parent;
            hijoActual->right = nullptr;
            nodo->right = nullptr;
            nodo->left = nullptr;


            return true;
        }

        return false;
    }


public:
    bool removeNodoCaso3(TreeNode *nodo) {

        TreeNode *nodoMasALaIzquierda = recorrerIzquierda(nodo->right);
        if (nodoMasALaIzquierda != nullptr) {

            nodo->setDato(nodoMasALaIzquierda->dato);


            removeNodo(nodoMasALaIzquierda);
            return true;
        }
        return false;
    }

public:
    TreeNode *recorrerIzquierda(TreeNode *nodo) {
        if (nodo->left != nullptr) {
            return recorrerIzquierda(nodo->left);
        }
        return nodo;
    }


};


#endif // BINARYTREE_H
