#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    string name;
    int cnt[27] = {0,};
    vector<char> v;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> name;

        cnt[name[0] - 'a']++;
    }

    for(int i = 0; i < 27; i++) {
        if(cnt[i] >= 5) {
            v.push_back('a' + i);
        }
    }

    if(!v.empty()) {
        for(auto a : v) {
            cout << a;
        }
    }
    else {
        cout << "PREDAJA";
    }
}