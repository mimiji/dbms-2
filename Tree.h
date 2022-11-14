#pragma once

#include<iostream>

using namespace std;

/**
* \brief Узел дерева.
*/
class Node
{
private:
    /**
    * \brief Данные.
    */
    int data;

    /**
    * \brief Указатель на левый узел.
    */
    Node* left;

    /**
    * \brief Указатель на правый узел.
    */
    Node* right;

    friend class BinaryTree;
public:
    /**
    * \brief Конструктор по умолчанию
    */
    Node() noexcept;

    /**
    * \brief Деструктор
    */
    ~Node() noexcept;
};

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
     * \brief Рекурсивная процедура. Рекурсивно вызывает себя для удаления левого поддерева, правого поддерева, затем удаляет сам элемент.
     * \param rootPtr - указатель на узел
     */
    void deleteTree(Node* rootPtr);

    /**
     * \brief Вспомогательная функция для создания нового узла при каждом вызове функции insertNode
     * \param new_data - переменная с данными
     * \return newNode - указатель на узел
     */
    Node* createNode(const int new_data) noexcept;

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
     * \brief Метод find проверяет, содержится ли в дереве элемент со значением key
     * \param
     * \return возвращает true или false
     */
    bool findElement(const int key) const noexcept;

    /**
     * \brief Функция инвертирования заданного бинарного дерева с использованием прямого обхода
     * \param root - указатель на узел
     */
    void invertBinaryTree(Node* root) const noexcept;

    /**
     * \brief Функция для обхода заданного бинарного дерева в прямом порядке
     * \param root - корень дерева
     */
    void preOrder(Node* root) const;

    /**
     * \brief Геттер для переменной корня дерева
     * \return root - корень дерева
     */
    Node* get_root() const noexcept;

    /**
     * \brief Сеттер для переменной корня дерева
     * \param ptr - указатель на узел
     */
    void set_root(Node* ptr) noexcept;
};