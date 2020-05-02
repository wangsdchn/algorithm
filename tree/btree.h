#ifndef _BTREE_H
#define _BTREE_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node
{
	int value;
	struct Node *lchild;
	struct Node *rchild;
	Node(int data):value(data),lchild(NULL),rchild(NULL){}
}Node;

class BTree{
	private:
		Node* create_tree(int arr[], int length);
		int calc_height_rescu(Node* pNode);
		void print_tree_preorder_recursive_partition(Node* pRoot);
		void print_tree_inorder_recursive_partition(Node* pRoot);
		void print_tree_postorder_recursive_partition(Node* pRoot);
		int find_root_index(int in[], int in_l, int in_r, int root_value);
		Node* restore_tree_partition(int pre[], int pre_l, int pre_r, int in[], int in_l, int in_r);
		Node* restore_tree(int pre[], int in[], int length);

	public:
		Node* create_node(int value);
		void free_node(Node* node);
		Node* pRoot = NULL;
		BTree();
		BTree(int arr[], int length);
		BTree(int pre[], int in[], int length);
		~BTree();
		void invert_tree();
		int calc_height();
		// tree print
		void print_tree_preorder();
		void print_tree_inorder();
		void print_tree_postorder();
		void print_tree_preorder_recursive();
		void print_tree_inorder_recursive();
		void print_tree_postorder_recursive();
		void print_tree_from_top_to_bottom();
		void print_tree_from_top_to_bottom_cycle();

};

#endif
