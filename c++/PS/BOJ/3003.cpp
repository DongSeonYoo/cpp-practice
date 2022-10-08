#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int king;
    int queen;
    int rook;
    int bisop;
    int knight;
    int phon;

    cin >> king >> queen >> rook >> bisop >> knight >> phon;

    cout << 1 - king << " " << 1 - queen << " " << 2 - rook << " " << 2 - bisop << " " << 2 - knight << " " << 8 - phon;
}