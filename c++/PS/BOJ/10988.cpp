#include <bits/stdc++.h>

using namespace std;

// # solve : reverse함수를 이용한 풀이

int main() {

    string before;
    string input;

    cin >> input;
    before = input;


    reverse(input.begin(), input.end());

    if(before == input) {
        cout << "1" << '\n';
    }
    else {
        cout << "0" << '\n';
    }
}