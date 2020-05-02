#ifndef _AVLTREE_H
#define _AVLTREE_H
#include <iostream>
#include "bstree.h"

typedef struct AVLNode
{
    int value;
    AVLNode *lchild = NULL;
    AVLNode *rchild = NULL;
    int height = 0;
    AVLNode(int value):value(value), height(0), lchild(NULL), rchild(NULL){};
}AVLNode;

class AVLTree:public BSTree{
    private:
        AVLNode *pRoot;
        AVLNode* create_avl_node(int value);
        void update_height(AVLNode *node);
        int get_height(AVLNode *node);
        int get_balance_level(AVLNode *node);
        AVLNode* re_balance(AVLNode *node);
        AVLNode* ll_rotate(AVLNode *node);
        AVLNode* rr_rotate(AVLNode *node);
        AVLNode* lr_rotate(AVLNode *node);
        AVLNode* rl_rotate(AVLNode *node);
        AVLNode* insert_node_op(AVLNode *node, int value);
        AVLNode* delete_node_op(AVLNode *node, int value);
    public:
        int height();
        void insert_node(int value);
        void delete_node(int value);
};

#endif