#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;

    getline(cin, str);

    for(int i = 0; i < str.size(); i++) {

        if(str[i] >= 'A' && str[i] <= 'Z' && str[i]) {
            if(str[i] + 13 > 'Z') {
                str[i] = 'A' + 13 - (90 - str[i]) - 1;

            } else {
                str[i] += 13;
            }
        }
        
        else if(str[i] >= 'a' && str[i] <= 'z') {
            if(str[i] + 13 > 'z') {
                str[i] = 'a' + 13 - (122 - str[i]) - 1;

            } else {
                str[i] += 13;
            }
        }

        cout << str[i];
    }

    cout << '\n';
}