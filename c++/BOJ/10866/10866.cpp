#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    deque<int> d;
    int num;
    string input;

    cin >> num;

    while(num != 0) {

        cin >> input;

        if(input == "push_front") {
            int n;
            cin >> n;
            d.push_front(n);
        }
        
        else if(input == "push_back") {
            int n;
            cin >> n;
            d.push_back(n);
        }

        else if(input == "pop_front") {
            if(!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else {
                cout << -1 << '\n';
            }
        }

        else if(input == "pop_back") {
            if(!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else {
                cout << -1 << '\n';
            }
        }

        else if(input == "size") {
            cout << d.size() << '\n';
        }

        else if(input == "empty") {
            if(d.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }

        else if(input == "front") {
            if(d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
            }
        }
        
        else if(input == "back") {
            if(d.empty()) {
                cout << -1 << '\n';
            }
            
            else {
                cout << d.back() << '\n';
            }
        }
        num--;
    }
}