#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {

    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main() {

    int n;
    int age;
    string name;

    vector<pair<int, string>> v;

    cin >> n;

    for(int i = 0; i < n; i++) {

        cin >> age >> name;

        v.push_back(make_pair(age, name));
    }

    sort(v.begin(), v.end(), comp);

    for(auto a : v) {
        cout << a.first << " " << a.second << '\n';
    }
}