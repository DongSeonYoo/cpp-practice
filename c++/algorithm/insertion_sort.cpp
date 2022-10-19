#include <iostream>

using namespace std;

int main() {

    int array[10] = {1, 3, 5, 2, 4, 8, 6, 10, 9, 7};
    int i, j, temp;

    for(i = 0; i < 10; i++) {
        j = i;
        while(array[j] < array[j + 1] && j >= 0) {
            temp = array[j + 1];
            array[j + 1] = array[j];
            array[j] = temp;
            j--;
        }
    }

    for(i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
}