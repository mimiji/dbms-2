/*****************************************************************//**
 * \file   Node.h
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/
#pragma once

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
    * \brief Конструктор c параметрами
    */
    Node(const int data_) noexcept;
    /**
    * \brief Деструктор
    */
    ~Node() noexcept;
};