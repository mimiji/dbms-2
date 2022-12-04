/*****************************************************************//**
 * \file   Node.h
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    /**
      * \brief Геттер для переменной data
      * \return data - данные
      */
    int get_data();

    /**
      * \brief Геттер для указателя left
      * \return data - данные
      */
    Node* get_left();

    /**
      * \brief Геттер для указателя right
      * \return data - данные
      */
    Node* get_right();
};