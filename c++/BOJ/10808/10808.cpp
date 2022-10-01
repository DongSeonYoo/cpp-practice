#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    int arr[26] = {0};

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 97 && s[i] <= 122) {
            arr[s[i] - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
}