#include <iostream>
#include "bst.h"
using namespace std;


BinarySearchTree::BinarySearchTree(){
    /* Set all initial nodes to null pointers */
    root = root->right = root->left = nullptr;
}

void BinarySearchTree::insert(const int &key, BinaryNode *&root) {

    /* Insert root if empty */
    if (root == nullptr) {
        root = new BinaryNode;
        root->left = root->right = nullptr;
        root->data = key;
    }
    else if (key < root->data) // recurse through nodes
        insert(key, root->left);
    else if (key > root->data)
        insert(key, root->right);
}

void BinarySearchTree::levelorder(BinaryNode *root) {
    if (root)
        q.push(root);
    while (!q.empty()) // while the queue exists
    {
        const BinaryNode * const temp_node = q.front();
        q.pop();
        cout<<temp_node->data<<" ";

        /* Push nodes in the order to traverse */
        /* Left node added first, then right node */
        if(temp_node->left)
            q.push(temp_node->left);
        if (temp_node->right)
            q.push(temp_node->right);
    }
}

void BinarySearchTree::makeEmpty(BinaryNode *&root) {
    /* Recursively delete nodes */
    if (root != nullptr) {
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
    /* If inputted node is a null pointer */
    /* then leave it as such */
    root = nullptr;
}