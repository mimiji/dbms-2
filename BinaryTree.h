/*****************************************************************//**
 * \file   BinaryTree.h
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/

#pragma once

#include<iostream>
#include"Node.h"

using namespace std;

/**
* \brief Класс дерево.
*/
class BinaryTree
{
private:

    /**
    * \*brief Корень деерва.
    */
    Node* root;

    /**
    * \brief Рекурсивная процедура. Рекурсивно вызывает себя для удаления левого поддерева, правого поддерева, затем удаляет сам элемент.
    * \param rootPtr - указатель на узел
    */
    void deleteTree(Node* rootPtr);

    /**
     * \brief Вставка узла
     * \param rootPtr - указатель на узел, new_data - переменная с данными
     * \return rootPtr - указатель на узел
     */
    Node* insertNode(Node* rootPtr, const int new_data) noexcept;

    /**
    * \brief Функция,помогающая получить предшественника по порядку для удаления узла из дерева
    * \param rootPtr - указатель на узел
    * \return rootPtr - указатель на узел
    */
    Node* findMinimum(Node* rootPtr) const noexcept;

    /**
     * \brief Удаление узла
     * \param rootPtr - указатель на узел, data_ - переменная с данными
     * \return rootPtr - указатель на узел
     */
    Node* deleteNode(Node* rootPtr, const int data_);

    /**
    * \brief Функция поворота бинарного дерева
    * \param root - указатель на узел
    */
    void invertBinaryTree(Node* root) const noexcept;

    /**
     * \brief Функция для обхода заданного бинарного дерева в прямом порядке
     * \param root - корень дерева
     */
    void preOrder(Node* root) const;

public:
    /**
    * \brief Конструктор по умолчанию
    */
    BinaryTree() noexcept;

    /**
    * \brief Деструктор
    */
    ~BinaryTree() noexcept;

    /**
     * \brief Метод find проверяет, содержится ли в дереве элемент со значением key
     * \param key - ключ
     * \return возвращает true или false
     */
    bool findElement(const int key) const noexcept;
};