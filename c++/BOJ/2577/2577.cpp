#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int a, b, c;
    int result; 
    int count = 0;
    int arr[10] = {0};

    cin >> a >> b >> c;

    result = a * b * c;
    // A × B × C = 150 × 266 × 427 = 17037300
    //result = 17037300

    while(result != 0) {
        arr[result % 10]++;
        result /= 10;
    }

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
}