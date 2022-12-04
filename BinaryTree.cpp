/*****************************************************************//**
 * \file   BinaryTree.cpp
 * 
 * \author Victoriya
 * \date   November 2022
 *********************************************************************/

#include "BinaryTree.h"

BinaryTree::BinaryTree() noexcept : root(nullptr) {}

BinaryTree::BinaryTree(const BinaryTree& other) noexcept : root(nullptr)
{
    std::vector<Node *> remaining;
    Node * current = other.root;
    while (current != nullptr)
    {
        insert(current->data);
        if (current->right != nullptr)
        {
            remaining.push_back(current->right);
        }
        if (current->left != nullptr)
        {
            current = current->left;
        }
        else if (remaining.empty())
        {
            break;
        }
        else 
        {
            current = remaining.back();
            remaining.pop_back();
        }
    }
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) noexcept
{
    if (this == &other)
        return *this;

    BinaryTree copy(other);
    std::swap(root, copy.root);

    return *this;
}

BinaryTree::BinaryTree(BinaryTree&& other) noexcept
{
    if (this == &other)
        return;

    other.root = nullptr;
}

BinaryTree& BinaryTree::operator=(BinaryTree&& other) noexcept
{
    if (this == &other)
        return *this;

    std::swap(root, other.root);

    return *this;
}

BinaryTree::~BinaryTree() noexcept
{
    deleteTree(root);
}

void BinaryTree::deleteTree(Node* rootPtr)
{
    if (rootPtr != nullptr)
    {
        deleteTree(rootPtr->left);
        deleteTree(rootPtr->right);
        delete rootPtr;
    }
}

Node* BinaryTree::insertNode(const int new_data, Node * rootPtr) noexcept
{
    if (rootPtr == nullptr)
    {
        rootPtr = new Node(new_data);
    }
    if (new_data < rootPtr->data)
    {
        rootPtr->left = insertNode(new_data, rootPtr->left);
    }
    else if (new_data > rootPtr->data)
    {
        rootPtr->right = insertNode(new_data, rootPtr->right);
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
        throw invalid_argument("Узел не найден!");
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
    Node* current = root;
    if (current != nullptr)
    {
        while (current && current->data != key)
        {
            if (current->data > key)
                current = current->left;
            else
                current = current->right;
        }
    }

    return current != nullptr;
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

void BinaryTree::insert(const int new_data) noexcept
{
    root = insertNode(new_data, root);
}

void BinaryTree::remove(const int new_data) noexcept
{
    root = deleteNode(root, new_data);
}

void BinaryTree::invert() noexcept
{
    invertBinaryTree(root);
}

std::ostream& operator<<(ostream& out, BinaryTree const& tree)
{
    std::vector<Node*> remaining;
    Node* current = tree.root;
    while (current != nullptr)
    {
        out << current->get_data() << ' ';
        if (current->get_right())
        {
            remaining.push_back(current->get_right());
        }
        if (current->get_left())
        {
            current = current->get_left();
        }
        else if (remaining.empty())
        {
            break;
        }
        else
        {
            current = remaining.back();
            remaining.pop_back();
        }
    }
    return out;
}