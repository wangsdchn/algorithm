# include "sort.h"

ARRAYSORT::ARRAYSORT(int arr_in[], int length_in){
    length = length_in;
    arr = new int[length];
    for (int i = 0; i < length; i++){
        arr[i] = arr_in[i];
    }
}
ARRAYSORT::~ARRAYSORT(){
    if (arr){
        delete []arr;
    }
}
void ARRAYSORT::swap(int arr[], int i, int j){
	if (arr[i] == arr[j]){
		return ;
	}
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void ARRAYSORT::print(){
    cout << endl;
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void ARRAYSORT::bubble_sort(){
	int i;
	int j;
	bool flag_swap;
	for (i = length - 1; i >= 0; i--){
		flag_swap = false;
		for (j = 0; j <= i; j++){
			if (arr[j] > arr[j+1]){
				swap(arr, j, j + 1);
				flag_swap = true;
			}
		}
		if (!flag_swap){
			return ;
		}
	}
}

void ARRAYSORT::heapify_max(int arr[], int n, int i){
    if(i >= n){
        return ;
    }
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int max = i;
    if(c1 < n && arr[c1] > arr[max]){
        max = c1;
    }
    if(c2 < n && arr[c2] > arr[max]){
        max = c2;
    }
    if(max != i){
        swap(arr, max, i);
        heapify_max(arr, n, max);
    }
}

void ARRAYSORT::heapify_min(int arr[], int n, int i){
    if (i >= n){
        return ;
    }
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int min = i;
    if (c1 < n && arr[c1] < arr[min]){
        min = c1;
    }
    if (c2 < n && arr[c2] < arr[min]){
        min = c2;
    }
    if (min != i){
        swap(arr, min, i);
        heapify_min(arr, n, min);
    }
}

void ARRAYSORT::build_heap(int arr[], int n, bool reverse){
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
    int i;
    for(i = parent; i >= 0; i--){
        if (reverse)
            heapify_max(arr, n, i);
        else
            heapify_min(arr, n, i);
    }
}

void ARRAYSORT::heap_sort(bool reverse){
    build_heap(arr, length, reverse);
    int last_node = length - 1;
    int i;
    for (i = last_node; i > 0; i--){
        swap(arr, 0, i);
        if (reverse)
            heapify_max(arr, i, 0);
        else
            heapify_min(arr, i, 0);
    }
}

void ARRAYSORT::merge_array(int arr[], int left, int mid, int right, int *temp_arr){
	int i = left;
	int j = mid + 1; 
	int m = left;
	while (i <= mid && j <= right){
		if (arr[i] < arr[j]){
			temp_arr[m] = arr[i];
			i++;
			m++;
		}
		else{
			temp_arr[m] = arr[j];
			j++;
			m++;
		}
	}
	while (i <= mid){
		temp_arr[m] = arr[i];
		i++;
		m++;
	}
	while (j <= right){
		temp_arr[m] = arr[j];
		j++;
		m++;
	}
	for (int i = left; i <= right; i++){
		arr[i] = temp_arr[i];
	}
}

void ARRAYSORT::begin_merge_sort(int arr[], int left, int right, int *temp_arr){
	if (left == right){
		return ;
	}
    int mid = left + (right - left) / 2;
	begin_merge_sort(arr, left, mid, temp_arr);
	begin_merge_sort(arr, mid + 1, right, temp_arr);
	merge_array(arr, left, mid, right, temp_arr);
}

void ARRAYSORT::merge_sort(){
	int temp_arr[length];
	begin_merge_sort(arr, 0, length - 1, temp_arr);
}

void ARRAYSORT::select_sort(){
	int i;
	int j;
	int min_index;
	for (i = 0; i < length - 1; i++){
		min_index = i;
		for (j = i + 1; j < length; j++){
			if (arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		if (i != min_index){
			swap(arr, i, min_index);
		}
	}
}

int ARRAYSORT::partition_equal(int arr[], int key, int left, int right, int &l_len, int &r_len){
	int i = left;
	int j = right;
	l_len = 0;
	r_len = 0;
	// int temp = arr[key];
	while (i < j){ 
		while (j > i && arr[j] >= arr[key]){
			if (arr[j] == arr[key]){
				swap(arr, right - r_len, j);
				r_len++;
			}
			j--;
		}
		while (i < j && arr[i] <= arr[key]){
			if (arr[i] == arr[key]){
				swap(arr, left + l_len, i);
				l_len++;
			}
			i++;
		}
		if (i < j){
			swap(arr, i, j);
		}
	}
	// swap(arr, i, key);
	int stop_pos = i;
	for (int l = 0; l < l_len; l++){
		swap(arr, left + l, stop_pos - l); 
	}
	for (int r = 0; r < r_len; r++){
		swap(arr, right - r, stop_pos + 1 + r); 
	}
	return stop_pos;
}

int ARRAYSORT::partition(int arr[], int key, int left, int right){
	int i = left;
	int j = right;
	while (i < j){ 
		while (j > i && arr[j] >= arr[key]){
			j--;
		}
		while (i < j && arr[i] <= arr[key]){
			i++;
		}
		if (i < j){
			swap(arr, i, j);
		}
	}
	swap(arr, i, key);
	return i;
}
int ARRAYSORT::select_key(int arr[], int left, int right, int mode){
	int key = left;
	if (mode == 0){
		key = left;
	}
	else if (mode == 1){
		srand(time(NULL));
		key = (rand() % (right - left)) + left;
		swap(arr, key, left);
		key = left;
	}
	else if (mode == 2){
		int mid = left + ((right - left) >> 1);
		int mid_index = left;
		if (arr[mid] > arr[left]){
			swap(arr, mid, left);
		}
		if (arr[left] > arr[right]){
			swap(arr, left, right);
		}
		if (arr[mid] > arr[left]){
			swap(arr, mid, left);
		}
		key = left;
	}
	return key;
}
void ARRAYSORT::quick_sort_part(int arr[], int left, int right, int mode){
	if (left >= right){
		return ;
	}
	int key = select_key(arr, left, right, mode);
	if (mode == 3){
		int pos_split;
		pos_split = partition(arr, key, left, right);
		quick_sort_part(arr, left, pos_split, mode);
		quick_sort_part(arr, pos_split+1, right, mode);
	}
	else{
		int l_len, r_len;
		int split_pos;
		split_pos = partition_equal(arr, key, left, right, l_len, r_len);
		quick_sort_part(arr, left, split_pos - l_len, mode);
		quick_sort_part(arr, split_pos + 1 + r_len, right, mode);
	}
}
void ARRAYSORT::quick_sort(int mode){
    quick_sort_part(arr, 0, length, mode);
}

void ARRAYSORT::insert_sort(){
	int i;
	int j;
	for (i = 1; i < length; i++){
		int tmp = arr[i];
		for (j = i - 1; j >= 0; j--){
			if (arr[j] > tmp){
				arr[j + 1] = arr[j];
			}
			else{
				arr[j] = tmp;
				break;
			}
		}
	}
}
