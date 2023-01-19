#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> v;
    int num;
    int sum = 0;
    int count = 0;

    for(int i = 0; i < 5; i++) {

        cin >> num;
        v.push_back(num);
        sum += num;
        count++;
    }

    sort(v.begin(), v.end());

    cout << sum / count << '\n';
    cout << v[v.size() / count + 1] << '\n';
}