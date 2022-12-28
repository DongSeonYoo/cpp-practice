#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    string pattern;

    string pre;
    string sub;

    int position = 0;

    cin >> N;

    cin >> pattern;

    position = pattern.find('*');
    pre = pattern.substr(0, position);
    sub = pattern.substr(position + 1);

    string name;

    for(int i = 0; i < N; i++) {
        cin >> name;

        if(pre.size() + sub.size() > name.size()) {
            cout << "NE" << '\n';
        }
        else {
            
            if(name.substr(0, pre.size()) == pre && name.substr(name.size() - sub.size()) == sub) {
                cout << "DA" << '\n';
            } else {
                cout << "NE" << '\n';
            }
        }
    }
}