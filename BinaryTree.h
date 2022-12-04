/*****************************************************************//**
 * \file   BinaryTree.h
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/

#pragma once

#include"Node.h"

using namespace std;

/**
* \brief Класс дерево.
*/
class BinaryTree
{
private:

    /**
    * \*brief Корень дерева.
    */
    Node* root;

    /**
    * \brief Рекурсивная процедура. Рекурсивно вызывает себя для удаления левого поддерева, правого поддерева, затем удаляет сам элемент.
    * \param rootPtr - указатель на узел
    */
    void deleteTree(Node* rootPtr);

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
     * \brief Вставка узла
     * \param rootPtr - указатель на узел, new_data - переменная с данными
     * \return rootPtr - указатель на узел
     */
    Node* insertNode(const int new_data, Node* t) noexcept;


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
     * \brief Конструктор копирования
     */
    BinaryTree(const BinaryTree& other) noexcept;

    /**
     * \brief Оператор копирования
     */
    BinaryTree& operator=(const BinaryTree& other) noexcept;

    /**
     * \brief Конструктор перемещения
     */
    BinaryTree(BinaryTree&& other) noexcept;

    /**
     * \brief Оператор перещения
     */
    BinaryTree& operator=(BinaryTree&& other) noexcept;

    /**
     * \brief Геттер для корня дерева
     * \return root - корень дерева
     */
    Node* get_root()
    {
        return root;
    }

    /**
     * \brief Метод find проверяет, содержится ли в дереве элемент со значением key
     * \param key - ключ
     * \return возвращает true или false
     */
    bool findElement(const int key) const noexcept;

    /**
     * \brief Вставка узла (функция в области public)
     * \param new_data - переменная с данными
     */
    void insert(const int new_data) noexcept;

    /**
     * \brief Удаление узла (функция в области public)
     * \param new_data - переменная с данными
     */
    void remove(const int new_data) noexcept;

    /**
     * \brief Поворот дерева (функция в области public)
     */
    void invert() noexcept;

    /**
    * \brief Оператор сдвига дерева в стандартный поток ввода-вывода.
    * \param out Cтандартный поток ввода-вывода.
    * \param tree Дерево.
    */
    friend std::ostream& operator<<(ostream& out, BinaryTree const& tree);
};