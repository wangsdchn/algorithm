#include "btree.h"

Node* BTree::create_node(int value){
	Node *new_node = new Node(value);
	return new_node;
}
void BTree::free_node(Node* pNode){
	if (pNode){
		delete pNode;
		pNode = NULL;
	}
}

BTree::BTree(){
	cout << "Defalut BTree construct" << endl;
};

BTree::BTree(int arr[], int length){
	pRoot = create_tree(arr, length);
};

BTree::BTree(int pre[],int in[], int length){
	pRoot = restore_tree(pre, in, length);
};

BTree::~BTree(){
	cout << "Defalut BTree reconstruct" << endl;
};

int BTree::find_root_index(int in[], int in_l, int in_r, int root_value){
	int root_index = -1;
	for (int i = in_l;i <= in_r;i++){
		if (in[i]==root_value){
			root_index = i;
			return root_index;
		}
	}
	return root_index;
}

Node* BTree::restore_tree_partition(int pre[], int pre_l, int pre_r, int in[], int in_l, int in_r){
	if (pre_r - pre_l != in_r - in_l){
		cout << "Invalid Pre and In" << endl;
		return NULL;
	}
	if (pre_r < pre_l){
		return NULL;
	}
	if (in_r < in_l){
		return NULL;
	}
	int length_left;
	int length_right;
	int root_value = pre[pre_l];
	Node* pRoot = create_node(root_value);
	int root_index = find_root_index(in, in_l, in_r, root_value);
	if (root_index == -1){
		cout << "Invalid Pre and In" << endl;
		return NULL;
	}
	length_left = root_index - in_l;
	length_right = in_r - root_index;
	if (length_left > 0){
		pRoot->lchild = restore_tree_partition(pre, pre_l + 1, pre_l + length_left, in, in_l, in_l + length_left - 1);
	}
	if (length_right > 0){
		pRoot->rchild = restore_tree_partition(pre, pre_r - length_right + 1, pre_r, in, in_r - length_right + 1, in_r);
	}
	return pRoot;
}

Node* BTree::restore_tree(int pre[], int in[], int length){
	Node* pRoot = restore_tree_partition(pre, 0, length - 1, in, 0, length - 1);
	return pRoot;
}

Node* BTree::create_tree(int arr[], int length){
	if (length <= 0){
		return NULL;
	}
	Node *phead = create_node(arr[0]);
	queue<Node *> q_node;
	q_node.push(phead);
	int i = 1;
	while (i < length){
		Node *temp = q_node.front();
		q_node.pop();
		temp->lchild = create_node(arr[i]);
		q_node.push(temp->lchild);
		temp->rchild = create_node(arr[i + 1]);
		q_node.push(temp->rchild);
		i += 2;
	}
	while (!q_node.empty()){
		q_node.pop();
	}
	return phead;
}
int BTree::calc_height_rescu(Node* pNode){
	if (pNode == NULL){
		return 0;
	}
	int left = calc_height_rescu(pNode->lchild);
	int right = calc_height_rescu(pNode->rchild);
	return left > right ? left + 1 : right + 1;
}
int BTree::calc_height(){
	return calc_height_rescu(pRoot);
}

void BTree::invert_tree(){
	if (pRoot == NULL){
		return ;
	}
	stack<Node *> node_stack;
	node_stack.push(pRoot);
	while (!node_stack.empty()){
		Node* pRoot = node_stack.top();
		node_stack.pop();
		Node* lchild = pRoot->lchild;
		pRoot->lchild = pRoot->rchild;
		pRoot->rchild = lchild;
		if (pRoot->lchild){
			node_stack.push(pRoot->lchild);
		}
		if (pRoot->rchild){
			node_stack.push(pRoot->rchild);
		}
	}
}

void BTree::print_tree_from_top_to_bottom(){
	if (pRoot == NULL){
		return ;
	}
	queue<Node *> node_queue;
	node_queue.push(pRoot);
	Node *temp;
	while (!node_queue.empty()){
		temp = node_queue.front();
		node_queue.pop();
		cout << temp->value << " ";
		if (temp->lchild != NULL){
			node_queue.push(temp->lchild);
		}
		if (temp->rchild != NULL){
			node_queue.push(temp->rchild);
		}
	}
	cout << endl;
}

