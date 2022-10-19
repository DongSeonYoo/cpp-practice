#include <iostream>

using namespace std;

int sorted_array[8];

void merge(int *array, int start, int end) {
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    int sorted_array_idx = start;

    while(left <= mid && right <= end) {
        if(array[left] <= array[right]) {
            sorted_array[sorted_array_idx] = array[left];
            left++;
        }
        else {
            sorted_array[sorted_array_idx] = array[right];
            right++;
        }
        sorted_array_idx++;
    }

    if(left > mid) {
        for(int idx = right; idx <= end; idx++) {
            sorted_array[sorted_array_idx] = array[idx];
            sorted_array_idx++;
        }
    }
    else {
        for(int idx = left; idx <= mid; idx++) {
            sorted_array[sorted_array_idx] = array[idx];
            sorted_array_idx++;
        }
    }

    for(int i = start; i <= end; i++) {
        array[i] = sorted_array[i];
    }
}

void partition(int *array, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        partition(array, start, mid);
        partition(array, mid + 1, end);
        merge(array, start, end);
    }
}

int main() {
    int array[8] = {3, 6, 2, 7, 1, 2, 4, 8};

    partition(array, 0, 7);

    for(int i = 0; i < 8; i++) {
        cout << array[i] << " ";
    }
}