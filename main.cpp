#include <iostream>
#include <time.h>
#include "sort/sort.h"
#include "tree/btree.h"
#include "tree/bstree.h"
#include "tree/avltree.h"
using namespace std;
/*
void test_tree(int argc, const char *argv[]){
	const int length = 9;
    int arr[length] = {3, 4, 2, 8, 5, 7, 1, 8, 10};
	Node *tree;
	tree = create_tree(arr, length);
	cout << endl << "preorder_res" << endl;
	print_tree_preorder_recursive(tree);
	cout << endl << "inorder_res" << endl;
	print_tree_inorder_recursive(tree);
	cout << endl << "postorder_res" << endl;
	print_tree_postorder_recursive(tree);
	cout << endl << "preorder" << endl;
	print_tree_preorder(tree);
	cout << endl << "inorder" << endl;
	print_tree_inorder(tree);
	cout << endl << "postorder" << endl;
	print_tree_postorder(tree);
	cout << endl << "top to bottom" << endl;
	print_tree_from_top_to_bottom(tree);
	cout << endl << "top to bottom cycle" << endl;
	print_tree_from_top_to_bottom_cycle(tree);
	cout << endl << "invert tree" << endl;
	Node *tree_invert = invert_tree(tree);
	print_tree_from_top_to_bottom(tree_invert);
}

void test_sort(int argc, const char *argv[]){
	int length = atoi(argv[1]);
	int quick_sort_mode = atoi(argv[2]);
	const char *phase = argv[3];
    // int arr[] = {3, 4, 2, 8, 5, 7, 1, 10};
	int arr[length];
	srand(time(NULL));
	for (int j = 0; j<length; j++){
		arr[j] = rand()%length;
		// arr[j] = 10;
		// arr[j] = j;
	}
	cout<<"generate done"<<endl;
	clock_t start_time = clock();
    quick_sort(arr, 0, length - 1, quick_sort_mode);
	// heap_sort(arr, length, false);
	// insert_sort(arr, length);
	// bubble_sort(arr, length);
	// select_sort(arr, length);
	// merge_sort(arr, length);
	clock_t end_time = clock();
	cout<<"Sort time: "<<(float)(end_time-start_time)*1000/CLOCKS_PER_SEC<<"ms"<<endl;
	if (argc == 4){
		if (0 == strcmp(phase, "test")){
			for (int i = 0; i < length; i++){
				cout<<arr[i]<<endl;
			}
		}
	}
	
}
*/
void test_restore_tree(){
	int length = 9;
	// 不能有重复数字
	int pre[] = {3,4,8,6,10,5,2,7,1};
	int in[] = {6,8,10,4,5,3,7,2,1};
	BTree btree(pre, in, length);
	cout << "begin print" << endl;
	btree.print_tree_postorder();
	cout << "end print" << endl;
}
void test_calc_height(){
	const int LENGTH = 9;
	int arr[LENGTH] = {3,4,8,6,10,5,2,7,1};
	BTree btree(arr, LENGTH);
	int height = btree.calc_height();
	cout << "Height of tree: " << height << endl;
}

void test_array(){
	const int LENGTH = 8;
	int arr[] = {5, 4, 2, 8, 3, 7, 1, 10};
	ARRAYSORT array = ARRAYSORT(arr, LENGTH);
	array.print();
}

void test_bstree(){
	const int LENGTH = 4;
	// int arr[LENGTH] = {5, 4, 2, 8, 3, 7, 1, 10};
	int arr[LENGTH] = {5, 4, 2, 3};
	// int arr[LENGTH] = {5, 6, 7, 8};
	BSTree bstree(arr, LENGTH);
	bstree.delete_node(5);
	bstree.print_tree_from_top_to_bottom();
	bool is_exist = bstree.find_node(6);
	bstree.insert_node(6);
	bstree.print_tree_from_top_to_bottom();
	bool is_exist_1 = bstree.find_node(6);
	bstree.delete_node(5);
	bstree.print_tree_from_top_to_bottom();
	bool is_exist_2 = bstree.find_node(6);
	cout << is_exist << " " << is_exist_1 << " " << is_exist_2 << endl;
}

int main(int argc, const char * argv[]) {
	// test_sort(argc, argv);
	// test_tree(argc, argv);
	// test_array();
	// test_restore_tree();
	// test_calc_height();
	test_bstree();
    return 0;
}