void BTree::print_tree_from_top_to_bottom_cycle(){
	if (pRoot == NULL){
		return ;
	}
	stack<Node *> node_stack[2];
	node_stack[0].push(pRoot);
	Node *temp;
	int layer = 0;
	while (!node_stack[0].empty() || !node_stack[1].empty()){
		// cout << node_stack[0].empty() << node_stack[1].empty() << endl;
		int layer_0_1 = layer & 1;
		temp = node_stack[layer_0_1].top();
		node_stack[layer_0_1].pop();
		cout << temp->value << " ";
		// cout << layer << " " << layer_0_1 << endl;
		if (layer_0_1 == 0){
			if (temp->rchild != NULL){
				node_stack[1].push(temp->rchild);
			}
			if (temp->lchild != NULL){
				node_stack[1].push(temp->lchild);
			}
		}
		else{
			if (temp->lchild != NULL){
				node_stack[0].push(temp->lchild);
			}
			if (temp->rchild != NULL){
				node_stack[0].push(temp->rchild);
			}
		}
		if (node_stack[layer_0_1].empty()){
			layer++;
		}
	}
}

void BTree::print_tree_preorder(){
	if(pRoot == NULL){
		return ;
	}
	stack<Node *> node_stack;
	Node * temp_node = pRoot;
	while (temp_node || !node_stack.empty()){
		if (temp_node){
			cout << temp_node->value << " ";
			node_stack.push(temp_node);
			temp_node = temp_node->lchild;
		}
		else{
			temp_node = node_stack.top();
			node_stack.pop();
			temp_node = temp_node->rchild;
		}
	}
}

void BTree::print_tree_inorder(){
	if(pRoot == NULL){
		return ;
	}
	stack<Node *> node_stack;
	Node * temp_node = pRoot;
	while (temp_node || !node_stack.empty()){
		if (temp_node){
			node_stack.push(temp_node);
			temp_node = temp_node->lchild;
		}
		else{
			temp_node = node_stack.top();
			node_stack.pop();
			cout << temp_node->value << " ";
			temp_node = temp_node->rchild;
		}
	}
}


void BTree::print_tree_postorder(){
	if(pRoot == NULL){
		return ;
	}
	stack<Node *> node_stack;
	Node * temp_node = pRoot;
	Node *pre = NULL;
	while (temp_node || !node_stack.empty()){
		if (temp_node){
			node_stack.push(temp_node);
			temp_node = temp_node->lchild;
		}
		else{
			temp_node = node_stack.top();
			if (temp_node->rchild && temp_node->rchild != pre){
				temp_node = temp_node->rchild;
			}
			else {
				cout << temp_node->value << " ";
				node_stack.pop();
				pre = temp_node;
				temp_node = NULL;
			}
		}
	}
}

void BTree::print_tree_preorder_recursive_partition(Node *pRoot){
	if(pRoot){
		cout << pRoot->value << " ";
		print_tree_preorder_recursive_partition(pRoot->lchild);
		print_tree_preorder_recursive_partition(pRoot->rchild);
	}
}
void BTree::print_tree_preorder_recursive(){
	print_tree_preorder_recursive_partition(pRoot);
}

void BTree::print_tree_inorder_recursive_partition(Node *pRoot){
	if(pRoot){
		print_tree_inorder_recursive_partition(pRoot->lchild);
		cout << pRoot->value << " ";
		print_tree_inorder_recursive_partition(pRoot->rchild);
	}
}

void BTree::print_tree_inorder_recursive(){
	print_tree_inorder_recursive_partition(pRoot);
}

void BTree::print_tree_postorder_recursive_partition(Node *pRoot){
	if(pRoot){
		print_tree_postorder_recursive_partition(pRoot->lchild);
		print_tree_postorder_recursive_partition(pRoot->rchild);
		cout << pRoot->value << " ";
	}
}

void BTree::print_tree_postorder_recursive(){
	print_tree_postorder_recursive_partition(pRoot);
}
