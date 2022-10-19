#include <iostream>

using namespace std;

int main() {
    int arr[10] = {9, 2, 3, 5, 7, 8, 6, 4, 10, 1};
    int temp;

    for(int i = 0; i < 9; i++) {
        for(int j = i; j < 10; j++) {
            if(arr[i] > arr[j + 1]) {
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}