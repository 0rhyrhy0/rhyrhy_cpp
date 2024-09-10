#include "../headers/bst.h"
#include "../headers/bstError.h"
#include <iostream>

using std::cout;
using std::endl;

BST* BST::largest() { return right ? right->largest() : this; }
BST* BST::smallest() { return left ? left->smallest() : this; }


BST* BST::insert(int value) {
    if(this->value == value) {
        throw BSTsameValueExist(value);
    }

    // to the right
    if(this->value < value) {
        if(right) {
            right->insert(value);
            return this;
        }

        right = new BST(value);
        right->parent = this;
        return this;
    }

    // to the left
    if(left) {
        left->insert(value);
        return this;
    }

    left = new BST(value);
    left->parent = this;
    return this;
}
BST& BST::operator+ (int value) {
    return *this->insert(value);
}


BST* BST::find(int value) {
    // to the right
    if(this->value < value) {
        if(right) return right->find(value);
        throw BSTvalueNotFound(value);
    }

    // to the left
    if(this->value > value) {
        if(left) return left->find(value);
        throw BSTvalueNotFound(value);
    }

    // finding Node
    return this;
}


BST* BST::remove(int value) {
    BST* delNode = this->find(value);

    // root Node
    if (delNode->parent == nullptr) {
        // If the root node has no children
        if (delNode->left == delNode->right) {
            delete delNode;
            return nullptr; // Tree is now empty
        }

        // If the root node has only one child
        if (delNode->left == nullptr) {
            BST* newRoot = delNode->right;
            delNode->right = nullptr;
            delete delNode;
            newRoot->parent = nullptr;
            return newRoot;
        }

        if (delNode->right == nullptr) {
            BST* newRoot = delNode->left;
            delNode->left = nullptr;
            delete delNode;
            newRoot->parent = nullptr;
            return newRoot;
        }

        // If the root node has two children
        BST* replaceNode = delNode->left->largest();

        delNode->value = replaceNode->value;
        replaceNode->remove(replaceNode->value);

        return this;
    }

    // tail Node
    if(delNode->left == delNode->right) {
        if(delNode->parent->left == delNode) {
            delNode->parent->left = nullptr;
        } else {
            delNode->parent->right = nullptr;
        }

        delete delNode;
        return this;
    }

    // both sides full
    if(delNode->left && delNode->right) {
        BST* replaceNode = delNode->left->largest();

        delNode->value = replaceNode->value;
        replaceNode->remove(replaceNode->value);

        return this;
    }

    // left child only
    if(delNode->left) {
        if(delNode->parent->left == delNode)
            delNode->parent->left = delNode->left;
        else
            delNode->parent->right = delNode->left;

        delete delNode;
        return this;
    }

    // right child only
    if(delNode->parent->left == delNode)
        delNode->parent->left = delNode->right;
    else
        delNode->parent->right = delNode->right;

    delete delNode;
    return this;
}


void BST::show() const {
    showHelper();
    cout << endl;
}
void BST::showHelper() const {
    // cout << '[';
    if(left) left->showHelper();
    cout << ' ' << this->value << ' ';
    if(right) right->showHelper();
    // cout << ']';
}


int BST::calcHeight() const {
    // leaf node
    if(left == right) return 1;

    int l = left  ? left->calcHeight()  : 0;
    int r = right ? right->calcHeight() : 0;

    return 1 + (l>r ? l : r);
}


int BST::countNodes() const {
    // leaf node
    if(left == right) return 1;

    int l = left  ? left->countNodes()  : 0;
    int r = right ? right->countNodes() : 0;

    return 1 + l + r;
}


BST::~BST() {
    delete left;
    delete right;
}