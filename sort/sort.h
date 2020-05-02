#ifndef _SORT_H
#define _SORT_H

#include <iostream>
using namespace std;

class ARRAYSORT{
    private:
        int length;
        int *arr;
        void swap(int arr[], int i, int j);
        void heapify_max(int arr[], int i, int j);
        void heapify_min(int arr[], int i, int j);
        void build_heap(int arr[], int length, bool reverse);
        void begin_merge_sort(int arr[], int left, int right, int *temp_arr);
        void merge_array(int arr[], int left, int mid, int right, int *temp_arr);

        int partition_equal(int arr[], int key, int left, int right, int &l_len, int &r_len);
        int partition(int arr[], int key, int left, int right);
        int select_key(int arr[], int left, int right, int mode);
        void quick_sort_part(int arr[], int left, int right, int mode);
        
    public:
        ARRAYSORT(int arr[], int length);
        ~ARRAYSORT();
        void bubble_sort();
        void insert_sort();
        void select_sort();
        void heap_sort(bool reverse);
        void merge_sort();
        void quick_sort(int mode = 0);

        void print();
};

#endif
