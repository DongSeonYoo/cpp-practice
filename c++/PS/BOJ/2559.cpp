#include <bits/stdc++.h>

using namespace std;

int psum[100001];

int main() {

    int N, M;
    int num;
    int t = -10000001;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> num;

        psum[i] = psum[i - 1] + num;
    }

    for(int i = M; i <= N; i++) {
        t = max(t, psum[i] - psum[i - M]);
    }

    cout << t << '\n';
}