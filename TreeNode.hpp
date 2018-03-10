#ifndef TREENODE_H
#define TREENODE_H


#include <iostream>
#include <string>

using std::string;
/**
  *@file TreeNode.hpp
  * @version 1.0
  * @date 9/3/18
  * @author Roger Valderrama
  * @title Tree Node
  * @brief Estructura del nodo para el arbol
  */
/**
 * @brief The TreeNode class Estructura del nodo para el arbol
 */
class TreeNode {
public:
    int dato;

public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    /**
 * @brief TreeNode incializa el nodo
 * @param dat
 */
    TreeNode(int dat) {
        dato = dat;
        left = nullptr;
        right = nullptr;
        parent = nullptr;

    }


public:
    /**
         * @brief setDato establece el dato del nodo
         * @param dat dato del nodo
         */
    void setDato(int dat) {
        this->dato = dat;
    }

public:
    /**
     * @brief getDato retorna el dato de un nodo
     * @return  entero del dato
     */
    int getDato() {
        return this->dato;
    }


};


#endif // TREENODE_H
