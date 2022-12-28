#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int before, after;

int cnt[101];
int sum;

int main() {

    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++) {
        cin >> before >> after;

        for(int j = before; j < after; j++) {
            cnt[j]++;
        }
    }

    for(int i = 0; i < 100; i++) {
        if(cnt[i]) {

            if(cnt[i] == 1) {
                sum += A * 1;
            }

            else if(cnt[i] == 2) {
                sum += B * 2;
            }

            else if(cnt[i] == 3) {
                sum += C * 3;
            }
        }
    }

    cout << sum << '\n';
}