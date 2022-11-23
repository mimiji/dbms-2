/*****************************************************************//**
 * \file   Node.cpp 
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/

#include "Node.h"

Node::Node() noexcept : data(), left(nullptr), right(nullptr)
{}

Node::Node(const int data_) noexcept : data(data_), left(nullptr), right(nullptr)
{}

Node::~Node()
{
    if (this->left == this)
    {
        this->left = nullptr;
    }
    else
    {
        this->right = nullptr;
    }

    this->left = nullptr;
    this->right = nullptr;
}