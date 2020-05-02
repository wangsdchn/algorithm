#include "bstree.h"

BSTree::BSTree(){
    cout << "Defalut BSTree construct" << endl;
}

BSTree::BSTree(int arr_in[], int length_in){
    create_BSTree(arr_in, length_in);
}

BSTree::~BSTree(){
    cout << "Defalut BSTree reconstruct" << endl;
}

void BSTree::insert_node(int value){
    if (pRoot == NULL){
        pRoot = create_node(value);
        return ;
    }
    Node* pTemp = pRoot;
    while (pTemp!=NULL){
        if (value > pTemp->value){
            if (pTemp->rchild){
                pTemp = pTemp->rchild;
            }
            else{
                pTemp->rchild = create_node(value);
                break;
            }
        }
        else if(value < pTemp->value){
            if (pTemp->lchild){
                pTemp = pTemp->lchild;
            }
            else{
                pTemp->lchild = create_node(value);
                break;
            }
        }
        else{
            return ;
        }
    }
}
Node* BSTree::create_BSTree(int arr[], int length){
    if (length <= 0){
        return NULL;
    }
    for (int i = 0; i < length; i++){
        insert_node(arr[i]);
    }
};

void BSTree::delete_node(Node *pFather, Node *pFind, bool is_left){
    if (pFind==NULL){
        return ;
    }
    
    if (pFind->lchild==NULL){
        if (pFather == NULL){
            pRoot = pFind->rchild;
        }
        else if (is_left){
            pFather->lchild = pFind->rchild;
        }
        else{
            pFather->rchild = pFind->rchild;
        }
        free_node(pFind);
    }
    else if (pFind->rchild==NULL){
        if (pFather == NULL){
            pRoot = pFind->lchild;
        }
        else if (is_left){
            pFather->lchild = pFind->lchild;
        }
        else{
            pFather->rchild = pFind->lchild;
        }
        free_node(pFind);
    }
    else{
        Node *rchild = pFind->rchild;
        pFather = pFind;
        while (rchild){
            if (rchild->lchild != NULL){
                is_left = true;
                pFather = rchild;
                rchild = rchild->lchild;
            }
            else{
                break;
            }
        }
        pFind->value = rchild->value;
        delete_node(pFather, rchild, is_left);
    }
}

void BSTree::delete_node(int value){
    if (pRoot == NULL){
        return ;
    }
    Node* pFind = pRoot;
    Node* pFather = NULL;
    bool is_left = false;
    while (pFind){
        if (value > pFind->value){
            is_left = false;
            pFather = pFind;
            pFind = pFind->rchild;
        }
        else if (value < pFind->value){
            is_left = true;
            pFather = pFind;
            pFind = pFind->lchild;
        }
        else{
            break;
        }
    }
    delete_node(pFather, pFind, is_left);
}

bool BSTree::find_node(int value){
    bool result = false;
    Node* temp = pRoot;
    while (temp){
        if (value > temp->value){
            temp = temp->rchild;
        }
        else if (value < temp->value){
            temp = temp->lchild;
        }
        else{
            result = true;
            break;
        }
    }
    return result;
}