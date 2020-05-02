#ifndef _BSTREE_H
#define _BSTREE_H

#include <iostream>
#include <queue>
#include <stack>
#include "btree.h"
using namespace std;

class BSTree: public BTree{
    public:
        BSTree();
        BSTree(int arr[], int length);
        ~BSTree();
        // tree ops
        void insert_node(int value);
        void delete_node(int value);
        bool find_node(int value);
    private:
        Node* create_BSTree(int arr[], int length);
        void delete_node(Node *pFather, Node *pFind, bool is_left);
};

#endif
