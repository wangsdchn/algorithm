#include "avltree.h"

int AVLTree::height(){
    return pRoot->height;
}

AVLNode* AVLTree::create_avl_node(int value){
    AVLNode* new_node = new AVLNode(value);
    return new_node;
}

int AVLTree::get_height(AVLNode *node){
    return node->height;
}
void AVLTree::update_height(AVLNode *node){
    node->height = max(get_height(node->rchild), get_height(node->lchild)) + 1;
}

int AVLTree::get_balance_level(AVLNode *node){
    return node->lchild->height - node->rchild->height;
}

AVLNode* AVLTree::ll_rotate(AVLNode *node){
    AVLNode *lchild = node->lchild;
    node->lchild = lchild->rchild;
    lchild->rchild = node;
    update_height(node);
    update_height(lchild);
    return lchild;
}
AVLNode* AVLTree::rr_rotate(AVLNode *node){
    AVLNode *rchild = node->rchild;
    node->rchild = rchild->lchild;
    rchild->lchild = node;
    update_height(node);
    update_height(rchild);
    return rchild;
}
AVLNode* AVLTree::lr_rotate(AVLNode *node){
    node->lchild = ll_rotate(node->lchild);
    return rr_rotate(node);
}
AVLNode* AVLTree::rl_rotate(AVLNode *node){
    node->rchild = ll_rotate(node->rchild);
    return rr_rotate(node);
}

AVLNode* AVLTree::re_balance(AVLNode *node){
    int balance_level = get_balance_level(node);
    if (balance_level <= 1 and balance_level >= -1){
        return node;
    }
    // LL
    else if(balance_level > 1 and get_balance_level(node->lchild)>0){
        node = ll_rotate(node);
    }
    // LR
    else if(balance_level > 1 and get_balance_level(node->lchild)<0){
        node = lr_rotate(node);
    }
    // RR
    else if(balance_level < -1 and get_balance_level(node->rchild)<0){
        node = rr_rotate(node);
    }
    // RL
    else if(balance_level < -1 and get_balance_level(node->rchild)>0){
        node = rl_rotate(node);
    }
}

void AVLTree::insert_node(int value){
    pRoot = insert_node_op(pRoot, value);
}

AVLNode* AVLTree::insert_node_op(AVLNode *node, int value){
    if (node == NULL){
        node = create_avl_node(value);
    }
    else if (value < node->value){
        node->lchild = insert_node_op(node->lchild, value);
    }
    else if (value > node->value){
        node->rchild = insert_node_op(node->rchild, value);
    }
    re_balance(node);
    return node;
}
