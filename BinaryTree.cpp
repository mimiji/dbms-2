/*****************************************************************//**
 * \file   BinaryTree.cpp
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/

#include "BinaryTree.h"

BinaryTree::BinaryTree() noexcept : root(nullptr)
{}

BinaryTree::~BinaryTree() noexcept
{
    deleteTree(root);
}

void BinaryTree::deleteTree(Node* rootPtr)
{
    if (rootPtr)
    {
        deleteTree(rootPtr->left);
        deleteTree(rootPtr->right);
        delete rootPtr;
    }
}

Node* BinaryTree::insertNode(Node* rootPtr, const int new_data) noexcept
{
    if (rootPtr == nullptr)
    {
        Node* newNode = new Node(new_data);
    }
    if (new_data < rootPtr->data)
    {
        rootPtr->left = insertNode(rootPtr->left, new_data);
    }
    if (new_data > rootPtr->data)
    {
        rootPtr->right = insertNode(rootPtr->right, new_data);
    }
    return rootPtr;
}

Node* BinaryTree::findMinimum(Node* rootPtr) const noexcept
{
    while (rootPtr->left != nullptr)
    {
        rootPtr = rootPtr->left;
    }
    return rootPtr;
}

Node* BinaryTree::deleteNode(Node* rootPtr, const int data_)
{
    if (rootPtr == nullptr)
    {
        throw invalid_argument("”зел не найден!");
    }
    else if (data_ < rootPtr->data)
    {
        rootPtr->left = deleteNode(rootPtr->left, data_);
    }
    else if (data_ > rootPtr->data)
    {
        rootPtr->right = deleteNode(rootPtr->right, data_);
    }
    else
    {
        if (rootPtr->left == nullptr && rootPtr->right == nullptr)
        {
            delete rootPtr;
            rootPtr = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }
        else if (rootPtr->right == nullptr)
        {
            Node* temp = rootPtr;
            rootPtr = rootPtr->left;
            delete temp;
        }
        else
        {
            Node* temp = findMinimum(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->left = deleteNode(rootPtr->right, temp->data);
        }
    }

    return rootPtr;
}

bool BinaryTree::findElement(const int key) const noexcept
{
    Node* curr = root;
    while (curr && curr->data != key)
    {
        if (curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr != NULL;
}

void BinaryTree::invertBinaryTree(Node* root) const noexcept
{
    if (root == nullptr) {
        return;
    }

    swap(root->left, root->right);

    invertBinaryTree(root->left);

    invertBinaryTree(root->right);
}

void BinaryTree::preOrder(Node* root)  const
{
    if (root != nullptr)
    {
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}